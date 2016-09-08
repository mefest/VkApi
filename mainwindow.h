#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vkapi.h"
#include <QJsonObject>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    VkApi *vkApi;

private:
    Ui::MainWindow *ui;

private slots:
    void urlChange(QUrl url);

};

#endif // MAINWINDOW_H
