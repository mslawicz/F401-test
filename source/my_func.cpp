#include "my_func.h"
#include "mbed.h"

DigitalOut led1(LED1);

void myPeriodicFunction(void)
{
    led1 = !led1;
}