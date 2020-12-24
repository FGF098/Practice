#include "rangedproportionalusetype.h"

RangedProportionalUseType::RangedProportionalUseType(const Resourse* use, unsigned int k, unsigned int maxPercent) : UseType(use)
{
    value = k;

    if (maxPercent < 100)
    {
        percent = maxPercent;
    }
    else
    {
        percent = 50;
    }
}

unsigned int RangedProportionalUseType::CalcUsage(unsigned int workValue) const
{
    if (workValue * value <= used.getMaxValue() * percent / 100 + 1)
    {
        return workValue * value;
    }
    else
    {
        return used.getMaxValue() * percent / 100 + 1;
    }
}
