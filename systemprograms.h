#ifndef SYSTEMPROGRAMS_H
#define SYSTEMPROGRAMS_H

#include <QVector>
#include <QPair>

#include "program.h"

// class for containing programs in system
class SystemPrograms
{
public:

    // add default programs
    SystemPrograms();

    // create with custom programs
    SystemPrograms(const QVector<Program>* newPrograms);

    QVector<const Program*> getPrograms();

    void ChangeProgram(int index, const UseType* newType);

protected:

    QVector<Program> programs = QVector<Program>();
};

#endif // SYSTEMPROGRAMS_H
