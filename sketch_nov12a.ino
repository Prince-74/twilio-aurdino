#include <WiFi.h>
#include <HTTPClient.h>

// Wi-Fi credentials
const char* ssid = ; // your ssid
const char* password = ; // your password

// Server URL
const char* serverName = "http://190.000.000.108:3000/full-bin";  // Change to your Node.js server IP

// Define Ultrasonic Sensor pins
#define TRIG_PIN 5
#define ECHO_PIN 18

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Connect to Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = (duration * 0.0343) / 2;
  return distance;
}

void sendNotification() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST("{\"status\":\"full\"}");
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}

void loop() {
  long distance = measureDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 10) {  // Threshold for a "full" bin
    sendNotification();
    delay(60000);  // Wait to avoid duplicate notifications
  }
  delay(1000);
}
