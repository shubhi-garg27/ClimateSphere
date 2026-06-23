
#include "zone_manager.h"

static zone_t zones[MAX_ZONES];

static int active_zones = 0;

void zone_manager_init(void)
{
    active_zones = 0;

    for(int i = 0; i < MAX_ZONES; i++)
    {
        zones[i].zone_id = i;

        zones[i].sensor_data.temperature = 0;
        zones[i].sensor_data.humidity = 0;
        zones[i].sensor_data.light_level = 0;
        zones[i].sensor_data.occupied = 0;

        zones[i].prediction.comfort_score = 0;
        zones[i].prediction.recommended_fan_speed = 0;
        zones[i].prediction.recommended_brightness = 0;
    }
}

void update_zone(
        int zone_id,
        climate_input_t input)
{
    if(zone_id >= MAX_ZONES)
        return;

    zones[zone_id].sensor_data = input;
}

zone_t get_zone(
        int zone_id)
{
    return zones[zone_id];
}

void evaluate_all_zones(void)
{
    active_zones = 0;

    for(int i = 0; i < MAX_ZONES; i++)
    {
        zones[i].prediction =
            predict_comfort(
                zones[i].sensor_data);

        if(zones[i].sensor_data.occupied)
        {
            active_zones++;
        }
    }
}

int get_active_zone_count(void)
{
    return active_zones;
}
