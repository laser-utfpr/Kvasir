#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //shared_parameters.loadSettingsFromFile();

    ui->setupUi(this);

    ui->command_menu->setMenu(&command_menu);
    command_menu_action = nullptr;
    n_command_actions = 0;
    connect(&command_menu, SIGNAL(aboutToShow()), this, SLOT(makeCommandMenu()));
    connect(&command_menu, SIGNAL(triggered(QAction*)), this, SLOT(changeCommand(QAction*)));

    force_stop = false;

    ui->ally_center_menu->setMenu(&ally_center_menu);
    ui->enemy_center_menu->setMenu(&enemy_center_menu);
    ui->available_tag_menu->setMenu(&available_tag_menu);
    ui->current_tag_menu->setMenu(&current_tag_menu);

    const char *color_name[] = COLOR_MEMBER_NAMES;
    Color init;
    if((init = shared_parameters.getAllyCenter()) != UNCOLORED)
        ui->ally_center_menu->setText(color_name[static_cast<int>(init)]);
    if((init = shared_parameters.getEnemyCenter()) != UNCOLORED)
        ui->enemy_center_menu->setText(color_name[static_cast<int>(init)]);

    QString qstr;
    for(int i=0; i<N_COLORS; i++)
    {
        qstr = color_name[i];
        ally_color_action[i] = new QAction(qstr,this);
        enemy_color_action[i] = new QAction(qstr,this);
        tag_color_action[i] = new QAction(qstr,this);
        ally_center_menu.addAction(ally_color_action[i]);
        enemy_center_menu.addAction(enemy_color_action[i]);
        if(shared_parameters.isTagColor(static_cast<Color>(i)))
            current_tag_menu.addAction(tag_color_action[i]);
        else
            available_tag_menu.addAction(tag_color_action[i]);
    }
    connect(&ally_center_menu, SIGNAL(triggered(QAction*)), this, SLOT(changeAllyCenter(QAction*)));
    connect(&enemy_center_menu, SIGNAL(triggered(QAction*)), this, SLOT(changeEnemyCenter(QAction*)));
    connect(&available_tag_menu, SIGNAL(triggered(QAction*)), this, SLOT(addTagColor(QAction*)));
    connect(&current_tag_menu, SIGNAL(triggered(QAction*)), this, SLOT(removeTagColor(QAction*)));

    Coord sr_ulc = shared_parameters.getSearchedRegionULC();
    Coord sr_lrc = shared_parameters.getSearchedRegionLRC();
    ui->sr_ulc_x->setText(QString::number(sr_ulc.x));
    ui->sr_ulc_y->setText(QString::number(sr_ulc.y));
    ui->sr_lrc_x->setText(QString::number(sr_lrc.x));
    ui->sr_lrc_y->setText(QString::number(sr_lrc.y));

    Coord pf_ulc = shared_parameters.getPlayableFieldULC();
    Coord pf_lrc = shared_parameters.getPlayableFieldLRC();
    ui->pf_ulc_x->setText(QString::number(pf_ulc.x));
    ui->pf_ulc_y->setText(QString::number(pf_ulc.y));
    ui->pf_lrc_x->setText(QString::number(pf_lrc.x));
    ui->pf_lrc_y->setText(QString::number(pf_lrc.y));
    Coord left_goal_ulc = shared_parameters.getLeftGoalULC();
    Coord left_goal_lrc = shared_parameters.getLeftGoalLRC();
    ui->left_goal_ulc_x->setText(QString::number(left_goal_ulc.x));
    ui->left_goal_ulc_y->setText(QString::number(left_goal_ulc.y));
    ui->left_goal_lrc_x->setText(QString::number(left_goal_lrc.x));
    ui->left_goal_lrc_y->setText(QString::number(left_goal_lrc.y));
    Coord right_goal_ulc = shared_parameters.getRightGoalULC();
    Coord right_goal_lrc = shared_parameters.getRightGoalLRC();
    ui->right_goal_ulc_x->setText(QString::number(right_goal_ulc.x));
    ui->right_goal_ulc_y->setText(QString::number(right_goal_ulc.y));
    ui->right_goal_lrc_x->setText(QString::number(right_goal_lrc.x));
    ui->right_goal_lrc_y->setText(QString::number(right_goal_lrc.y));
    Coord left_gka_ulc = shared_parameters.getLeftGKAreaULC();
    Coord left_gka_lrc = shared_parameters.getLeftGKAreaLRC();
    ui->left_gka_ulc_x->setText(QString::number(left_gka_ulc.x));
    ui->left_gka_ulc_y->setText(QString::number(left_gka_ulc.y));
    ui->left_gka_lrc_x->setText(QString::number(left_gka_lrc.x));
    ui->left_gka_lrc_y->setText(QString::number(left_gka_lrc.y));
    Coord right_gka_ulc = shared_parameters.getRightGKAreaULC();
    Coord right_gka_lrc = shared_parameters.getRightGKAreaLRC();
    ui->right_gka_ulc_x->setText(QString::number(right_gka_ulc.x));
    ui->right_gka_ulc_y->setText(QString::number(right_gka_ulc.y));
    ui->right_gka_lrc_x->setText(QString::number(right_gka_lrc.x));
    ui->right_gka_lrc_y->setText(QString::number(right_gka_lrc.y));

    smmc = new SMMCThread(shared_parameters);

    connect(this, SIGNAL(stopSMMC()), smmc, SLOT(stopThread()));

    connect(this, SIGNAL(visionSettingsChanged()), smmc, SLOT(updateVisionOutputSettings()));
    connect(this, SIGNAL(aiSettingsChanged()), smmc, SLOT(updateAIOutputSettings()));
    connect(this, SIGNAL(commSettingsChanged()), smmc, SLOT(updateCommOutputSettings()));

    connect(smmc, SIGNAL(visionInputUpdate()), this, SLOT(handleVisionUpdate()));
    connect(smmc, SIGNAL(aiInputUpdate()), this, SLOT(handleAIUpdate()));
    connect(smmc, SIGNAL(commInputUpdate()), this, SLOT(handleCommUpdate()));

    connect(this, SIGNAL(runVision()), smmc, SLOT(startVision()));
    connect(this, SIGNAL(runAI()), smmc, SLOT(startAI()));
    connect(this, SIGNAL(runComm()), smmc, SLOT(startComm()));

    connect(this, SIGNAL(shutdownVision()), smmc, SLOT(shutdownVision()));
    connect(this, SIGNAL(shutdownAI()), smmc, SLOT(shutdownAI()));
    connect(this, SIGNAL(shutdownComm()), smmc, SLOT(shutdownComm()));

    smmc->start();
    usleep(THREAD_START_WAIT_TIME_US);

    cam.open(0);

    frame_update_timer = new QTimer(this);
    connect(frame_update_timer, SIGNAL(timeout()), this, SLOT(processImages()));
    frame_update_timer->start(FRAME_REFRESH_RATE_MS);
}

