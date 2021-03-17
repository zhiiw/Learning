#ifndef ITEMDEF_H
#define ITEMDEF_H
#include <QMetaType>

typedef enum{
    Loser,
    King//define the king status
} ItemStatus;

struct ItemData{
    QString name;
};

Q_DECLARE_METATYPE(ItemData)

#endif // ITEMDEF_H
