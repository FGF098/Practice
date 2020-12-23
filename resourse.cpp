#include "resourse.h"

Resourse::Resourse(QString newName, QString newUnitOfMeasurement, unsigned int newMaxValue)
{
    name = newName;
    unitOfMeasurement = newUnitOfMeasurement;
    maxValue = newMaxValue;
}

QString Resourse::getName() const
{
    return name;
}

QString Resourse::getUnitOfMeasurement() const
{
    return unitOfMeasurement;
}

unsigned int Resourse::getMaxValue() const
{
    return maxValue;
}
