#ifndef ROOK_H
#define ROOK_H

#include "bead.h"
#include <QObject>

class Rook : public QObject,Bead
{
    Q_OBJECT
public:
    explicit Rook(QObject *parent = 0);
    Rook();

signals:

public slots:

};

#endif // ROOK_H
