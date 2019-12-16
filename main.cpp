/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stats_report.h"
#include "platform/mbed_debug.h"
#include "my_func.h"

#define SLEEP_TIME                  500 // (msec)
#define PRINT_AFTER_N_LOOPS         20

Ticker periodicCall;

// main() runs in its own thread in the OS
int main()
{
    printf("Hello F401!\r\n");
    debug("this is a debug message\r\n");
    SystemReport sys_state( SLEEP_TIME * PRINT_AFTER_N_LOOPS /* Loop delay time in ms */);
    periodicCall.attach(&myPeriodicFunction, 0.5);

    int count = 0;
    while (true)
    {
        wait_ms(SLEEP_TIME);

        if ((0 == count) || (PRINT_AFTER_N_LOOPS == count)) {
            // Following the main thread wait, report on the current system status
            sys_state.report_state();
            count = 0;
        }
        ++count;
    }
}
