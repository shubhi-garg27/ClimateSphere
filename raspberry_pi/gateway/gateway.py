from flask import Flask
from flask import request
from flask import jsonify

from zone_cache import *

app = Flask(__name__)


@app.route("/thread/ingest",
           methods=["POST"])
def ingest():

    payload = request.json

    zone_id = payload["zone_id"]

    update_zone(
        zone_id,
        payload
    )

    return {
        "status": "received"
    }


@app.route("/thread/zones")
def zones():

    return jsonify(
        get_all_zones()
    )


if __name__ == "__main__":

    app.run(
        host="0.0.0.0",
        port=6000
    )
