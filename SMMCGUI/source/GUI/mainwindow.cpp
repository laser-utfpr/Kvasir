#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    shared_parameters.loadSettingsFromFile();
    usleep(THREAD_START_WAIT_TIME_US);

    ui->setupUi(this);

    //loading the modules' paths
    QString qstr;
    qstr = (shared_parameters.getVisionPath()).c_str();
    ui->vision_path_input->setText(qstr);
    qstr = (shared_parameters.getAIPath()).c_str();
    ui->ai_path_input->setText(qstr);
    qstr = (shared_parameters.getCommPath()).c_str();
    ui->comm_path_input->setText(qstr);

    //creating the AI command menu and connecting it's signals
    ui->command_menu->setMenu(&command_menu);
    command_menu_action = nullptr;
    n_command_actions = 0;
    connect(&command_menu, SIGNAL(aboutToShow()), this, SLOT(makeCommandMenu()));
    connect(&command_menu, SIGNAL(triggered(QAction*)), this, SLOT(changeCommand(QAction*)));

    force_stop = false;

    //setting the menus' variables to it's buttons
    ui->ball_menu->setMenu(&ball_menu);
    ui->ally_center_menu->setMenu(&ally_center_menu);
    ui->enemy_center_menu->setMenu(&enemy_center_menu);
    ui->available_tag_menu->setMenu(&available_tag_menu);
    ui->current_tag_menu->setMenu(&current_tag_menu);

    //initializing the menus' chosen option
    const char *color_name[] = COLOR_MEMBER_NAMES;
    Color init;
    if((init = shared_parameters.getBallColor()) != UNCOLORED)
        ui->ball_menu->setText(color_name[static_cast<int>(init)]);
    if((init = shared_parameters.getAllyCenter()) != UNCOLORED)
        ui->ally_center_menu->setText(color_name[static_cast<int>(init)]);
    if((init = shared_parameters.getEnemyCenter()) != UNCOLORED)
        ui->enemy_center_menu->setText(color_name[static_cast<int>(init)]);

    //for each color add it's action to the menus that should have it
    for(int i=0; i<N_COLORS; i++)
    {
        //creates the color action with the color name
        qstr = color_name[i];
        ball_color_action[i] = new QAction(qstr,this);
        ally_color_action[i] = new QAction(qstr,this);
        enemy_color_action[i] = new QAction(qstr,this);
        tag_color_action[i] = new QAction(qstr,this);

        //adds the actions to the menus
        ball_menu.addAction(ball_color_action[i]);
        ally_center_menu.addAction(ally_color_action[i]);
        enemy_center_menu.addAction(enemy_color_action[i]);
        if(shared_parameters.isTagColor(static_cast<Color>(i)))
            current_tag_menu.addAction(tag_color_action[i]);
        else
            available_tag_menu.addAction(tag_color_action[i]);
    }
    connect(&ball_menu, SIGNAL(triggered(QAction*)), this, SLOT(changeBallColor(QAction*)));
    connect(&ally_center_menu, SIGNAL(triggered(QAction*)), this, SLOT(changeAllyCenter(QAction*)));
    connect(&enemy_center_menu, SIGNAL(triggered(QAction*)), this, SLOT(changeEnemyCenter(QAction*)));
    connect(&available_tag_menu, SIGNAL(triggered(QAction*)), this, SLOT(addTagColor(QAction*)));
    connect(&current_tag_menu, SIGNAL(triggered(QAction*)), this, SLOT(removeTagColor(QAction*)));

    //itializing the text boxes of the coordinates
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

    std::cout << std::endl << "Creating SMMC thread" << std::endl;
    smmc = new SMMCThread(shared_parameters, static_cast<QObject*>(this));

    //conecting signals and slots of the smmc thread
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

    std::cout << std::endl << "Starting SMMC thread" << std::endl;
    smmc->start();
    usleep(THREAD_START_WAIT_TIME_US);

    emit visionSettingsChanged();
    emit aiSettingsChanged();
    emit commSettingsChanged();

    frame_update_timer = new QTimer(this);
    connect(frame_update_timer, SIGNAL(timeout()), this, SLOT(processImages()));
    frame_update_timer->start(FRAME_REFRESH_RATE_MS);
}

