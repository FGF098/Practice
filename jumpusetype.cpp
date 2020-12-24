#include "jumpusetype.h"

JumpUseType::JumpUseType(const Resourse* use, QVector<QPair<unsigned int, unsigned int>> newBordersAndValues) : UseType(use)
{
    int size = newBordersAndValues.size();

    bordersAndValues = newBordersAndValues;

    int j;
    QPair<unsigned int, unsigned int> temp;

    // bubble sort
    for(int i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(bordersAndValues[j].first < bordersAndValues[i].first)
            {
                temp = bordersAndValues[j];
                bordersAndValues[j] = bordersAndValues[i];
                bordersAndValues[i] = temp;
            }
        }
    }
}

unsigned int JumpUseType::CalcUsage(unsigned int workValue) const
{
    if(workValue == 0)
    {
        return 0;
    }

    int size= bordersAndValues.size();

    for (int i = 0; i < size; i++)
    {
        if (bordersAndValues[i].first > workValue)
        {
            return bordersAndValues[i].second;
        }
    }

    return 0;
}
