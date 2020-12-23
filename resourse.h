#ifndef RESOURSE_H
#define RESOURSE_H

#include <QString>

// abstract class for resourses for using in programs (they can't create resourses
class Resourse
{
public:

    // constructor
    Resourse(QString newName, QString newUnitOfMeasurement, unsigned int newMaxValue);

    //getters - const
    QString getName() const;
    QString getUnitOfMeasurement() const;
    unsigned int getMaxValue() const;

    // pure virtual function for system resourse
    virtual void setMaxValue(unsigned int newMaxValue) = 0;

protected:

    // can't be changed after initialization
    QString name;
    QString unitOfMeasurement;

    // may be changed after initialization, but only in system version
    // also can't be setted here
    unsigned int maxValue;
};

#endif // RESOURSE_H
