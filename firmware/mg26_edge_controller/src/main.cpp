#include <iostream>

#include "zone_manager.h"
#include "matter_control.h"

int main()
{
    zone_manager_init();

    climate_input_t deskA;

    deskA.temperature = 29.0f;
    deskA.humidity = 60.0f;
    deskA.light_level = 250.0f;
    deskA.occupied = 1;

    climate_input_t deskB;

    deskB.temperature = 25.0f;
    deskB.humidity = 55.0f;
    deskB.light_level = 400.0f;
    deskB.occupied = 1;

    climate_input_t deskC;

    deskC.temperature = 26.0f;
    deskC.humidity = 50.0f;
    deskC.light_level = 350.0f;
    deskC.occupied = 0;

    update_zone(0, deskA);
    update_zone(1, deskB);
    update_zone(2, deskC);

    evaluate_all_zones();

    for(int i = 0; i < 3; i++)
    {
        zone_t zone = get_zone(i);

        std::cout
            << "Zone "
            << i
            << std::endl;

        std::cout
            << "Comfort Score: "
            << zone.prediction.comfort_score
            << std::endl;

        set_fan_speed(
            zone.prediction.recommended_fan_speed);

        set_light_level(
            zone.prediction.recommended_brightness);

        set_vent_angle(45);

        std::cout
            << "-------------------"
            << std::endl;
    }

    return 0;
}
