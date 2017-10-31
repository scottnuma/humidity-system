
// Library may require installation under Sketch > Include Library > Manage Libraries...
#include "DHT.h"
#include <Servo.h>

int POTENTIOMETER_PIN = A0;
int SENSOR_PIN = 10;
int SENSOR_TYPE = DHT22;

int SERVO_PIN = 9;

// servo angle to activate vent
int ON_THETA = 120;

// servo angle to deactivate vent
int OFF_THETA = 70;

// middle servo angle for netural
int MIDDLE_THETA = 90;

// amount of time necessary for servo to move
int ACTION_DELAY = 300;

DHT dht(SENSOR_PIN, SENSOR_TYPE);
Servo servo;
boolean ventOn;

void setup() {
  dht.begin();
  activateVent();
  deactivateVent();
  Serial.begin(9600);
}

void loop() {
  float threshold = humidityThreshold();
  float humidity = readHumidity();
  Serial.print("Threshold: ");
  Serial.println(threshold);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  if (humidity > threshold && !ventOn) {
    activateVent();
  } else if (humidity < threshold && ventOn) {
    deactivateVent();
  }
  delay(2000);
}

/**
 * Turn on vent
 */
void activateVent() {
  servo.attach(SERVO_PIN);
  servo.write(ON_THETA);
  delay(ACTION_DELAY);
  servo.write(MIDDLE_THETA);
  delay(ACTION_DELAY);
  servo.detach();
  ventOn = true;
}

/**
 * Turn off vent
 */
void deactivateVent() {
  servo.attach(SERVO_PIN);
  servo.write(OFF_THETA);
  delay(ACTION_DELAY);
  servo.write(MIDDLE_THETA);
  delay(ACTION_DELAY);
  servo.detach();
  ventOn = false;
}

float humidityThreshold() {
  return readDial();
}
/**
 * Return a reading from the potentiometer
 * 
 * Return value is in [0,1).
 */
float readDial() {
  return analogRead(POTENTIOMETER_PIN) * (1.0/1023.0);
}

/**
 * Return the current humidity
 * 
 * Returns a value in [0,1)
 */
float readHumidity(){
  return dht.readHumidity() / 100.0;
}

/**
 * Return the current temperatue in Fahrenheit
 */
float readTemperature(){
  return dht.readTemperature(true);
}

