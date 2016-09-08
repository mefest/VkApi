#include "user.h"

#include <QDebug>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "vkapi.h"

User::User(VkApi *api, int id, QObject *parent) : AbstractEntity(api, id,parent)
{
    QVariantMap args;
    args["fields"] = "photo_50,city,verified";
    args["name_case"] = "Nom";
    reply = api->request("users.get", args);

    connect(reply, &QNetworkReply::finished, this, &User::onUpdate);
}


void User::onUpdate()
{
    QString str = (QString)reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObj(jsonResponse.object());
    qDebug()<<jsonObj.find("first_name").value();
    QJsonObject response = jsonObj.value("response").toArray().at(0).toObject();
    firstName = response.value("first_name").toString();
    lastName = response.value("last_name").toString();
    qDebug()<<firstName<<lastName;

    reply->deleteLater();
}
