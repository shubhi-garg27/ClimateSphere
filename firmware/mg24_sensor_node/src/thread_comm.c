#include <stdio.h>
#include "thread_comm.h"

void thread_init(void)
{
}

void thread_send(sensor_data_t data)
{
    printf(
        "{\"temperature\":%.2f,"
        "\"humidity\":%.2f,"
        "\"lux\":%.2f,"
        "\"occupied\":%d}\n",
        data.temperature,
        data.humidity,
        data.lux,
        data.occupied
    );
}
