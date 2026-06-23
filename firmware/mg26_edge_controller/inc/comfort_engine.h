#ifndef COMFORT_ENGINE_H
#define COMFORT_ENGINE_H

typedef struct
{
    int fan_speed;
    int brightness;
    int vent_angle;
} comfort_output_t;

comfort_output_t evaluate_zone(
        float temp,
        float humidity,
        int occupied);

#endif
