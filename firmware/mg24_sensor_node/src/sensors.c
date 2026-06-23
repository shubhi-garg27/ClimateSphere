#include "sensors.h"

void sensors_init(void)
{
}

sensor_data_t read_all_sensors(void)
{
    sensor_data_t data;

    data.temperature = 25.2;
    data.humidity = 58.4;
    data.lux = 420.0;
    data.occupied = 1;

    return data;
}
