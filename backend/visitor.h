#ifndef VISITOR_H
#define VISITOR_H

#include <QObject>

class Visitor : public QObject
{
    Q_OBJECT
public:
    explicit Visitor(QObject *parent = nullptr);

signals:
};

#endif // VISITOR_H
