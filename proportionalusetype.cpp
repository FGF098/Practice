#include "proportionalusetype.h"

ProportionalUseType::ProportionalUseType(Resourse use, unsigned int newValue) : UseType(use)
{
    value = newValue;
}

unsigned int ProportionalUseType::CalcUsage(unsigned int workValue) const
{
    return workValue * value;
}
