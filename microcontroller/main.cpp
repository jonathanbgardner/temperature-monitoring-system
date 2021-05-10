// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include <stdio.h>


#include <fcntl.h>
#include <unistd.h>

#include "DHT.h"

#define DHTPIN A0     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

int lastEvent = 0;

void SerialRead(){
  String port = "/dev/ttyACM0";
}

void setup() {
  Serial.begin(9600); 
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index
  // Must send in temp in Fahrenheit!
  float hi = dht.computeHeatIndex(f, h);

  // Serial.print("%d %d %d %d", h, t, f, hi);
  
  // Serial.print("Humidity: "); 
  // Serial.print(h);
  // Serial.print(" %\t");
  // Serial.print("Temperature: "); 
  // Serial.print(t);
  // Serial.print(" *C ");
  // Serial.print(f);
  // Serial.print(" *F\t");
  // Serial.print("Heat index: ");
  // Serial.print(hi);
  // Serial.println(" *F");

  String data = String(h) + " " + String(t) + " " + String(f) + " " + String(hi) + "\n";
  Serial.print(data);
  delay(1000);
  Serial.flush();
}