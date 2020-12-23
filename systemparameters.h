#ifndef SYSTEMPARAMETERS_H
#define SYSTEMPARAMETERS_H

#include <QVector>
#include <QPair>

#include "systemresourse.h"
#include "program.h"

// use usual acess in private, give const pointers in getters
// container for system resourses
class SystemParameters
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
    SystemParameters();

    //initializing with custom max value for default resourses
    SystemParameters(unsigned int maxCPU, unsigned int maxCPU_RAM, unsigned int maxSSD, unsigned int maxLAN, unsigned int maxGPU, unsigned int maxGPU_RAM);

    //initializing with custom system(!) resourses
    SystemParameters(const QVector<SystemResourse> newResourses);

    //getters
    QVector<const Resourse*> getResourses();

    // return false if index out of range
    bool ChangeMaxValue(int indexOfResourse, unsigned int newMaxValue);

private:

    QVector<SystemResourse> resourses = QVector<SystemResourse>();

};

#endif // SYSTEMPARAMETERS_H