MainWindow::~MainWindow()
{
    //emiting signals to shutdown modules
    emit shutdownVision();
    emit shutdownAI();
    emit shutdownComm();
    usleep(MODULES_SHUTDOWN_WAIT_TIME_US);

    //emiting signals to shutdown smmc thread
    std::cout << std::endl << "Ending SMMC thread" << std::endl;
    emit stopSMMC();
    usleep(THREAD_STOP_WAIT_TIME_US);
    delete smmc;

    //deleting the AI commands' actions
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

    //deleting color actions
    for(int i=0; i<N_COLORS; i++)
    {
        delete ball_color_action[i];
        delete ally_color_action[i];
        delete enemy_color_action[i];
        delete tag_color_action[i];
    }

    delete ui;
}

void MainWindow::processGameControlImage(void)
{
    auto image_data = shared_parameters.getImageData();

    /*for(auto i = image_data.begin(); i != image_data.end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;*/

    cv::Mat image(shared_parameters.getImageHeight(), shared_parameters.getImageWidth(), shared_parameters.getImageCVType(), &image_data[0]);

    if(image.empty())
    {
        std::cout << "Image is empty" << std::endl;
        return;
    }

    if(image.rows > 0 && image.cols > 0)
    {
        if(ui->color_objects_cb->isChecked())
        {
            //draws colors objects
            std::vector<ColoredObject> object = shared_parameters.getColorObjects();
            const char *color_name[] = COLOR_MEMBER_NAMES;
            for(int i=0; i<object.size(); i++)
            {
                cv::circle(image, cv::Point(object[i].coord.x, object[i].coord.y),
                                             DOT_RADIUS, SCALAR_GREEN, DOT_THICKNESS);
                if(object[i].color != UNCOLORED && object[i].coord.x != NAN && object[i].coord.y != NAN)
                {
                    if(object[i].coord.y - TEXT_Y_OFFSET >= 0)
                    {
                        if(object[i].coord.y - TEXT_X_OFFSET >= 0)
                            cv::putText(image, color_name[static_cast<int>(object[i].color)],
                                        cv::Point(object[i].coord.x - TEXT_X_OFFSET, object[i].coord.y - TEXT_Y_OFFSET),
                                        DEFAULT_IMAGE_TEXT_FONT, IMAGE_TEXT_SCALING, SCALAR_GREEN);
                        else
                            cv::putText(image, color_name[static_cast<int>(object[i].color)],
                                        cv::Point(object[i].coord.x, object[i].coord.y - TEXT_Y_OFFSET),
                                        DEFAULT_IMAGE_TEXT_FONT, IMAGE_TEXT_SCALING, SCALAR_GREEN);
                    }
                    else
                    {
                        if(object[i].coord.y - TEXT_X_OFFSET >= 0)
                            cv::putText(image, color_name[static_cast<int>(object[i].color)],
                                        cv::Point(object[i].coord.x - TEXT_X_OFFSET, object[i].coord.y + TEXT_Y_OFFSET),
                                        DEFAULT_IMAGE_TEXT_FONT, IMAGE_TEXT_SCALING, SCALAR_GREEN);
                        else
                            cv::putText(image, color_name[static_cast<int>(object[i].color)],
                                        cv::Point(object[i].coord.x, object[i].coord.y + TEXT_Y_OFFSET),
                                        DEFAULT_IMAGE_TEXT_FONT, IMAGE_TEXT_SCALING, SCALAR_GREEN);
                    }
                }
            }
        }
        if(ui->robot_positions_cb->isChecked())
        {
            //draws robots
            Entity ball = shared_parameters.getBall();
            Player ally[N_ROBOTS];
            for(int i=0; i<N_ROBOTS; i++)
                ally[i] = shared_parameters.getAllyRobot(i);
            Entity enemy[N_ROBOTS];
            for(int i=0; i<N_ROBOTS; i++)
                enemy[i] = shared_parameters.getEnemyRobot(i);

            if(ball.already_found && ball.coord.x != NAN && ball.coord.y != NAN)
            {
                cv::Scalar *scalar_color;
                if(ball.found_last_frame)
                    scalar_color = new SCALAR_GREEN;
                else
                    scalar_color = new SCALAR_RED;
                cv::circle(image, cv::Point(ball.coord.x, ball.coord.y),
                           DOT_RADIUS, *scalar_color, DOT_THICKNESS);

                std::string ball_name("BALL");
                cv::putText(image, ball_name, cv::Point(ball.coord.x - TEXT_X_OFFSET,
                            ball.coord.y + TEXT_Y_OFFSET), DEFAULT_IMAGE_TEXT_FONT,
                        IMAGE_TEXT_SCALING, *scalar_color);
                delete scalar_color;
            }

            for(int i=0; i<N_ROBOTS; i++)
            {
                if(ally[i].already_found && ally[i].coord.x != NAN && ally[i].coord.y != NAN)
                {
                    cv::Scalar *scalar_color;
                    if(ally[i].found_last_frame)
                        scalar_color = new SCALAR_GREEN;
                    else
                        scalar_color = new SCALAR_RED;
                    cv::circle(image, cv::Point(ally[i].coord.x, ally[i].coord.y),
                               DOT_RADIUS, *scalar_color, DOT_THICKNESS);

                    std::string ally_name("ROBOT_");
                    ally_name += std::to_string(i);
                    cv::putText(image, ally_name, cv::Point(ally[i].coord.x - TEXT_X_OFFSET,
                                ally[i].coord.y + TEXT_Y_OFFSET), DEFAULT_IMAGE_TEXT_FONT,
                                IMAGE_TEXT_SCALING, *scalar_color);
                    delete scalar_color;
                }
            }

            for(int i=0; i<N_ROBOTS; i++)
            {
                if(enemy[i].already_found && enemy[i].coord.x != NAN && enemy[i].coord.y != NAN)
                {
                    cv::Scalar *scalar_color;
                    if(enemy[i].found_last_frame)
                        scalar_color = new SCALAR_GREEN;
                    else
                        scalar_color = new SCALAR_RED;
                    cv::circle(image, cv::Point(enemy[i].coord.x, enemy[i].coord.y),
                               DOT_RADIUS, *scalar_color, DOT_THICKNESS);

                    std::string enemy_name("ENEMY");
                    cv::putText(image, enemy_name, cv::Point(enemy[i].coord.x - TEXT_X_OFFSET,
                                enemy[i].coord.y + TEXT_Y_OFFSET), DEFAULT_IMAGE_TEXT_FONT,
                                IMAGE_TEXT_SCALING, *scalar_color);
                    delete scalar_color;
                }
            }
        }
        if(ui->player_status_cb->isChecked())
        {
            //draws robot statuses
            Player ally[N_ROBOTS];
            for(int i=0; i<N_ROBOTS; i++)
                ally[i] = shared_parameters.getAllyRobot(i);

            for(int i=0; i<N_ROBOTS; i++)
            {
                if(ally[i].already_found && ally[i].coord.x != NAN && ally[i].coord.y != NAN)
                {
                    cv::Scalar *scalar_color;
                    if(ally[i].found_last_frame)
                        scalar_color = new SCALAR_GREEN;
                    else
                        scalar_color = new SCALAR_RED;
                    cv::putText(image, ally[i].status, cv::Point(ally[i].coord.x - TEXT_X_OFFSET,
                                ally[i].coord.y - TEXT_Y_OFFSET), DEFAULT_IMAGE_TEXT_FONT,
                                IMAGE_TEXT_SCALING, *scalar_color);
                    delete scalar_color;
                }
            }
        }
        if(ui->player_movements_cb->isChecked())
        {
            //draws movement arrows
            Player ally[N_ROBOTS];
            for(int i=0; i<N_ROBOTS; i++)
                ally[i] = shared_parameters.getAllyRobot(i);

            for(int i=0; i<N_ROBOTS; i++)
            {
                if(ally[i].already_found && ally[i].coord.x != NAN && ally[i].coord.y != NAN
                   && ally[i].movement.linear_vel_angle != NAN && ally[i].movement.linear_vel_scaling != NAN)
                {
                    cv::Scalar *scalar_color;
                    if(ally[i].movement.stay_still)
                        scalar_color = new SCALAR_RED;
                    else
                        scalar_color = new SCALAR_BLUE;

                    cv::line(image, cv::Point(ally[i].coord.x, ally[i].coord.y),
                    cv::Point(ally[i].coord.x + MOVEMENT_ARROW_LENGTH*cos(ally[i].movement.linear_vel_angle)*ally[i].movement.linear_vel_scaling,
                          ally[i].coord.y + MOVEMENT_ARROW_LENGTH*sin(ally[i].movement.linear_vel_angle)*ally[i].movement.linear_vel_scaling),
                    *scalar_color);

                    delete scalar_color;
                }
            }
        }

        cv::Mat resized_image;
        cv::Size new_size(ui->game_control_image->width(),ui->game_control_image->height());
        cv::resize(image, resized_image, new_size, INTERPOLATION_METHOD);

        cv::cvtColor(resized_image, resized_image, CV_BGR2RGB);
        QImage qimage((uchar*)resized_image.data, resized_image.cols, resized_image.rows,
                      resized_image.step, QImage::Format_RGB888);

        ui->game_control_image->setPixmap(QPixmap::fromImage(qimage));
    }
}

