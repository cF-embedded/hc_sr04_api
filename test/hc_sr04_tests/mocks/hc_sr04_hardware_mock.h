/******************************************************************************
 *brief: HC-SR04 driver mocks for TDD header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __HC_SR04_HARDWARE_MOCK_H
#define __HC_SR04_HARDWARE_MOCK_H

#include "../../../src/hc_sr04/hc_sr04_hardware.h"

void mock_hc_sr04_hardware_init(void);
void mock_hc_sr04_hardware_tim_trig(time_us_t);
time_us_t mock_hc_sr04_hardware_tim_echo(void);
hc_sr04_echo_e_t mock_hc_sr04_hardware_wait_for_echo(void);

/* helper functions for mocks */
void mock_hc_sr04_hardware_set_wait_for_echo(hc_sr04_echo_e_t);
void mock_hc_sr04_hardware_set_tim_echo(time_us_t);
void setup_hc_sr04_hardware_with_mocks(hc_sr04_hardware_s_t*);

#endif /* __HC_SR04_HARDWARE_MOCK_H */
