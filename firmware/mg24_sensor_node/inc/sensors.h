#ifndef SENSORS_H
#define SENSORS_H

typedef struct
{
    float temperature;
    float humidity;
    float lux;
    int occupied;
} sensor_data_t;

void sensors_init(void);

sensor_data_t read_all_sensors(void);

#endif