void MainWindow::processVisionSettingsImage(void)
{
    auto image_data = shared_parameters.getImageData();
    cv::Mat image(shared_parameters.getImageHeight(), shared_parameters.getImageWidth(), shared_parameters.getImageCVType(), &image_data[0]);
    if(image.empty())
    {
        std::cout << "Image is empty" << std::endl;
        return;
    }

    if(image.rows > 0 && image.cols > 0)
    {
        {
            //draws colors objects
            std::vector<ColoredObject> object = shared_parameters.getColorObjects();
            const char *color_name[] = COLOR_MEMBER_NAMES;
            for(int i=0; i<object.size(); i++)
            {
                cv::circle(image, cv::Point(object[i].coord.x, object[i].coord.y),
                                             DOT_RADIUS, SCALAR_GREEN, DOT_THICKNESS);
                if(object[i].color != UNCOLORED && object[i].coord.x != NAN && object[i].coord.y != NAN)
                {
                    if(object[i].coord.y - TEXT_Y_OFFSET >= 0)
                    {
                        if(object[i].coord.y - TEXT_X_OFFSET >= 0)
                            cv::putText(image, color_name[static_cast<int>(object[i].color)],
                                        cv::Point(object[i].coord.x - TEXT_X_OFFSET, object[i].coord.y - TEXT_Y_OFFSET),
                                        DEFAULT_IMAGE_TEXT_FONT, IMAGE_TEXT_SCALING, SCALAR_GREEN);
                        else
                            cv::putText(image, color_name[static_cast<int>(object[i].color)],
                                        cv::Point(object[i].coord.x, object[i].coord.y - TEXT_Y_OFFSET),
                                        DEFAULT_IMAGE_TEXT_FONT, IMAGE_TEXT_SCALING, SCALAR_GREEN);
                    }
                    else
                    {
                        if(object[i].coord.y - TEXT_X_OFFSET >= 0)
                            cv::putText(image, color_name[static_cast<int>(object[i].color)],
                                        cv::Point(object[i].coord.x - TEXT_X_OFFSET, object[i].coord.y + TEXT_Y_OFFSET),
                                        DEFAULT_IMAGE_TEXT_FONT, IMAGE_TEXT_SCALING, SCALAR_GREEN);
                        else
                            cv::putText(image, color_name[static_cast<int>(object[i].color)],
                                        cv::Point(object[i].coord.x, object[i].coord.y + TEXT_Y_OFFSET),
                                        DEFAULT_IMAGE_TEXT_FONT, IMAGE_TEXT_SCALING, SCALAR_GREEN);
                    }
                }
            }
        }

        {
            //draws searched region rectangle
            Coord ulc = shared_parameters.getSearchedRegionULC();
            Coord lrc = shared_parameters.getSearchedRegionLRC();
            if(ulc.x != NAN && ulc.y != NAN && lrc.x != NAN && lrc.y != NAN)
                cv::rectangle(image, cv::Point(ulc.x, ulc.y), cv::Point(lrc.x, lrc.y), SCALAR_RED, REC_THICKNESS);
        }

        cv::Mat resized_image;
        cv::Size new_size(ui->vision_settings_image->width(),ui->vision_settings_image->height());
        cv::resize(image, resized_image, new_size, INTERPOLATION_METHOD);

        cv::cvtColor(resized_image, resized_image, CV_BGR2RGB);
        QImage qimage((uchar*)resized_image.data, resized_image.cols, resized_image.rows,
                      resized_image.step, QImage::Format_RGB888);

        ui->vision_settings_image->setPixmap(QPixmap::fromImage(qimage));
    }
}

