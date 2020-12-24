#ifndef REALIZEDPROGRAM_H
#define REALIZEDPROGRAM_H

#include<QVector>

#include "program.h"
#include "realizedusetype.h"

QVector<const UseType*> nfs = {&CPUMidUse, &CPU_RAMMidUse, &GPUMidUse, &GPU_RAMMidUse, &SSDSmallUse};
Program GAME("Need for shift", "EE", nfs);

QVector<const UseType*> browser = {&CPUSmallUse, &CPU_RAMMidUse, &LANSmallUse};
Program BROWSER("Ghrome", "Gaagle", browser);

QVector<const UseType*> defender = {&CPUSmallUse, &CPU_RAMSmallUse, &LANSmallUse, &SSDSmallUse};
Program AVTIVIRUS("Kas", "Kas.lab", defender);

#endif // REALIZEDPROGRAM_H
