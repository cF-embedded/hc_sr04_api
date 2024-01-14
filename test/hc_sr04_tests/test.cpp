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

TEST(hc_sr04_tests, status_eror_when_init_null_pointer)
{
    hc_sr04_s_t* hc_sr04 = NULL;
    hc_sr04_hardware_s_t hardware_mock;
    setup_hc_sr04_hardware_with_mocks(&hardware_mock);
    
    hc_sr04_status_e_t status = hc_sr04_init(hc_sr04, hardware_mock);

    EXPECT_EQ(status, HC_SR04_STATUS_ERROR);
}
