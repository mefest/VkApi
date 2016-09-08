#ifndef USER_H
#define USER_H

#include "abstractentity.h"

class User : public AbstractEntity
{
    Q_OBJECT

public:
    explicit User(VkApi* api, int id = 0, QObject *parent = 0);
    explicit User(VkApi* api, QJsonObject user, QObject *parent = 0);


    QString getFirstName() { return firstName; }
    QString getLastName() { return lastName; }

private:
    QString firstName;
    QString lastName;

signals:

public slots:
    void onUpdate();

};

#endif // USER_H
