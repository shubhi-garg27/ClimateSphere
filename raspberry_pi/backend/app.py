from flask import Flask
from flask import request
from flask import jsonify

from flask_cors import CORS

import sqlite3

from config import *

app = Flask(__name__)

CORS(app)


@app.route("/")
def home():

    return {
        "project": "ClimateSphere",
        "status": "running"
    }


@app.route("/api/zones", methods=["GET"])
def get_zones():

    conn = sqlite3.connect(DATABASE_NAME)

    cursor = conn.cursor()

    cursor.execute("""
    SELECT *
    FROM zones
    ORDER BY zone_id
    """)

    rows = cursor.fetchall()

    conn.close()

    result = []

    for row in rows:

        result.append(
            {
                "zone_id": row[0],
                "temperature": row[1],
                "humidity": row[2],
                "light": row[3],
                "occupied": row[4],
                "comfort_score": row[5],
                "fan_speed": row[6],
                "brightness": row[7]
            }
        )

    return jsonify(result)


@app.route("/api/zone/<int:zone_id>",
           methods=["GET"])
def get_zone(zone_id):

    conn = sqlite3.connect(DATABASE_NAME)

    cursor = conn.cursor()

    cursor.execute("""
    SELECT *
    FROM zones
    WHERE zone_id=?
    """, (zone_id,))

    row = cursor.fetchone()

    conn.close()

    if row is None:
        return jsonify({"error": "zone not found"}), 404

    return jsonify(
        {
            "zone_id": row[0],
            "temperature": row[1],
            "humidity": row[2],
            "light": row[3],
            "occupied": row[4],
            "comfort_score": row[5],
            "fan_speed": row[6],
            "brightness": row[7]
        }
    )


@app.route("/api/sensor",
           methods=["POST"])
def sensor_update():

    data = request.json

    conn = sqlite3.connect(DATABASE_NAME)

    cursor = conn.cursor()

    cursor.execute("""
    INSERT OR REPLACE INTO zones
    (
        zone_id,
        temperature,
        humidity,
        light,
        occupied,
        comfort_score,
        fan_speed,
        brightness
    )
    VALUES
    (
        ?,?,?,?,?,?,?,?
    )
    """,
    (
        data["zone_id"],
        data["temperature"],
        data["humidity"],
        data["light"],
        data["occupied"],
        data["comfort_score"],
        data["fan_speed"],
        data["brightness"]
    ))

    conn.commit()

    conn.close()

    return jsonify(
        {
            "status": "updated"
        }
    )


@app.route("/api/statistics",
           methods=["GET"])
def statistics():

    conn = sqlite3.connect(DATABASE_NAME)

    cursor = conn.cursor()

    cursor.execute("""
    SELECT COUNT(*)
    FROM zones
    WHERE occupied=1
    """)

    active_zones = cursor.fetchone()[0]

    cursor.execute("""
    SELECT AVG(comfort_score)
    FROM zones
    """)

    comfort = cursor.fetchone()[0]

    conn.close()

    return jsonify(
        {
            "active_zones": active_zones,
            "average_comfort": comfort
        }
    )


if __name__ == "__main__":

    app.run(
        host=SERVER_HOST,
        port=SERVER_PORT,
        debug=True
    )
