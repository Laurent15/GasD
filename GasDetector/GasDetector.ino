//#include <DHT.h>
//#include <DHT_U.h>

// Project structure, refer to https://arduino.stackexchange.com/questions/348/how-to-organize-my-arduino-projects-structure-for-easy-source-control
//#include "DHTesp.h"

#define DHTPIN 2        // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22

DHTesp dht(DHTPIN, DHTTYPE);

void setup() {
  delay(5000);
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  
  dht.begin();
} 


void loop()
{
  delay(1000);
  float h = dht.readHumidity();        // read humidity
  float t = dht.readTemperature();     // read temperature

  if (isnan(h) || isnan(t)) 
  {
    int i =1;
    Serial.println(F("Failed to read from DHT sensor!"));
  }
  else
  {
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print(F(" Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(F("°Heat index: "));
    Serial.print(hic);
    Serial.println(F("°C "));
  }
}
