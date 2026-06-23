# ClimateSphere Node-RED Dashboard

This flow demonstrates integration between ClimateSphere and Node-RED.

## Features

- Real-time zone monitoring
- Backend API integration
- Occupancy visualization
- Comfort monitoring

## Import Flow

1. Open Node-RED
2. Menu → Import
3. Select `flows.json`
4. Deploy

## Backend Requirement

The Flask backend must be running:

```bash
python app.py
```

Default endpoint:

```text
http://localhost:5000/api/zones
```
