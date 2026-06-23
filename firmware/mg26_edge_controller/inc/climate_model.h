#ifndef CLIMATE_MODEL_H
#define CLIMATE_MODEL_H

typedef struct
{
    float temperature;
    float humidity;
    float light_level;
    int occupied;
} climate_input_t;

typedef struct
{
    float comfort_score;
    int recommended_fan_speed;
    int recommended_brightness;
} climate_prediction_t;

void climate_model_init(void);

climate_prediction_t predict_comfort(
        climate_input_t input);

#endif
