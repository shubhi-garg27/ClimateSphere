#include "comfort_engine.h"

comfort_output_t evaluate_zone(
        float temp,
        float humidity,
        int occupied)
{
    comfort_output_t output;

    if(!occupied)
    {
        output.fan_speed = 0;
        output.brightness = 0;
        output.vent_angle = 0;

        return output;
    }

    if(temp > 27)
        output.fan_speed = 100;
    else if(temp > 25)
        output.fan_speed = 70;
    else
        output.fan_speed = 40;

    output.brightness = 80;

    output.vent_angle = 45;

    return output;
}
