#include "program.h"

Program::Program(QString newName, QString newProducer, QVector<QPair<const Resourse*, const UseType*>> newUsage)
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
            if (newUsage[i].first == usage[j].first)
            {
                // change usage
                usage[j].second = newUsage[i].second;
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
        result.push_back(QPair<const Resourse*, unsigned int>(usage[i].first, usage[i].second->CalcUsage(workValue)));
    }

    return result;
}

void Program::addOrChangeUsage(const Resourse* newResourse, const UseType* newUsage)
{
    setUpdateDateTime();

    int size = usage.size();

    // flag for add new usage
    bool flag = true;

    // check for using same resorse
    for (int i = 0; i < size; i++)
    {
        // if using same resourse s]change usage to new
        if(usage[i].first == newResourse)
        {
            usage[i].second = newUsage;
            // no need to add new usage
            flag = false;
            // no need to continue seeking - resourses in usage must be unique
            break;
        }
    }

    // add new usage
    if(flag)
    {
        usage.push_back(QPair<const Resourse*, const UseType*>(newResourse, newUsage));
    }
}

void Program::deleteUsage(const Resourse* deletedResourse)
{
    setUpdateDateTime();

    int size = usage.size();

    for(int i = 0; i < size; i++)
    {
        // if matched - delete
        if(usage[i].first == deletedResourse)
        {
            usage.removeAt(i);
            // no need to continue searching - resourses in usage must be unique
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
