/******************************************************************************
 *brief: HC-SR04 driver hardware interface header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __HC_SR04_HARDWARE_H
#define __HC_SR04_HARDWARE_H

#include "hc_sr04_types.h"

typedef struct
{
    void (*hc_sr04_hardware_init)(void);
    void (*hc_sr04_hardware_tim_trig)(time_us_t);
    time_us_t (*hc_sr04_hardware_tim_echo)(void);
    hc_sr04_echo_e_t (*hc_sr04_hardware_wait_for_echo)(void);
} hc_sr04_hardware_s_t;

#endif /* __HC_SR04_HARDWARE_H */