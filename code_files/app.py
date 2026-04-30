from flask import Flask, render_template, request, jsonify
# import RPi.GPIO as GPIO # Uncomment when running on actual Pi connected to hardware

app = Flask(__name__)

# --- Database & State ---
VALID_USER = "owner"
VALID_PASS = "admin123"
VALID_RFID_TAG = "TAG12345" # Placeholder for your physical RFID data
CAR_UNLOCKED = False

# --- Hardware Setup Placeholder ---
# GPIO.setmode(GPIO.BCM)
# motor_forward_pin = 17
# GPIO.setup(motor_forward_pin, GPIO.OUT)

@app.route('/')
def index():
    return render_template('index.html')

# Route 1: Manual Login (Fallback)
@app.route('/login', methods=['POST'])
def login():
    global CAR_UNLOCKED
    data = request.json
    
    if data['username'] == VALID_USER and data['password'] == VALID_PASS:
        CAR_UNLOCKED = True
        print("--- CAR UNLOCKED VIA CREDENTIALS ---")
        return jsonify({"status": "success", "message": "Car Unlocked!"})
    else:
        return jsonify({"status": "error", "message": "Invalid Credentials"}), 401

# Route 2: RFID Login (Primary)
@app.route('/rfid-scan', methods=['POST'])
def rfid_scan():
    # In reality, the Pi reads the physical scanner.
    # This route lets us trigger a test scan from the phone screen.
    global CAR_UNLOCKED
    data = request.json
    
    if data.get('rfid_tag') == VALID_RFID_TAG:
        CAR_UNLOCKED = True
        print("--- CAR UNLOCKED VIA RFID ---")
        return jsonify({"status": "success", "message": "Car Unlocked!"})
    else:
        return jsonify({"status": "error", "message": "Invalid RFID Tag"}), 401

# Route 3: Driving Controls
@app.route('/control', methods=['POST'])
def control_car():
    if not CAR_UNLOCKED:
        return jsonify({"status": "error", "message": "Car is locked!"}), 403
        
    command = request.json.get('command')
    
    # --- Hardware Execution ---
    if command == "forward":
        print("Hardware: Moving Forward")
    elif command == "backward":
        print("Hardware: Moving Backward")
    elif command == "left":
        print("Hardware: Turning Left")
    elif command == "right":
        print("Hardware: Turning Right")
    elif command == "stop":
        print("Hardware: Motors Stopped")
    elif command == "indicator_left":
        print("Hardware: Left Indicator Blinking")
    elif command == "indicator_right":
        print("Hardware: Right Indicator Blinking")
        
    return jsonify({"status": "success", "action": command})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)