MainWindow::~MainWindow()
{
    emit shutdownVision();
    emit shutdownAI();
    emit shutdownComm();
    usleep(MODULES_SHUTDOWN_WAIT_TIME_US);

    emit stopSMMC();
    usleep(THREAD_STOP_WAIT_TIME_US);
    delete smmc;

    if(command_menu_action != nullptr)
    {
        for(int i=0; i<n_command_actions; i++)
        {
            if(command_menu_action[i] != nullptr)
            {
                delete command_menu_action[i];
                command_menu_action[i] = nullptr;
            }
        }
        delete command_menu_action;
        command_menu_action = nullptr;
    }
    for(int i=0; i<N_COLORS; i++)
    {
        delete ally_color_action[i];
        delete enemy_color_action[i];
        delete tag_color_action[i];
    }

    delete ui;
}

void MainWindow::processGameControlImage(void)
{
    //for testing - to be deleted
    cam.read(cam_image);
    if(cam_image.empty())
        return;

    cv::Mat resized_image;
    cv::Size new_size(ui->game_control_image->width(),ui->game_control_image->height());
    cv::resize(cam_image, resized_image, new_size, INTERPOLATION_METHOD);

    if(ui->color_objects_cb->isChecked())
    {
        //draw color objects
    }
    if(ui->robot_positions_cb->isChecked())
    {
        //draw robot positions
    }
    if(ui->player_status_cb->isChecked())
    {
        //draw player status
    }
    if(ui->player_movements_cb->isChecked())
    {
        //draw player movements
    }

    cv::cvtColor(resized_image, resized_image, CV_BGR2RGB);
    QImage qimage((uchar*)resized_image.data, resized_image.cols, resized_image.rows,
                  resized_image.step, QImage::Format_RGB888);

    ui->game_control_image->setPixmap(QPixmap::fromImage(qimage));
}

void MainWindow::processVisionSettingsImage(void)
{

}

void MainWindow::processAISettingsImage(void)
{

}

