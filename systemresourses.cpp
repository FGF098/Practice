#include "systemresourses.h"

SystemResourses::SystemResourses()
{
    resourses.push_back(CPU);
    resourses.push_back(CPU_RAM);
    resourses.push_back(SSD);
    resourses.push_back(LAN);
    resourses.push_back(GPU);
    resourses.push_back(GPU_RAM);
}

SystemResourses::SystemResourses(const QVector<Resourse>* newResourses)
{
    int size = newResourses->size();

    for(int i = 0; i < size; i++)
    {
        resourses.push_back((*newResourses)[i]);
    }
}

QVector<const Resourse*> SystemResourses::getResourses() const
{
    int size = resourses.size();

    QVector<const Resourse*> result(size);

    for(int i = 0; i < size; i++)
    {
        result[i] = &(resourses[i]);
    }

    return result;
}
