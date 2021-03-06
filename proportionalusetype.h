#ifndef PROPORTIONALUSETYPE_H
#define PROPORTIONALUSETYPE_H

#include "resourse.h"
#include "usetype.h"

class ProportionalUseType : public UseType
{
public:
    ProportionalUseType(const Resourse* use, unsigned int k);

    unsigned int CalcUsage(unsigned int workValue) const override;

private:

    unsigned int value;
};

#endif // PROPORTIONALUSETYPE_H
