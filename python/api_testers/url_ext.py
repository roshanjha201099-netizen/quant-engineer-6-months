from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route("/api/itinerary", methods=["POST"])
def receive_itinerary():
    data = request.get_json(silent=True) or {}

    print("\n--- New itinerary received ---")
    print("itineraryId:", data.get("itineraryId"))
    print("message:", data.get("message"))
    print("pageUrl:", data.get("pageUrl"))
    print("capturedAt:", data.get("capturedAt"))
    print("------------------------------\n")

    return jsonify({
        "success": True,
        "confirmation": "Backend received itinerary successfully",
        "received": data
    }), 200

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)
