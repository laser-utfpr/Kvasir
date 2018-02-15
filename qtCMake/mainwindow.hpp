#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_button_clicked();

    void on_box_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString box_text;
};

#endif // MAINWINDOW_H
