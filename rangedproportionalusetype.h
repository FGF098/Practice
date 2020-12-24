#ifndef RANGEDPROPORTIONALUSETYPE_H
#define RANGEDPROPORTIONALUSETYPE_H

#include "resourse.h"
#include "usetype.h"

class RangedProportionalUseType : public UseType
{
public:

    RangedProportionalUseType(const Resourse* use, unsigned int k, unsigned int maxPercent);

    unsigned int CalcUsage(unsigned int workValue) const override;

private:

    unsigned int value;

    unsigned int percent;
};

#endif // RANGEDPROPORTIONALUSETYPE_H
