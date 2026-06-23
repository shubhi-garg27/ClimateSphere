
#include "sensors.h"
#include "thread_comm.h"

int main(void)
{
    sensors_init();

    thread_init();

    while(1)
    {
        sensor_data_t data;

        data = read_all_sensors();

        thread_send(data);
    }
}
