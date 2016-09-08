#include "abstractentity.h"

AbstractEntity::AbstractEntity(VkApi *api, int id, QObject *parent) : QObject(parent), id(id), api(api)
{
    //    api = QVkApi::getInstance();
}