void MainWindow::processAISettingsImage(void)
{
    auto image_data = shared_parameters.getImageData();
    cv::Mat image(shared_parameters.getImageHeight(), shared_parameters.getImageWidth(), shared_parameters.getImageCVType(), &image_data[0]);
    if(image.empty())
    {
        std::cout << "Image is empty" << std::endl;
        return;
    }

    if(image.rows > 0 && image.cols > 0)
    {
        {
            //draws rectangles

            Coord ulc = shared_parameters.getPlayableFieldULC();
            Coord lrc = shared_parameters.getPlayableFieldLRC();
            if(ulc.x != NAN && ulc.y != NAN && lrc.x != NAN && lrc.y != NAN)
                cv::rectangle(image, cv::Point(ulc.x, ulc.y), cv::Point(lrc.x, lrc.y), SCALAR_GREEN, REC_THICKNESS);

            ulc = shared_parameters.getLeftGoalULC();
            lrc = shared_parameters.getLeftGoalLRC();
            if(ulc.x != NAN && ulc.y != NAN && lrc.x != NAN && lrc.y != NAN)
                cv::rectangle(image, cv::Point(ulc.x, ulc.y), cv::Point(lrc.x, lrc.y), SCALAR_RED, REC_THICKNESS);

            ulc = shared_parameters.getRightGoalULC();
            lrc = shared_parameters.getRightGoalLRC();
            if(ulc.x != NAN && ulc.y != NAN && lrc.x != NAN && lrc.y != NAN)
                cv::rectangle(image, cv::Point(ulc.x, ulc.y), cv::Point(lrc.x, lrc.y), SCALAR_RED, REC_THICKNESS);

            ulc = shared_parameters.getLeftGKAreaULC();
            lrc = shared_parameters.getLeftGKAreaLRC();
            if(ulc.x != NAN && ulc.y != NAN && lrc.x != NAN && lrc.y != NAN)
                cv::rectangle(image, cv::Point(ulc.x, ulc.y), cv::Point(lrc.x, lrc.y), SCALAR_BLUE, REC_THICKNESS);

            ulc = shared_parameters.getRightGKAreaULC();
            lrc = shared_parameters.getRightGKAreaLRC();
            if(ulc.x != NAN && ulc.y != NAN && lrc.x != NAN && lrc.y != NAN)
                cv::rectangle(image, cv::Point(ulc.x, ulc.y), cv::Point(lrc.x, lrc.y), SCALAR_BLUE, REC_THICKNESS);
        }

        cv::Mat resized_image;
        cv::Size new_size(ui->ai_settings_image->width(),ui->ai_settings_image->height());
        cv::resize(image, resized_image, new_size, INTERPOLATION_METHOD);

        cv::cvtColor(resized_image, resized_image, CV_BGR2RGB);
        QImage qimage((uchar*)resized_image.data, resized_image.cols, resized_image.rows,
                      resized_image.step, QImage::Format_RGB888);

        ui->ai_settings_image->setPixmap(QPixmap::fromImage(qimage));
    }
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

void MainWindow::on_vision_path_button_clicked(void)
{
    QString vision_path = QFileDialog::getOpenFileName(this, tr("Vision Path"));
    ui->vision_path_input->setText(vision_path);
}

void MainWindow::on_ai_path_button_clicked(void)
{
    QString ai_path = QFileDialog::getOpenFileName(this, tr("AI Path"));
    ui->ai_path_input->setText(ai_path);
}

void MainWindow::on_comm_path_button_clicked(void)
{
    QString comm_path = QFileDialog::getOpenFileName(this, tr("Comm Path"));
    ui->comm_path_input->setText(comm_path);
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
}

void MainWindow::on_shutdown_ai_clicked(void)
{
    emit shutdownAI();
}

void MainWindow::on_shutdown_comm_clicked(void)
{
    emit shutdownComm();
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
    shared_parameters.setAICommand(qstr.toStdString());
    emit aiSettingsChanged();
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
        emit visionSettingsChanged();
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
        emit visionSettingsChanged();
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
        emit visionSettingsChanged();
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
        emit visionSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->sr_lrc_y->foregroundRole(), Qt::red);
        ui->sr_lrc_y->setPalette(red_text);
    }
}

