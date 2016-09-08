#ifndef QVKAPI_H
#define QVKAPI_H

#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "user.h"
#include "app.h"



class VkApi : public QObject
{
    Q_OBJECT
public:

    static VkApi* getInstance();
    const QString getToken(){ return token; }
    void setToken(QString _token){ auth = true; token = _token; }
    QUrl getAuthUrl();

    User *getOwner();
    QList<User*> *getUsers(QList<int> &ids);

    void request(QUrl req);
    void request(QString req);
    QNetworkReply* request(QString method, QVariantMap args);

    bool isAuth() const { return auth; }

private:
    QString appId;
    QString token;
    QString version;

    bool auth;

    QNetworkAccessManager* _accessManager;

    static VkApi* instance;
    explicit VkApi(QObject *parent = 0);

signals:

    void finish(QJsonObject* reply);

public slots:

    void onGetReply(QNetworkReply *);

};

#endif // QVKAPI_H
