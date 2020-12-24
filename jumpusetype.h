#ifndef JUMPUSETYPE_H
#define JUMPUSETYPE_H

#include <QVector>
#include <QPair>

#include "resourse.h"
#include "usetype.h"

class JumpUseType : public UseType
{
public:
    // first - border, up to (include) value = second
    JumpUseType(const Resourse* use, QVector<QPair<unsigned int, unsigned int>> newBordersAndValues);

    unsigned int CalcUsage(unsigned int workValue) const override;

private:

    QVector<QPair<unsigned int, unsigned int>> bordersAndValues;
};

#endif // JUMPUSETYPE_H