void MainWindow::processImages(void)
{
    switch(ui->tabWidget->currentIndex())
    {
        case RUN_MODULES_INDEX:
        break;

        case GAME_CONTROL_INDEX:
        processGameControlImage(); break;

        case VISION_SETTINGS_INDEX:
        processVisionSettingsImage(); break;

        case AI_SETTINGS_INDEX:
        processAISettingsImage(); break;

        default:
        break;
    }
}

void MainWindow::on_vision_path_input_textChanged(const QString &arg1)
{
    shared_parameters.setVisionPath(arg1.toStdString());
}

void MainWindow::on_ai_path_input_textChanged(const QString &arg1)
{
    shared_parameters.setAIPath(arg1.toStdString());
}

void MainWindow::on_comm_path_input_textChanged(const QString &arg1)
{
    shared_parameters.setCommPath(arg1.toStdString());
}

void MainWindow::on_run_vision_clicked(void)
{
    emit runVision();
}

void MainWindow::on_run_ai_clicked(void)
{
    emit runAI();
}

void MainWindow::on_run_comm_clicked(void)
{
    emit runComm();
}

void MainWindow::on_shutdown_vision_clicked(void)
{
    emit shutdownVision();
    usleep(MODULES_SHUTDOWN_WAIT_TIME_US);
}

void MainWindow::on_shutdown_ai_clicked(void)
{
    emit shutdownAI();
    usleep(MODULES_SHUTDOWN_WAIT_TIME_US);
}

void MainWindow::on_shutdown_comm_clicked(void)
{
    emit shutdownComm();
    usleep(MODULES_SHUTDOWN_WAIT_TIME_US);
}

void MainWindow::makeCommandMenu(void)
{
    command_menu.clear();
    if(command_menu_action != nullptr)
    {
        for(int i=0; i<n_command_actions; i++)
        {
            if(command_menu_action[i] != nullptr)
            {
                delete command_menu_action[i];
                command_menu_action[i] = nullptr;
            }
        }
        delete command_menu_action;
        command_menu_action = nullptr;
    }

    std::vector<std::string> command_list = shared_parameters.getCommandList();
    n_command_actions = command_list.size();
    command_menu_action = new QAction*[n_command_actions];

    QString qstr;
    for(int i=0; i<n_command_actions; i++)
    {
        qstr = command_list[i].c_str();
        command_menu_action[i] = new QAction(qstr,this);
        command_menu.addAction(command_menu_action[i]);
    }
}

void MainWindow::changeCommand(QAction *action)
{
    ui->command_menu->setText(action->text());
}

void MainWindow::on_send_command_clicked(void)
{
    QString qstr = ui->command_menu->text();
    shared_parameters.sendAICommand(qstr.toStdString());
    //emit signal
}

void MainWindow::on_stop_resume_clicked(void)
{
    if(force_stop == false)
    {
        shared_parameters.setForceStop(true);
        ui->stop_resume->setText("Resume");
        force_stop = true;
    }
    else // if(force_stop == true)
    {
        shared_parameters.setForceStop(true);
        ui->stop_resume->setText("Force Stop");
        force_stop = false;
    }
}

void MainWindow::on_sr_ulc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->sr_ulc_x->foregroundRole(), Qt::black);
        ui->sr_ulc_x->setPalette(black_text);
        shared_parameters.setSearchedRegionULCx(value);
    }
    else
    {
        red_text.setColor(ui->sr_ulc_x->foregroundRole(), Qt::red);
        ui->sr_ulc_x->setPalette(red_text);
    }
}

void MainWindow::on_sr_ulc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->sr_ulc_y->foregroundRole(), Qt::black);
        ui->sr_ulc_y->setPalette(black_text);
        shared_parameters.setSearchedRegionULCy(value);
    }
    else
    {
        red_text.setColor(ui->sr_ulc_y->foregroundRole(), Qt::red);
        ui->sr_ulc_y->setPalette(red_text);
    }
}

void MainWindow::on_sr_lrc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->sr_lrc_x->foregroundRole(), Qt::black);
        ui->sr_lrc_x->setPalette(black_text);
        shared_parameters.setSearchedRegionLRCx(value);
    }
    else
    {
        red_text.setColor(ui->sr_lrc_x->foregroundRole(), Qt::red);
        ui->sr_lrc_x->setPalette(red_text);
    }
}

void MainWindow::on_sr_lrc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->sr_lrc_y->foregroundRole(), Qt::black);
        ui->sr_lrc_y->setPalette(black_text);
        shared_parameters.setSearchedRegionLRCy(value);
    }
    else
    {
        red_text.setColor(ui->sr_lrc_y->foregroundRole(), Qt::red);
        ui->sr_lrc_y->setPalette(red_text);
    }
}

