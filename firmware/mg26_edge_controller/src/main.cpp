#include "comfort_engine.h"
#include "matter_control.h"

int main()
{
    float temp = 28.0;

    float humidity = 60.0;

    int occupied = 1;

    comfort_output_t result;

    result =
        evaluate_zone(
            temp,
            humidity,
            occupied);

    set_fan_speed(result.fan_speed);

    set_light_level(result.brightness);

    set_vent_angle(result.vent_angle);

    return 0;
}
