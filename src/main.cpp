#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

const int HUMIDITY_SENSOR = 1;
const int TEMPERATURE_SENSOR = 3;
const int RELAY_2 = 12;

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  // Humidity
  pinMode(HUMIDITY_SENSOR, OUTPUT);

  // Temperature
  pinMode(TEMPERATURE_SENSOR, OUTPUT);

  // Relay 2
  pinMode(RELAY_2, OUTPUT);
}

void loop() {
  Serial.print("HUMIDITY_SENSOR: ");
  Serial.println(analogRead(HUMIDITY_SENSOR));

  Serial.print("TEMPERATURE_SENSOR: ");
  Serial.println(analogRead(TEMPERATURE_SENSOR));

  // if (Serial.available() > 0) {
  //   char BluetoothAvailability = 0;
  //   BluetoothAvailability = Serial.read();

  //   if (BluetoothAvailability == 'A') {
  //     digitalWrite(LED_BUILTIN, HIGH);
  //   } else if (BluetoothAvailability == 'a') {
  //     digitalWrite(LED_BUILTIN, LOW);
  //   }
  // }

  while(Serial.available() > 0) {
    char BluetoothAvailability = 0;
    BluetoothAvailability = Serial.read();

    if (BluetoothAvailability == 'T') {
      // output temperature
      Serial.print("TEMPERATURE_SENSOR: ");
      Serial.println(analogRead(TEMPERATURE_SENSOR));
    } else if (BluetoothAvailability == 'H') {
      // output humidity
      Serial.print("HUMIDITY_SENSOR: ");
      Serial.println(analogRead(HUMIDITY_SENSOR));
    }
  }

  // if humidity is below 13% or temperature is below 29.5C, turn on pin 12 for 5 seconds, then turn off
  if (analogRead(HUMIDITY_SENSOR) < 13 || analogRead(TEMPERATURE_SENSOR) > 13) {
    digitalWrite(RELAY_2, HIGH);
  } else {
    digitalWrite(RELAY_2, LOW);
  }
}