void MainWindow::on_pf_ulc_x_textChanged(const QString &new_text)
{

}

void MainWindow::on_pf_ulc_y_textChanged(const QString &new_text)
{

}

void MainWindow::on_pf_lrc_x_textChanged(const QString &new_text)
{

}

void MainWindow::on_pf_lrc_y_textChanged(const QString &new_text)
{

}

void MainWindow::on_left_goal_ulc_x_textChanged(const QString &new_text)
{

}

void MainWindow::on_left_goal_ulc_y_textChanged(const QString &new_text)
{

}

void MainWindow::on_left_goal_lrc_x_textChanged(const QString &new_text)
{

}

void MainWindow::on_left_goal_lrc_y_textChanged(const QString &new_text)
{

}

void MainWindow::on_right_goal_ulc_x_textChanged(const QString &new_text)
{

}

void MainWindow::on_right_goal_ulc_y_textChanged(const QString &new_text)
{

}

void MainWindow::on_right_goal_lrc_x_textChanged(const QString &new_text)
{

}

void MainWindow::on_right_goal_lrc_y_textChanged(const QString &new_text)
{

}

void MainWindow::on_left_gka_ulc_x_textChanged(const QString &new_text)
{

}

void MainWindow::on_left_gka_ulc_y_textChanged(const QString &new_text)
{

}

void MainWindow::on_left_gka_lrc_x_textChanged(const QString &new_text)
{

}

void MainWindow::on_left_gka_lrc_y_textChanged(const QString &new_text)
{

}

void MainWindow::on_right_gka_ulc_x_textChanged(const QString &new_text)
{

}

void MainWindow::on_right_gka_ulc_y_textChanged(const QString &new_text)
{

}

void MainWindow::on_right_gka_lrc_x_textChanged(const QString &new_text)
{

}

void MainWindow::on_right_gka_lrc_y_textChanged(const QString &new_text)
{

}

void MainWindow::changeAllyCenter(QAction* action)
{
    QString qstr = action->text();
    ui->ally_center_menu->setText(qstr);

    std::string new_center_color = qstr.toStdString();
    const char *color_name[] = COLOR_MEMBER_NAMES;
    Color new_color;
    for(int i=0; i<N_COLORS; i++)
    {
        std::string tested_color = color_name[i];
        if(new_center_color == tested_color)
            new_color = static_cast<Color>(i);
    }
    shared_parameters.setAllyCenter(new_color);
    //emit signal
}

void MainWindow::changeEnemyCenter(QAction* action)
{
    QString qstr = action->text();
    ui->enemy_center_menu->setText(qstr);

    std::string new_center_color = qstr.toStdString();
    const char *color_name[] = COLOR_MEMBER_NAMES;
    Color new_color;
    for(int i=0; i<N_COLORS; i++)
    {
        std::string tested_color = color_name[i];
        if(new_center_color == tested_color)
            new_color = static_cast<Color>(i);
    }
    shared_parameters.setEnemyCenter(new_color);
    //emit signal
}

void MainWindow::addTagColor(QAction *action)
{
    QString qstr = action->text();
    std::string new_tag_color = qstr.toStdString();
    const char *color_name[] = COLOR_MEMBER_NAMES;
    Color new_color;
    for(int i=0; i<N_COLORS; i++)
    {
        std::string tested_color = color_name[i];
        if(new_tag_color == tested_color)
            new_color = static_cast<Color>(i);
    }
    shared_parameters.addTagColor(new_color);

    available_tag_menu.removeAction(action);
    current_tag_menu.addAction(action);

    //emit signal
}

void MainWindow::removeTagColor(QAction *action)
{
    QString qstr = action->text();
    std::string dead_tag_color = qstr.toStdString();
    const char *color_name[] = COLOR_MEMBER_NAMES;
    Color dead_color;
    for(int i=0; i<N_COLORS; i++)
    {
        std::string tested_color = color_name[i];
        if(dead_tag_color == tested_color)
            dead_color = static_cast<Color>(i);
    }
    shared_parameters.addTagColor(dead_color);

    current_tag_menu.removeAction(action);
    available_tag_menu.addAction(action);

    //emit signal
}

void MainWindow::handleVisionUpdate(void)
{

}

void MainWindow::handleAIUpdate(void)
{

}

void MainWindow::handleCommUpdate(void)
{
    //no comm parameters to be handled for now
}

#include "moc_mainwindow.cpp"
