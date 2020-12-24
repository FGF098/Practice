#include "usetype.h"

UseType::UseType(const Resourse* use) : used(*use) {}

const Resourse* UseType::getResourse() const
{
    return &used;
}
