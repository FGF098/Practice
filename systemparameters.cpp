#include "systemparameters.h"

SystemParameters::SystemParameters()
{
    resourses.push_back(CPU);
    resourses.push_back(CPU_RAM);
    resourses.push_back(SSD);
    resourses.push_back(LAN);
    resourses.push_back(GPU);
    resourses.push_back(GPU_RAM);
}

SystemParameters::SystemParameters(unsigned int maxCPU, unsigned int maxCPU_RAM, unsigned int maxSSD, unsigned int maxLAN, unsigned int maxGPU, unsigned int maxGPU_RAM)
{
    auto cpu = CPU;
    auto cpu_ram = CPU_RAM;
    auto ssd = SSD;
    auto lan = LAN;
    auto gpu = GPU;
    auto gpu_ram = GPU_RAM;

    cpu.setMaxValue(maxCPU);
    cpu_ram.setMaxValue(maxCPU_RAM);
    ssd.setMaxValue(maxSSD);
    lan.setMaxValue(maxLAN);
    gpu.setMaxValue(maxGPU);
    gpu_ram.setMaxValue(maxGPU_RAM);

    resourses.push_back(cpu);
    resourses.push_back(cpu_ram);
    resourses.push_back(ssd);
    resourses.push_back(lan);
    resourses.push_back(gpu);
    resourses.push_back(gpu_ram);
}

SystemParameters::SystemParameters(const QVector<SystemResourse> newResourses)
{
    int size = newResourses.size();

    for(int i = 0; i < size; i++)
    {
        resourses.push_back(newResourses[i]);
    }
}

bool SystemParameters::ChangeMaxValue(int indexOfResourse, unsigned int newMaxValue)
{
    if(indexOfResourse < 0 || indexOfResourse >= resourses.size())
    {
        return false;
    }
    else
    {
        resourses[indexOfResourse].setMaxValue(newMaxValue);
        return true;
    }
}
