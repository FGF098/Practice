#include "fixedusetype.h"

FixedUseType::FixedUseType(Resourse use,unsigned int newValue) : UseType(use)
{
    value = newValue;
}

unsigned int FixedUseType::CalcUsage(unsigned int workValue) const
{
    if (workValue == 0)
    {
        return 0;
    }
    else
    {
        return value;
    }
}