void MainWindow::on_pf_ulc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->pf_ulc_x->foregroundRole(), Qt::black);
        ui->pf_ulc_x->setPalette(black_text);
        shared_parameters.setPlayableFieldULCx(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->pf_ulc_x->foregroundRole(), Qt::red);
        ui->pf_ulc_x->setPalette(red_text);
    }
}

void MainWindow::on_pf_ulc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->pf_ulc_y->foregroundRole(), Qt::black);
        ui->pf_ulc_y->setPalette(black_text);
        shared_parameters.setPlayableFieldULCy(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->pf_ulc_y->foregroundRole(), Qt::red);
        ui->pf_ulc_y->setPalette(red_text);
    }
}

void MainWindow::on_pf_lrc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->pf_lrc_x->foregroundRole(), Qt::black);
        ui->pf_lrc_x->setPalette(black_text);
        shared_parameters.setPlayableFieldLRCx(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->pf_lrc_x->foregroundRole(), Qt::red);
        ui->pf_lrc_x->setPalette(red_text);
    }
}

void MainWindow::on_pf_lrc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->pf_lrc_y->foregroundRole(), Qt::black);
        ui->pf_lrc_y->setPalette(black_text);
        shared_parameters.setPlayableFieldLRCy(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->pf_lrc_y->foregroundRole(), Qt::red);
        ui->pf_lrc_y->setPalette(red_text);
    }
}

