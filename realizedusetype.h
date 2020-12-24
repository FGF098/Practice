#ifndef REALIZEDUSETYPE_H
#define REALIZEDUSETYPE_H

#include "usetype.h"
#include "fixedusetype.h"
#include "jumpusetype.h"
#include "proportionalusetype.h"
#include "rangedproportionalusetype.h"
#include "systemresourses.h"

FixedUseType LANSmallUse (&LAN, 50);
FixedUseType SSDSmallUse (&SSD, 10);
FixedUseType CPUSmallUse (&CPU, 10);
FixedUseType CPU_RAMSmallUse (&CPU_RAM, 500);
FixedUseType GPUSmallUse (&GPU, 50);
FixedUseType GPU_RAMSmallUse (&GPU_RAM, 800);
RangedProportionalUseType CPUMidUse (&CPU, 15, 40);
RangedProportionalUseType CPU_RAMMidUse (&CPU_RAM, 400, 40);
RangedProportionalUseType GPUMidUse (&CPU, 50, 35);
RangedProportionalUseType GPU_RAMMidUse (&CPU_RAM, 300, 35);

#endif // REALIZEDUSETYPE_H
