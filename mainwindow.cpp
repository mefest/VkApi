#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vkapi.h"
#include <QDebug>
#include <QUrlQuery>
#include <QJsonArray>

#include "user.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vkApi = VkApi::getInstance();
    qDebug()<<vkApi->getAuthUrl();
    ui->web->setUrl(vkApi->getAuthUrl());

    connect(ui->web,&QWebEngineView::urlChanged,this, &MainWindow::urlChange);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::urlChange(QUrl url)
{
    url = url.toString().replace("#","?");
    QUrlQuery *query = new QUrlQuery(url);
    QString token = query->queryItemValue("access_token");
    qDebug()<<token;

    if(token != ""){
        vkApi->setToken(token);
        User *user = new User(vkApi, 0, this);
    }
}


