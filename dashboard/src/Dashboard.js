import React, { useEffect, useState } from "react";

import axios from "axios";

import Header from "./components/Header";
import ZoneCard from "./components/ZoneCard";
import StatisticsCard from "./components/StatisticsCard";

function Dashboard()
{
    const [zones, setZones] = useState([]);
    const [stats, setStats] = useState({});

    const loadData = async () =>
    {
        try
        {
            const zonesResponse =
                await axios.get(
                    "http://localhost:5000/api/zones"
                );

            const statsResponse =
                await axios.get(
                    "http://localhost:5000/api/statistics"
                );

            setZones(zonesResponse.data);

            setStats(statsResponse.data);
        }
        catch(error)
        {
            console.error(error);
        }
    };

    useEffect(() =>
    {
        loadData();

        const timer =
            setInterval(loadData, 5000);

        return () => clearInterval(timer);

    }, []);

    return (
        <div style={{padding:"20px"}}>

            <Header />

            <StatisticsCard stats={stats} />

            <h2>Climate Zones</h2>

            {
                zones.map(
                    (zone) =>
                    (
                        <ZoneCard
                            key={zone.zone_id}
                            zone={zone}
                        />
                    )
                )
            }

        </div>
    );
}

export default Dashboard;
