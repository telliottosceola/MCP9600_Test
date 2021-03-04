#include <Arduino.h>
#include <MCP9600.h>
#include <Wire.h>

ThermoCouple tempSens;
String temperature;
int a;

void setup() {
  Wire.setClock(50000);
  Wire.begin();
  Serial.begin(115200);
  a = tempSens.discover();
  if(tempSens.init(a)){
    Serial.println("Thermocouple init success");
  }else{
    Serial.println("Thermocouple init failed");
  }
}

void loop() {
  tempSens.init(a);
  temperature = String(tempSens.readTemp());
  Serial.print("Temperature = "+temperature);
  delay(5000);
}
