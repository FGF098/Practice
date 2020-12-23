#ifndef SYSTEMRESOURSE_H
#define SYSTEMRESOURSE_H

#include "resourse.h"

// resourse for system
class SystemResourse : public Resourse
{
public:

    SystemResourse(QString newName, QString newUnitOfMeasurement, unsigned int newMaxValue);

    void setMaxValue(unsigned int newMaxValue) override;
};

#endif // SYSTEMRESOURSE_H
