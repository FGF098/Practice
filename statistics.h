#ifndef STATISTICS_H
#define STATISTICS_H

#include <QTime>

#include "system.h"

class Statistics : public System
{
public:

    Statistics();

    // return percent usage of every resourse (may be bigger than 100)
    QVector<unsigned int> getPercent(int programIndex, unsigned int workValue);

    // must be added in chronological order!
    void addMoment (QTime moment);

    // return average usage in percents of every resourse
    QVector<unsigned int> AverageUsagePercent (QTime from, QTime till);

protected:

    QVector< QPair< QVector<QVector<unsigned int>> , QTime>> usageHistory = QVector<QPair<QVector<QVector<unsigned int>>, QTime>>();
};

#endif // STATISTICS_H
