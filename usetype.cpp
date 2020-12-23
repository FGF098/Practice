#include "usetype.h"

UseType::UseType(Resourse use) : used(use) {}

const Resourse* UseType::getResourse() const
{
    return &used;
}
