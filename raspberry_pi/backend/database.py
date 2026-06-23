import sqlite3

from config import DATABASE_NAME


def get_connection():
    return sqlite3.connect(DATABASE_NAME)


def create_tables():

    conn = get_connection()

    cursor = conn.cursor()

    cursor.execute("""
    CREATE TABLE IF NOT EXISTS zones(
        zone_id INTEGER PRIMARY KEY,
        temperature REAL,
        humidity REAL,
        light REAL,
        occupied INTEGER,
        comfort_score REAL,
        fan_speed INTEGER,
        brightness INTEGER,
        timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
    )
    """)

    conn.commit()

    conn.close()
