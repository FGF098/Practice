#ifndef USETYPE_H
#define USETYPE_H


class UseType
{
public:

    virtual unsigned int CalcUsage(unsigned int workValue) const = 0;
};

#endif // USETYPE_H
