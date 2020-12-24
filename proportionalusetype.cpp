#include "proportionalusetype.h"

ProportionalUseType::ProportionalUseType(const Resourse* use, unsigned int newValue) : UseType(use)
{
    value = newValue;
}

unsigned int ProportionalUseType::CalcUsage(unsigned int workValue) const
{
    return workValue * value;
}
