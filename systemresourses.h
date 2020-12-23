#ifndef SYSTEMRESOURSES_H
#define SYSTEMRESOURSES_H

#include <QVector>
#include <QPair>

#include "resourse.h"
#include "program.h"

// use usual acess in private, give const pointers in getters
// container for system resourses
class SystemResourses
{
public:

    // CPU usage will be counting with GFLOPS (google it - "FLOPS")
    const Resourse CPU = Resourse("CPU", "GFLOPS", 350);

    // RAM usage count in MB, max = 16 GB
    const Resourse CPU_RAM = Resourse("CPU_RAM", "MB", 16384);

    // SSD usage count in MB/s, both read/write
    const Resourse SSD = Resourse("SSD", "MB/s", 150);

    // access to LAN
    const Resourse LAN = Resourse("LAN", "Mb/s", 1000);

    // GPU usage will be counting with GFLOPS
    const Resourse GPU = Resourse("GPU", "GFLOPF", 4096);

    // GPU_RAM
    const Resourse GPU_RAM = Resourse("GPU RAM", "MB", 8192);

    //default initializing with const-based resourses (previous)
    SystemResourses();

    //initializing with custom resourses
    SystemResourses(const QVector<Resourse>* newResourses);

    //getters
    QVector<const Resourse*> getResourses();

private:

    QVector<Resourse> resourses = QVector<Resourse>();

};

#endif // SYSTEMRESOURSES_H
