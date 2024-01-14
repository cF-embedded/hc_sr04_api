/******************************************************************************
 *chip: any uC
 *brief: HC-SR04 driver
 *details: Default configuration , initialize and most significant function
 *author: cF-embedded.pl
 ******************************************************************************/

#include "hc_sr04.h"
#include <stddef.h>

#define TRIG_TIME      10

hc_sr04_status_e_t hc_sr04_init(hc_sr04_s_t* hc_sr04, hc_sr04_hardware_s_t hardware)
{
    if(hc_sr04 == NULL)
    {
        return HC_SR04_STATUS_ERROR;
    }

    hc_sr04->hardware = hardware;
    hc_sr04->hardware.hc_sr04_hardware_init();

    hc_sr04->last_distance = 0;
    hc_sr04->trig_time = TRIG_TIME;

    hc_sr04->echo = ECHO_NOK;
    hc_sr04->state = WAIT_FOR_ACTIVE;

    return HC_SR04_STATUS_OK;
}

distance_cm_t hc_sr04_get_distance(hc_sr04_s_t* hc_sr04)
{
    switch(hc_sr04->state)
    {
        case WAIT_FOR_ACTIVE:
        {
            hc_sr04->hardware.hc_sr04_hardware_tim_trig(hc_sr04->trig_time);
            hc_sr04->state = WAIT_FOR_ECHO;
        }
        break;
        case WAIT_FOR_ECHO:
        {
            hc_sr04->echo = hc_sr04->hardware.hc_sr04_hardware_wait_for_echo();

            if(hc_sr04->echo == ECHO_OK)
            {
                hc_sr04->state = MEASURE_COMPLETE;
            }

            else if(hc_sr04->echo == ECHO_NOK)
            {
                hc_sr04->state = WAIT_FOR_ACTIVE;
                hc_sr04->last_distance = 0;
            }
        }
        break;
        case MEASURE_COMPLETE:
        {
            hc_sr04->last_distance = (hc_sr04->hardware.hc_sr04_hardware_tim_echo()) / TIM_CM_DIVIDER;   // Distance in cm = time in us / 58
            hc_sr04->state = WAIT_FOR_ACTIVE;
        }
        break;
    }

    return hc_sr04->last_distance;
}