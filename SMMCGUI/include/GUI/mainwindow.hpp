#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtCore>
#include <QWidget>
#include <QMainWindow>
#include <QMenu>
#include <QFileDialog>

#include <opencv2/opencv.hpp>

#include <string>
#include <iostream>
#include <cmath>
#include <ctime>

#include "guiconstants.h"
#include "smmcconstants.h"

#include "sharedparameters.hpp"
#include "smmcthread.hpp"

#ifdef USE_GPU
    #include <opencv2/gpu/gpu.hpp>
#endif

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    SharedParameters shared_parameters;
    SMMCThread *smmc;

    QString vision_path;
    QString ai_path;
    QString comm_path;

    QMenu command_menu, manual_command_menu, players_menu, side_menu;
    QAction **command_menu_action, **manual_command_menu_action, **players_menu_action, **side_menu_action;
    int n_command_actions, n_manual_command_action, n_available_players, n_sides;

    bool force_stop;

    QMenu ball_menu;
    QMenu ally_center_menu;
    QMenu enemy_center_menu;
    QAction *ball_color_action[N_COLORS];
    QAction *ally_color_action[N_COLORS];
    QAction *enemy_color_action[N_COLORS];

    QMenu available_tag_menu;
    QMenu current_tag_menu;
    QAction *tag_color_action[N_COLORS];

    QPalette black_text;
    QPalette red_text;

    QTimer* frame_update_timer;

    void processGameControlImage(void);
    void processVisionSettingsImage(void);
    void processAISettingsImage(void);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void stopSMMC(void);

    void visionSettingsChanged(void);
    void aiSettingsChanged(void);
    void commSettingsChanged(void);

    void runVision(void);
    void runAI(void);
    void runComm(void);

    void shutdownVision(void);
    void shutdownAI(void);
    void shutdownComm(void);

private slots:
    void on_vision_path_button_clicked(void);
    void on_ai_path_button_clicked(void);
    void on_comm_path_button_clicked(void);

    void on_vision_path_input_textChanged(const QString &arg1);
    void on_ai_path_input_textChanged(const QString &arg1);
    void on_comm_path_input_textChanged(const QString &arg1);

    void on_run_vision_clicked(void);
    void on_run_ai_clicked(void);
    void on_run_comm_clicked(void);

    void on_shutdown_vision_clicked(void);
    void on_shutdown_ai_clicked(void);
    void on_shutdown_comm_clicked(void);

    void makeCommandMenu(void);
    void changeCommand(QAction *action);

    void makeSideMenu(void);
    void changeSide(QAction *action);
    void on_send_command_clicked(void);

    void makeManualCommandMenu(void);
    void changeManualCommand(QAction *action);

    void makePlayersMenu(void);
    void changeManualPlayer(QAction *action);
    void on_send_manual_player_clicked(void);

    void on_stop_resume_clicked(void);

    void on_sr_ulc_x_textChanged(const QString &new_text);
    void on_sr_ulc_y_textChanged(const QString &new_text);
    void on_sr_lrc_x_textChanged(const QString &new_text);
    void on_sr_lrc_y_textChanged(const QString &new_text);

    void on_pf_ulc_x_textChanged(const QString &new_text);
    void on_pf_ulc_y_textChanged(const QString &new_text);
    void on_pf_lrc_x_textChanged(const QString &new_text);
    void on_pf_lrc_y_textChanged(const QString &new_text);
    void on_left_goal_ulc_x_textChanged(const QString &new_text);
    void on_left_goal_ulc_y_textChanged(const QString &new_text);
    void on_left_goal_lrc_x_textChanged(const QString &new_text);
    void on_left_goal_lrc_y_textChanged(const QString &new_text);
    void on_right_goal_ulc_x_textChanged(const QString &new_text);
    void on_right_goal_ulc_y_textChanged(const QString &new_text);
    void on_right_goal_lrc_x_textChanged(const QString &new_text);
    void on_right_goal_lrc_y_textChanged(const QString &new_text);
    void on_left_gka_ulc_x_textChanged(const QString &new_text);
    void on_left_gka_ulc_y_textChanged(const QString &new_text);
    void on_left_gka_lrc_x_textChanged(const QString &new_text);
    void on_left_gka_lrc_y_textChanged(const QString &new_text);
    void on_right_gka_ulc_x_textChanged(const QString &new_text);
    void on_right_gka_ulc_y_textChanged(const QString &new_text);
    void on_right_gka_lrc_x_textChanged(const QString &new_text);
    void on_right_gka_lrc_y_textChanged(const QString &new_text);

    void changeBallColor(QAction* action);
    void changeAllyCenter(QAction *action);
    void changeEnemyCenter(QAction *action);

    void addTagColor(QAction *action);
    void removeTagColor(QAction *action);

    void processImages(void);

    //is this useful?
    void handleVisionUpdate(void);
    void handleAIUpdate(void);
    void handleCommUpdate(void);
};

#endif // MAINWINDOW_HPP
