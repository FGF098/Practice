#include "proportionalusetype.h"

ProportionalUseType::ProportionalUseType(const Resourse* use, unsigned int k) : UseType(use)
{
    value = k;
}

unsigned int ProportionalUseType::CalcUsage(unsigned int workValue) const
{
    return workValue * value;
}
