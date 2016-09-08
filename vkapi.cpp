#include "vkapi.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

VkApi* VkApi::instance = nullptr;

VkApi::VkApi(QObject *parent) : QObject(parent)
{
    auth = false;
    token=QString(APP_ID);
    _accessManager = new QNetworkAccessManager(this);

//    connect(_accessManager, &QNetworkAccessManager::finished, this, &QVkApi::onGetReply);
    // возможно не нужен
}

VkApi *VkApi::getInstance()
{
    if(instance == nullptr){
        instance = new VkApi(0);
    }
    return instance;
}

QUrl VkApi::getAuthUrl()
{
    return QUrl(QString("https://oauth.vk.com/authorize?client_id="+token+
                        "&display=page&redirect_uri=https://oauth.vk.com/blank.html"
                        "&scope=friends+messages&response_type=token&v=5.53"));
}

 User* VkApi::getOwner()
{
    return new User(this);
}

void VkApi::request(QUrl req)
{

}

void VkApi::request(QString req)
{
    req+="&access_token="+token+"&v=5.53";
    QNetworkRequest reqes(req);
    _accessManager->get(reqes);
}

QNetworkReply* VkApi::request(QString method, QVariantMap args)
{
    QString req ="https://api.vk.com/method/";
    req+=method+"?";
    for(auto arg = args.begin(); arg != args.end();arg++){
        req += "&"+arg.key()+"="+arg.value().toString();
    }
    req += "&access_token=" + token + "&v=5.53";
    QNetworkRequest reques(req);
    return _accessManager->get(reques);
}

void VkApi::onGetReply(QNetworkReply *reply)
{
    QString str = (QString)reply->readAll();
    qDebug()<< str;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject *jsonObj = new QJsonObject(jsonResponse.object());
    emit finish(jsonObj);
}

