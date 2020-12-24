#ifndef FIXEDUSETYPE_H
#define FIXEDUSETYPE_H

#include "resourse.h"
#include "usetype.h"

class FixedUseType : public UseType
{
public:

    FixedUseType(const Resourse* use, unsigned int newValue);

    unsigned int CalcUsage(unsigned int workValue) const override;

private:

    unsigned int value;
};

#endif // FIXEDUSETYPE_H