void MainWindow::on_left_goal_ulc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->left_goal_ulc_x->foregroundRole(), Qt::black);
        ui->left_goal_ulc_x->setPalette(black_text);
        shared_parameters.setLeftGoalULCx(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->left_goal_ulc_x->foregroundRole(), Qt::red);
        ui->left_goal_ulc_x->setPalette(red_text);
    }
}

void MainWindow::on_left_goal_ulc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->left_goal_ulc_y->foregroundRole(), Qt::black);
        ui->left_goal_ulc_y->setPalette(black_text);
        shared_parameters.setLeftGoalULCy(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->left_goal_ulc_y->foregroundRole(), Qt::red);
        ui->left_goal_ulc_y->setPalette(red_text);
    }
}

void MainWindow::on_left_goal_lrc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->left_goal_lrc_x->foregroundRole(), Qt::black);
        ui->left_goal_lrc_x->setPalette(black_text);
        shared_parameters.setLeftGoalLRCx(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->left_goal_lrc_x->foregroundRole(), Qt::red);
        ui->left_goal_lrc_x->setPalette(red_text);
    }
}

void MainWindow::on_left_goal_lrc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->left_goal_lrc_y->foregroundRole(), Qt::black);
        ui->left_goal_lrc_y->setPalette(black_text);
        shared_parameters.setLeftGoalLRCy(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->left_goal_lrc_y->foregroundRole(), Qt::red);
        ui->left_goal_lrc_y->setPalette(red_text);
    }
}

void MainWindow::on_right_goal_ulc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->right_goal_ulc_x->foregroundRole(), Qt::black);
        ui->right_goal_ulc_x->setPalette(black_text);
        shared_parameters.setRightGoalULCx(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->right_goal_ulc_x->foregroundRole(), Qt::red);
        ui->right_goal_ulc_x->setPalette(red_text);
    }
}

void MainWindow::on_right_goal_ulc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->right_goal_ulc_y->foregroundRole(), Qt::black);
        ui->right_goal_ulc_y->setPalette(black_text);
        shared_parameters.setRightGoalULCy(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->right_goal_ulc_y->foregroundRole(), Qt::red);
        ui->right_goal_ulc_y->setPalette(red_text);
    }
}

void MainWindow::on_right_goal_lrc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->right_goal_lrc_x->foregroundRole(), Qt::black);
        ui->right_goal_lrc_x->setPalette(black_text);
        shared_parameters.setRightGoalLRCx(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->right_goal_lrc_x->foregroundRole(), Qt::red);
        ui->right_goal_lrc_x->setPalette(red_text);
    }
}

void MainWindow::on_right_goal_lrc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->right_goal_lrc_y->foregroundRole(), Qt::black);
        ui->right_goal_lrc_y->setPalette(black_text);
        shared_parameters.setRightGoalLRCy(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->right_goal_lrc_y->foregroundRole(), Qt::red);
        ui->right_goal_lrc_y->setPalette(red_text);
    }
}

