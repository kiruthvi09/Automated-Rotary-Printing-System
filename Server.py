from flask import Flask, request, jsonify

app = Flask(__name__)

# Store received delay data
received_data = []

@app.route('/receive_delay', methods=['POST'])
def receive_delay():
    data = request.get_json()
    if not data or "delays" not in data:
        return jsonify({"error": "Invalid data format"}), 400
    received_data.extend(data["delays"])
    return jsonify({"message": "Data received successfully"}), 200

@app.route('/data', methods=['GET'])
def display_data():
    if request.headers.get("Accept") == "application/json":
        return jsonify({"delays": received_data})  # Return JSON if requested
    else:
        # Default to HTML if accessed from a browser
        return """ 
        <html>
        <head>
            <title>Received Delay Data</title>
        </head>
        <body>
            <h2>Received Delay Data</h2>
            <table border="1">
                <tr><th>Color</th><th>Delay (seconds)</th></tr>
                """ + "".join(f"<tr><td>{item['color']}</td><td>{item['delay']}</td></tr>" for item in received_data) + """
            </table>
        </body>
        </html>
        """

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
