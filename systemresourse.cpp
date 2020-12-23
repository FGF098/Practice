#include "systemresourse.h"

SystemResourse::SystemResourse(QString newName, QString newUnitOfMeasurement, unsigned int newMaxValue) :
    Resourse(newName, newUnitOfMeasurement, newMaxValue) {}

void SystemResourse::setMaxValue(unsigned int newMaxValue)
{
    maxValue = newMaxValue;
}
