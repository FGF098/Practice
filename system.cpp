#include "system.h"

System::System() : SystemPrograms(), SystemResourses()
{
    workValues = QVector<unsigned int>(programs.size(), 0);
}

System::System(const QVector<Resourse>* newResourses, const QVector<Program>* newPrograms) : SystemPrograms(newPrograms), SystemResourses(newResourses)
{
    workValues = QVector<unsigned int>(programs.size(), 0);
}

QVector<QVector<unsigned int>> System::getUsage() const
{
    int programsSize = programs.size();
    int resoursesSize = resourses.size();

    auto result = QVector<QVector<unsigned int>>(programsSize);
    for(int i = 0; i < programsSize; i++)
    {
        result[i] = QVector<unsigned int>(resoursesSize, 0);
    }

    QVector<QPair<const Resourse*, unsigned int>> functionResult;
    int functionResultSize;
    // for every program
    for(int i = 0; i < programsSize; i++)
    {
        // for every resourse
        for(int j = 0; j < resoursesSize; j++)
        {
            // search for this resourse in program out
            functionResult = programs[i].CalcUsage(workValues[i]);
            functionResultSize = functionResult.size();
            for(int h = 0; h < functionResultSize; h++)
            {
                if(&resourses[j] == functionResult[h].first)
                {
                    result[i][j] = functionResult[h].second;
                    break;
                }
            }
        }
    }
    return result;
}

bool System::updateWorkValue(int index, unsigned int newWorkValue)
{
    unsigned int temp = workValues[index];
    workValues[index] = newWorkValue;

    auto usage = getUsage();

    int programsSize = usage.size();
    // usage must ne non-emoty
    int resoursesSize = usage[0].size();

    bool flag = true;

    unsigned int sum;
    // for every resourse
    for(int j = 0; j < resoursesSize; j++)
    {
        sum = 0;
        for (int i = 0; i < programsSize; i++)
        {
            sum+= usage[i][j];
        }

        if(sum > resourses[j].getMaxValue())
        {
            flag = false;
            workValues[index] = temp;
            break;
        }
    }

    return flag;
}
