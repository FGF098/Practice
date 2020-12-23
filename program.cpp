#include "program.h"

Program::Program(QString newName, QString newProducer, QVector<const UseType*> newUsage)
{
    name = newName;
    producer = newProducer;

    int inSize = newUsage.size();
    int usageSize = 0;

    //flag to push new usage
    bool flag;

    // for all new usages
    for(int i = 0; i < inSize; i++)
    {
        //flag to push new usage
        flag = true;

        // match for same resourse
        for(int j = 0; j < usageSize; j++)
        {
            // check if resourse is same
            if (newUsage[i]->getResourse() == usage[j]->getResourse())
            {
                // change usage
                usage[j] = newUsage[i];
                //do not push
                flag = false;
                break;
            }
        }

        //push if no match found
        if(flag)
        {
            usage.push_back(newUsage[i]);
            usageSize++;
        }
    }
}

QVector<QPair<const Resourse*, unsigned int>> Program::CalcUsage(unsigned int workValue) const
{
    auto result = QVector<QPair<const Resourse*, unsigned int>>();

    int size = usage.size();

    for(int i = 0; i < size; i++)
    {
        result.push_back(QPair<const Resourse*, unsigned int>(usage[i]->getResourse(), usage[i]->CalcUsage(workValue)));
    }

    return result;
}

void Program::ChangeUsage(const UseType* newUsage)
{
    setUpdateDateTime();

    int size = usage.size();
    // check for using same resorse
    for (int i = 0; i < size; i++)
    {
        // if using same resourse - change usage to new
        if(usage[i]->getResourse() == newUsage->getResourse())
        {
            usage[i] = newUsage;
            break;
        }
    }
}

QString Program::getName() const
{
    return name;
}

QString Program::getProducer() const
{
    return producer;
}

QVector<QDateTime> Program::getUpdateList() const
{
    int size = updateList.size();

    QVector<QDateTime> updateListCopy(size);

    for(int i = 0; i < size; i++)
    {
        updateListCopy[i] = updateList[i];
    }

    return updateListCopy;
}

void Program::setUpdateDateTime()
{
    updateList.push_back(QDateTime::currentDateTime());
}
