#ifndef PROGRAM_H
#define PROGRAM_H

#include <QString>
#include <QPair>
#include <QVector>
#include <QTime>

#include "resourse.h"
#include "usetype.h"

class Program
{
public:

    // if in usage list are same resourse usages, uses last in list
    Program(QString newName, QString newProducer, QVector<const UseType*> newUsages);

    // return list of pair resourse - his usage
    QVector<QPair<const Resourse*, unsigned int>>CalcUsage(unsigned int workValue) const;

    // also use this function for changing parameters of usage
    void ChangeUsage(const UseType* newUsage);

    QString getName() const;
    QString getProducer() const;

    QVector<QTime> getUpdateList() const;

private:

    // can't be changed after initialization
    QString name;
    QString producer;

    // list of pair resourse - usage function (resourse must be unique) for easier functionality
    // but they isn't sorted!
    QVector<const UseType*> usage = QVector<const UseType*>();

    QVector<QTime> updateList = QVector<QTime>();

    // add to updateList date-time of a update
    void setUpdateDateTime();
};

#endif // PROGRAM_H
