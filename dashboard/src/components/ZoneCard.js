function ZoneCard({zone})
{
    return (
        <div
            style={{
                border:"1px solid #cccccc",
                marginBottom:"15px",
                padding:"15px",
                borderRadius:"8px"
            }}
        >
            <h3>
                Zone {zone.zone_id}
            </h3>

            <p>
                Temperature:
                {" "}
                {zone.temperature}
                °C
            </p>

            <p>
                Humidity:
                {" "}
                {zone.humidity}
                %
            </p>

            <p>
                Light:
                {" "}
                {zone.light}
                lux
            </p>

            <p>
                Occupied:
                {" "}
                {zone.occupied ? "Yes" : "No"}
            </p>

            <p>
                Comfort Score:
                {" "}
                {zone.comfort_score}
            </p>

            <p>
                Fan Speed:
                {" "}
                {zone.fan_speed}
                %
            </p>

            <p>
                Brightness:
                {" "}
                {zone.brightness}
                %
            </p>

        </div>
    );
}

export default ZoneCard;
