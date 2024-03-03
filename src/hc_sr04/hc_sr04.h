/******************************************************************************
 *chip: any uC with PWM module
 *brief: HC-SR04 driver header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __HC_SR04_H
#define __HC_SR04_H

#include "hc_sr04_hardware.h"
#include "hc_sr04_types.h"

#define TIM_CM_DIVIDER 58

typedef struct
{
    time_us_t trig_time;
    distance_cm_t last_distance;
    hc_sr04_echo_e_t echo;
    hc_sr04_state_e_t state;
    hc_sr04_hardware_s_t hardware;
} hc_sr04_s_t;

hc_sr04_status_e_t hc_sr04_init(hc_sr04_s_t*, hc_sr04_hardware_s_t);

distance_cm_t hc_sr04_get_distance(hc_sr04_s_t*);

hc_sr04_state_e_t hc_sr04_get_state_by_echo(hc_sr04_s_t*);

#endif /* __HC_SR04_H */
