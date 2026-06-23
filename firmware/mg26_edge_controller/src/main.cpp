#include <iostream>

#include "climate_model.h"
#include "comfort_engine.h"
#include "matter_control.h"

int main()
{
    climate_model_init();

    climate_input_t input;

    input.temperature = 28.0f;
    input.humidity = 60.0f;
    input.light_level = 250.0f;
    input.occupied = 1;

    climate_prediction_t prediction;

    prediction =
        predict_comfort(input);

    std::cout
        << "Comfort Score: "
        << prediction.comfort_score
        << std::endl;

    set_fan_speed(
        prediction.recommended_fan_speed);

    set_light_level(
        prediction.recommended_brightness);

    set_vent_angle(45);

    return 0;
}
