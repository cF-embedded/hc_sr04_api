/******************************************************************************
 *brief: HC-SR04 driver TDD file
 *author: cF-embedded.pl
 ******************************************************************************/

extern "C"
{
#include "../../src/hc_sr04/hc_sr04.h"
#include "mocks/hc_sr04_hardware_mock.h"
}

#include <gtest/gtest.h>

TEST(hc_sr04_tests, status_eror_after_init_null_pointer)
{
    hc_sr04_s_t* hc_sr04 = NULL;
    hc_sr04_hardware_s_t hardware_mock;
    setup_hc_sr04_hardware_with_mocks(&hardware_mock);

    hc_sr04_status_e_t status = hc_sr04_init(hc_sr04, hardware_mock);

    EXPECT_EQ(status, HC_SR04_STATUS_ERROR);
}

TEST(hc_sr04_tests, status_ok_after_init)
{
    hc_sr04_s_t hc_sr04;
    hc_sr04_hardware_s_t hardware_mock;
    setup_hc_sr04_hardware_with_mocks(&hardware_mock);

    hc_sr04_status_e_t status = hc_sr04_init(&hc_sr04, hardware_mock);

    EXPECT_EQ(status, HC_SR04_STATUS_OK);
}

TEST(hc_sr04_tests, state_wait_for_active_after_init)
{
    hc_sr04_s_t hc_sr04;
    hc_sr04_hardware_s_t hardware_mock;
    setup_hc_sr04_hardware_with_mocks(&hardware_mock);

    hc_sr04_init(&hc_sr04, hardware_mock);

    EXPECT_EQ(hc_sr04.state, WAIT_FOR_ACTIVE);
}

TEST(hc_sr04_tests, state_wait_for_echo_after_get_distance)
{
    hc_sr04_s_t hc_sr04;
    hc_sr04_hardware_s_t hardware_mock;
    setup_hc_sr04_hardware_with_mocks(&hardware_mock);

    hc_sr04_init(&hc_sr04, hardware_mock);
    hc_sr04_get_distance(&hc_sr04);

    EXPECT_EQ(hc_sr04.state, WAIT_FOR_ECHO);
}

TEST(hc_sr04_tests, state_wait_for_active_after_echo_nok)
{
    hc_sr04_s_t hc_sr04;
    hc_sr04_hardware_s_t hardware_mock;
    setup_hc_sr04_hardware_with_mocks(&hardware_mock);

    hc_sr04_init(&hc_sr04, hardware_mock);
    hc_sr04_get_distance(&hc_sr04);
    mock_hc_sr04_hardware_set_wait_for_echo(ECHO_NOK);
    hc_sr04_get_distance(&hc_sr04);

    EXPECT_EQ(hc_sr04.state, WAIT_FOR_ACTIVE);
}

TEST(hc_sr04_tests, last_distance_0_after_echo_nok)
{
    hc_sr04_s_t hc_sr04;
    distance_cm_t distance;
    hc_sr04_hardware_s_t hardware_mock;
    setup_hc_sr04_hardware_with_mocks(&hardware_mock);

    hc_sr04_init(&hc_sr04, hardware_mock);
    hc_sr04_get_distance(&hc_sr04);
    mock_hc_sr04_hardware_set_wait_for_echo(ECHO_NOK);
    distance = hc_sr04_get_distance(&hc_sr04);

    EXPECT_EQ(distance, 0);
}
