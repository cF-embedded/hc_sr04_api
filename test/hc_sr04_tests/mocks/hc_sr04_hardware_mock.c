/******************************************************************************
 *brief: HC-SR04 driver mocks for TDD source file
 *author: cF-embedded.pl
 ******************************************************************************/

#include "hc_sr04_hardware_mock.h"

time_us_t mock_time;

hc_sr04_echo_e_t mock_echo;

void mock_hc_sr04_hardware_init(void) {}

void mock_hc_sr04_hardware_tim_trig(time_us_t) {}

time_us_t mock_hc_sr04_hardware_tim_echo(void)
{
    return mock_time;
}

hc_sr04_echo_e_t mock_hc_sr04_hardware_wait_for_echo(void)
{
    return mock_echo;
}

void mock_hc_sr04_hardware_set_wait_for_echo(hc_sr04_echo_e_t echo)
{
    mock_echo = echo;
}

void mock_hc_sr04_hardware_set_tim_echo(time_us_t time)
{
    mock_time = time;
}

void setup_hc_sr04_hardware_with_mocks(hc_sr04_hardware_s_t* hardware)
{
    hardware->hc_sr04_hardware_init = mock_hc_sr04_hardware_init;
    hardware->hc_sr04_hardware_tim_trig = mock_hc_sr04_hardware_tim_trig;
    hardware->hc_sr04_hardware_tim_echo = mock_hc_sr04_hardware_tim_echo;
    hardware->hc_sr04_hardware_wait_for_echo = mock_hc_sr04_hardware_wait_for_echo;
}
