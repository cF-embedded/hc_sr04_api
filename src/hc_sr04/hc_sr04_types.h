/******************************************************************************
 *brief: HC-SR04 driver types header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __HC_SR04_TYPES_H
#define __HC_SR04_TYPES_H

#include "stdint.h"
#include <stdbool.h>

typedef float distance_cm_t;
typedef uint16_t time_us_t;
typedef uint16_t time_ms_t;

typedef enum
{
    WAIT_FOR_ACTIVE,
    WAIT_FOR_ECHO,
    MEASURE_COMPLETE,
} hc_sr04_state_e_t;

typedef enum
{
    HC_SR04_STATUS_OK,
    HC_SR04_STATUS_ERROR,
} hc_sr04_status_e_t;

typedef enum
{
    ECHO_OK,
    ECHO_WAIT,
    ECHO_NOK,
} hc_sr04_echo_e_t;

#endif /* __HC_SR04_TYPES_H */