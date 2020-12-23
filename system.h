#ifndef SYSTEM_H
#define SYSTEM_H

#include <QVector>
#include <QPair>

#include "systemresourse.h"
#include "program.h"

// use usual acess in private, give const pointers in getters
class System
{
public:

    // CPU usage will be counting with GFLOPS (google it - "FLOPS")
    const SystemResourse CPU = SystemResourse("CPU", "GFLOPS", 350);

    // RAM usage count in MB, max = 16 GB
    const SystemResourse CPU_RAM = SystemResourse("CPU_RAM", "MB", 16384);

    // SSD usage count in MB/s, both read/write
    const SystemResourse SSD = SystemResourse("SSD", "MB/s", 150);

    // access to LAN
    const SystemResourse LAN = SystemResourse("LAN", "Mb/s", 1000);

    // GPU usage will be counting with GFLOPS
    const SystemResourse GPU = SystemResourse("GPU", "GFLOPF", 4096);

    // GPU_RAM
    const SystemResourse GPU_RAM = SystemResourse("GPU RAM", "MB", 8192);

    //default initializing with const-based resourses (previous)
    System();

    //initializing with custom max value for default resourses
    System(unsigned int maxCPU, unsigned int maxCPU_RAM, unsigned int maxSSD, unsigned int maxLAN, unsigned int maxGPU, unsigned int maxGPU_RAM);

    //initializing with custom system(!) resourses
    System(const QVector<SystemResourse> resourses);

    //getters
    QVector<const Resourse*> getResourses();
    // don't allow to change programs, because they can be deleted too
    QVector<const Program*> getPrograms();

    //function of

    ~System();

private:

    QVector<SystemResourse> resourses;

    // save programs and the work value
    QVector<QPair<Program, unsigned int>> programsAndWorks;

};

#endif // SYSTEM_H
