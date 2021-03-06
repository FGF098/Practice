#include "systemprograms.h"

#include "realizedprogram.h"

SystemPrograms::SystemPrograms()
{
    programs.push_back(GAME);
    programs.push_back(BROWSER);
    programs.push_back(AVTIVIRUS);
}

SystemPrograms::SystemPrograms(const QVector<Program>* newPrograms)
{
    int size = newPrograms->size();

    for(int i = 0; i < size; i++)
    {
        programs.push_back((*newPrograms)[i]);
    }
}

QVector<const Program*> SystemPrograms::getPrograms()
{
    int size = programs.size();

    QVector<const Program*> result(size);

    for(int i = 0; i < size; i++)
    {
        result[i] = &(programs[i]);
    }

    return result;
}

void SystemPrograms::ChangeProgram(int index, const UseType* newType)
{
    programs[index].ChangeUsage(newType);
}
