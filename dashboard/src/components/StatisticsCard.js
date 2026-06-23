function StatisticsCard({stats})
{
    return (
        <div
            style={{
                border:"1px solid gray",
                padding:"10px",
                marginBottom:"20px"
            }}
        >
            <h2>System Statistics</h2>

            <p>
                Active Zones:
                {" "}
                {stats.active_zones}
            </p>

            <p>
                Average Comfort:
                {" "}
                {stats.average_comfort}
            </p>

        </div>
    );
}

export default StatisticsCard;
