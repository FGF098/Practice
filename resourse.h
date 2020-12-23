#ifndef RESOURSE_H
#define RESOURSE_H

#include <QString>

// for using in program,
class Resourse
{
public:

    // constructor
    Resourse(QString newName, QString newUnitOfMeasurement, unsigned int newMaxValue);

    //getters
    QString getName();
    QString getUnitOfMeasurement();
    unsigned int getMaxValue();

    // abstract function for protecting from intialization and unprotected changing
    virtual void SetMaxValue(unsigned int newMaxValue) = 0;

protected:

    // can't be changed after initialization
    QString name;
    QString unitOfMeasurement;

    // may be changed after initialization, but only in system version
    unsigned int maxValue;
};

#endif // RESOURSE_H
