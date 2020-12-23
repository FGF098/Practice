#ifndef USETYPE_H
#define USETYPE_H

#include "resourse.h"

class UseType
{
public:

    UseType(Resourse use);

    const Resourse* getResourse() const;

    virtual unsigned int CalcUsage(unsigned int workValue) const = 0;

protected:

    Resourse used;
};

#endif // USETYPE_H
