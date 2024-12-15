  #Ultrasonic Sensor with SMS Alert System

This project integrates an ESP32 microcontroller with an ultrasonic sensor to measure the distance of an object and send an SMS alert via the Twilio API when the measured distance crosses a specific threshold (e.g., when a waste bin is full).

Features

Measure distances using an ultrasonic sensor (HC-SR04 or compatible).

Send SMS alerts using the Twilio API.

Use Express.js to handle the SMS request on a local server.

ESP32 communicates with the server to trigger the SMS alert.

Components Required

ESP32 (or ESP8266)

Ultrasonic Sensor (e.g., HC-SR04)

Jumper Wires

Breadboard (optional)

Wi-Fi Connection

Twilio Account (for SMS functionality)

Node.js and Express.js (for the backend server)

Circuit Diagram

Connect the VCC and GND of the ultrasonic sensor to the 3.3V (or 5V) and GND pins of the ESP32.

Connect the TRIG pin of the sensor to GPIO5 on the ESP32.

Connect the ECHO pin of the sensor to GPIO18 on the ESP32.

Software Requirements

Arduino IDE (for programming the ESP32)

Install the ESP32 board package.

Node.js

Install Express.js and Twilio modules.

Twilio Account

Get your Account SID, Auth Token, and a Twilio phone number.

Installation and Setup

ESP32 Code

Clone this repository.

Open the esp32-ultrasonic.ino file in the Arduino IDE.

Update the Wi-Fi credentials in the code:

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

Update the server IP address to match your local machine's IP:

const char* serverName = "http://YOUR_LOCAL_IP:3000/full-bin";

Upload the code to the ESP32.

Express.js Server

Navigate to the server folder in the repository.

Install dependencies:

npm install

Update Twilio credentials in server.js:

const accountSid = 'YOUR_TWILIO_ACCOUNT_SID';
const authToken = 'YOUR_TWILIO_AUTH_TOKEN';

Start the server:

node server.js

How It Works

The ultrasonic sensor measures the distance to an object.

If the distance is below a set threshold, the ESP32 sends a POST request to the Express.js server.

The server triggers the Twilio API to send an SMS alert to the specified recipient.

Testing

Open the Serial Monitor in the Arduino IDE to view distance measurements.

Use a tool like Postman or Hoppscotch to test the /full-bin endpoint manually.

Example Output

Serial Monitor

Ultrasonic Sensor Test Started
Distance: 12 cm
Distance: 8 cm  
Bin is full. Sending alert...

SMS Alert

Alert: The waste bin is full. Please empty it.

License

This project is licensed under the MIT License. Feel free to use, modify, and distribute it.

Happy coding!


