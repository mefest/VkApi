#ifndef ABSTRACTREPLY_H
#define ABSTRACTREPLY_H

#include <QObject>

class AbstractReply : public QObject
{
    Q_OBJECT
public:
    explicit AbstractReply(int id, QObject *parent = 0);

    int id;

    virtual void update() = 0;

signals:

public slots:
};

#endif // ABSTRACTREPLY_H
