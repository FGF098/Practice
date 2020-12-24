#include "statistics.h"

Statistics::Statistics() : System() {}

void Statistics::addMoment(QTime moment)
{
    usageHistory.push_back(QPair< QVector<QVector<unsigned int>> , QTime>(getUsage(), moment));
}

QVector<unsigned int> Statistics::getPercent(int programIndex, unsigned int workValue)
{
    int resoursesSize = resourses.size();

    // initiate with all zero
    QVector<unsigned int> result(resoursesSize, 0);

    QVector<QPair<const Resourse*, unsigned int>> functionResult;

    int functionResultSize;
    // for every resourse
    for(int j = 0; j < resoursesSize; j++)
    {
        // search for this resourse in program out
        functionResult = programs[programIndex].CalcUsage(workValue);
        functionResultSize = functionResult.size();
        // search matches for every resourse
        for(int h = 0; h < functionResultSize; h++)
        {
            if(&resourses[j] == functionResult[h].first)
            {
                result[j] = functionResult[h].second;
                break;
            }
        }
    }

    for(int i = 0; i < resoursesSize; i++)
    {
        result[i] = result[i] * 100 / resourses[i].getMaxValue();
    }

    return result;
}

QVector<unsigned int> Statistics::AverageUsagePercent (QTime from, QTime till)
{
    int resoursesSize = resourses.size();
    int programsSize = programs.size();
    int historySize = usageHistory.size();

    int start = historySize;
    QVector<unsigned int> result(resoursesSize, 0);

    // find start pozition
    for(int i = 0; i < historySize; i++)
    {
        if(usageHistory[i].second >= from)
        {
            start = i;
            break;
        }
    }

    int numberOfMoments = 0;

    for(int i = start; i < historySize; i++)
    {
        if(usageHistory[i].second <= till)
        {
            // for all resourses
            for (int j = 0; j < resoursesSize; j++)
            {
                // for every program
                for (int h = 0; h < programsSize; h++)
                {
                    result[j] += usageHistory[i].first[h][j];
                }
            }
            numberOfMoments++;
        }
        else
        {
            break;
        }
    }

    // if non-empty
    if(numberOfMoments > 0)
    {
        // counting an average
        for (int i = 0; i < resoursesSize; i++)
        {
            result[i] = result[i] * 100 / numberOfMoments;
        }
    }

    return result;
}
