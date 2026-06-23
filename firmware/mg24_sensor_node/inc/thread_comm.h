
#ifndef THREAD_COMM_H
#define THREAD_COMM_H

#include "sensors.h"

void thread_init(void);

void thread_send(sensor_data_t data);

#endif
