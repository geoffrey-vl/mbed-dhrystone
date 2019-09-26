#ifndef DHRYSTONE_H
#define DHRYSTONE_H

#include "stdint.h"


// Global Variables:
extern long g_dry_UserTime;
extern float g_dry_Microseconds;
extern float g_dry_Dhrystones_Per_Second;
extern float g_dmips;


// Functions:
#ifdef __cplusplus
extern "C" {
#endif
void Proc_0(uint32_t loops);
#ifdef __cplusplus
}
#endif


#endif //DHRYSTONE_H