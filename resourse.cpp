#include "resourse.h"

Resourse::Resourse(QString newName, QString newUnitOfMeasurement, unsigned int newMaxValue)
{
    name = newName;
    unitOfMeasurement = newUnitOfMeasurement;
    maxValue = newMaxValue;
}

QString Resourse::getName()
{
    return name;
}

QString Resourse::getUnitOfMeasurement()
{
    return unitOfMeasurement;
}

unsigned int Resourse::getMaxValue()
{
    return maxValue;
}
