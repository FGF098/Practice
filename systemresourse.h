#ifndef SYSTEMRESOURSE_H
#define SYSTEMRESOURSE_H

#include "resourse.h"

// for creating and controlling by system
class SystemResourse : Resourse
{
public:

    SystemResourse(QString newName, QString newUnitOfMeasurement, unsigned int newMaxValue) :
        Resourse(newName, newUnitOfMeasurement, newMaxValue) {}

    void SetMaxValue(unsigned int newMaxValue) override;
};

#endif // SYSTEMRESOURSE_H
