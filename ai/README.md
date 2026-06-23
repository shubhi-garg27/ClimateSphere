# ClimateSphere TinyML Model

This module provides edge-based comfort prediction for ClimateSphere.

## Inputs

- Temperature
- Humidity
- Ambient Light
- Occupancy Status

## Output

- Comfort Score (0–100)

## Workflow

```text
Sensor Data
      ↓
TinyML Model
      ↓
Comfort Score
      ↓
Comfort Engine
      ↓
Matter Control
```

## Training

```bash
python train_model.py
```

## Generate TFLite Model

```bash
python export_tflite.py
```

## Test Prediction

```bash
python predict.py
```
