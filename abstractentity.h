#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H

#include <QObject>
#include <QNetworkReply>

class VkApi;
class AbstractEntity : public QObject
{
public:
    explicit AbstractEntity(VkApi *api, int id, QObject *parent = 0);

    int id;

    QNetworkReply* reply;
protected:
    VkApi* api;

};

#endif // ABSTRACTENTITY_H
