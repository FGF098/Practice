#ifndef SYSTEM_H
#define SYSTEM_H

#include <QVector>

#include "systemprograms.h"
#include "systemresourses.h"

class System : public SystemPrograms, public SystemResourses
{
public:

    System();

    System(const QVector<Resourse>* newResourses, const QVector<Program>* newPrograms);

    // return false if usage is too big, fail change
    bool updateWorkValue(int index, unsigned int newWorkValue);

    // first - program index, second - resourse
    QVector<QVector<unsigned int>> getUsage() const;

protected:

    QVector<unsigned int> workValues;
};

#endif // SYSTEM_H
