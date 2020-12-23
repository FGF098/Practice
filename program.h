#ifndef PROGRAM_H
#define PROGRAM_H

#include <QString>
#include <QPair>
#include <QVector>
#include <QDateTime>

#include "resourse.h"
#include "usetype.h"

class Program
{
public:

    // if in usage list are same resourse usages, uses last in list
    Program(QString newName, QString newProducer, QVector<QPair<const Resourse*, const UseType*>> newUsage);

    // return list of pair resourse - his usage
    QVector<QPair<const Resourse*, unsigned int>>CalcUsage(unsigned int workValue) const;

    // add new usage for resourse, if resourse already using - change usage
    // also use this function for changing parameters of usage
    void addOrChangeUsage(const Resourse* newResourse, const UseType* newUsage);

    // delete usage of this resourse; if it not used already - it's OK
    void deleteUsage(const Resourse* deletedResourse);

    QString getName() const;
    QString getProducer() const;

    QVector<QDateTime> getUpdateList() const;

private:

    // can't be changed after initialization
    QString name;
    QString producer;

    // list of pair resourse - usage function (resourse must be unique) for easier functionality
    // but they isn't sorted!
    QVector<QPair<const Resourse*, const UseType*>> usage = QVector<QPair<const Resourse*, const UseType*>>();

    QVector<QDateTime> updateList = QVector<QDateTime>();

    // add to updateList date-time of a update
    void setUpdateDateTime();
};

#endif // PROGRAM_H