void MainWindow::on_left_gka_ulc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->left_gka_ulc_x->foregroundRole(), Qt::black);
        ui->left_gka_ulc_x->setPalette(black_text);
        shared_parameters.setLeftGKAreaULCx(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->left_gka_ulc_x->foregroundRole(), Qt::red);
        ui->left_gka_ulc_x->setPalette(red_text);
    }
}

void MainWindow::on_left_gka_ulc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->left_gka_ulc_y->foregroundRole(), Qt::black);
        ui->left_gka_ulc_y->setPalette(black_text);
        shared_parameters.setLeftGKAreaULCy(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->left_gka_ulc_y->foregroundRole(), Qt::red);
        ui->left_gka_ulc_y->setPalette(red_text);
    }
}

void MainWindow::on_left_gka_lrc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->left_gka_lrc_x->foregroundRole(), Qt::black);
        ui->left_gka_lrc_x->setPalette(black_text);
        shared_parameters.setLeftGKAreaLRCx(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->left_gka_lrc_x->foregroundRole(), Qt::red);
        ui->left_gka_lrc_x->setPalette(red_text);
    }
}

void MainWindow::on_left_gka_lrc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->left_gka_lrc_y->foregroundRole(), Qt::black);
        ui->left_gka_lrc_y->setPalette(black_text);
        shared_parameters.setLeftGKAreaLRCy(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->left_gka_lrc_y->foregroundRole(), Qt::red);
        ui->left_gka_lrc_y->setPalette(red_text);
    }
}

void MainWindow::on_right_gka_ulc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->right_gka_ulc_x->foregroundRole(), Qt::black);
        ui->right_gka_ulc_x->setPalette(black_text);
        shared_parameters.setRightGKAreaULCx(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->right_gka_ulc_x->foregroundRole(), Qt::red);
        ui->right_gka_ulc_x->setPalette(red_text);
    }
}

void MainWindow::on_right_gka_ulc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->right_gka_ulc_y->foregroundRole(), Qt::black);
        ui->right_gka_ulc_y->setPalette(black_text);
        shared_parameters.setRightGKAreaULCy(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->right_gka_ulc_y->foregroundRole(), Qt::red);
        ui->right_gka_ulc_y->setPalette(red_text);
    }
}

void MainWindow::on_right_gka_lrc_x_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->right_gka_lrc_x->foregroundRole(), Qt::black);
        ui->right_gka_lrc_x->setPalette(black_text);
        shared_parameters.setRightGKAreaLRCx(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->right_gka_lrc_x->foregroundRole(), Qt::red);
        ui->right_gka_lrc_x->setPalette(red_text);
    }
}

void MainWindow::on_right_gka_lrc_y_textChanged(const QString &new_text)
{
    bool ok = false;
    double value = new_text.toDouble(&ok);
    if(ok)
    {
        black_text.setColor(ui->right_gka_lrc_y->foregroundRole(), Qt::black);
        ui->right_gka_lrc_y->setPalette(black_text);
        shared_parameters.setRightGKAreaLRCy(value);
        emit aiSettingsChanged();
    }
    else
    {
        red_text.setColor(ui->right_gka_lrc_y->foregroundRole(), Qt::red);
        ui->right_gka_lrc_y->setPalette(red_text);
    }
}

void MainWindow::changeBallColor(QAction* action)
{
    QString qstr = action->text();
    ui->ball_menu->setText(qstr);

    std::string new_ball_color = qstr.toStdString();
    const char *color_name[] = COLOR_MEMBER_NAMES;
    Color new_color;
    for(int i=0; i<N_COLORS; i++)
    {
        std::string tested_color = color_name[i];
        if(new_ball_color == tested_color)
            new_color = static_cast<Color>(i);
    }
    shared_parameters.setBallColor(new_color);
    emit visionSettingsChanged();
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
    emit visionSettingsChanged();
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
    emit visionSettingsChanged();
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

    emit visionSettingsChanged();
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

    emit visionSettingsChanged();
}

void MainWindow::handleVisionUpdate(void)
{
    //std::cout << "Vision Update Recieved" << std::endl << std::endl;
}

void MainWindow::handleAIUpdate(void)
{
    //std::cout << "AI Update Recieved" << std::endl << std::endl;
}

void MainWindow::handleCommUpdate(void)
{
    //std::cout << "Comm Update Recieved" << std::endl << std::endl;
}

#include "moc_mainwindow.cpp"
