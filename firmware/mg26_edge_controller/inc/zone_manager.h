
#ifndef ZONE_MANAGER_H
#define ZONE_MANAGER_H

#include "climate_model.h"

#define MAX_ZONES 5

typedef struct
{
    int zone_id;

    climate_input_t sensor_data;

    climate_prediction_t prediction;

} zone_t;

void zone_manager_init(void);

void update_zone(
        int zone_id,
        climate_input_t input);

zone_t get_zone(
        int zone_id);

void evaluate_all_zones(void);

int get_active_zone_count(void);

#endif
