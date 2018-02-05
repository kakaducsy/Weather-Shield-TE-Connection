#include "TEWeatherShield.h"

TEWeatherShield::TEWeatherShield(void) {}

void TEWeatherShield::begin(void) {
  selectSensor(Sensor_NONE);

  HTU21D.begin();
  MS5637.begin();
  MS8607.begin();
  TSYS01.begin();
  TSD305.begin();
}

void TEWeatherShield::selectSensor(enum TEWeatherShield_Sensor sensor) {
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  delay(1200);
  switch (sensor) {
  case Sensor_HTU21D:
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(500);
    break;
  case Sensor_MS5637:
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(500);
    break;
  case Sensor_MS8607:
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(500);
    break;
  case Sensor_TSYS01:
    digitalWrite(14, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(500);
    break;
  case Sensor_TSD305:
    digitalWrite(14, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    delay(500);
    break;
  case Sensor_NONE:
    digitalWrite(14, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    break;
  }
}

void TEWeatherShield::selectHTU21D() { selectSensor(Sensor_HTU21D); }

void TEWeatherShield::selectMS5637() { selectSensor(Sensor_MS5637); }

void TEWeatherShield::selectMS8607() { selectSensor(Sensor_MS8607); }

void TEWeatherShield::selectTSYS01() { selectSensor(Sensor_TSYS01); }

void TEWeatherShield::selectTSD305() { selectSensor(Sensor_TSD305); }

void TEWeatherShield::measure_htu21d(float &t,float &h) {
  float temperature;
  float humidity;    
  selectHTU21D();
  delay(50);
  for(int i=0;i<5;i++)
  { 
    if (HTU21D.is_connected())
    {
      break;
    }
  }
  if (HTU21D.is_connected()) {
    HTU21D.set_i2c_master_mode(htu21_i2c_no_hold);       
    HTU21D.read_temperature_and_relative_humidity(&temperature, &humidity); 
    t=temperature;
    h=humidity;
  }
  else {
    Serial.println("HTU21D is disconnected");
  }
}
void TEWeatherShield::measure_tsd305(float &t,float &o) {
  float temperature;
  float object_temperature;    
  selectTSD305();
  delay(50);
    for(int i=0;i<5;i++)
  { 
    if (TSD305.is_connected())
    {
      break;
    }
  }
  if (TSD305.is_connected()) {    
    TSD305.read_temperature_and_object_temperature(&temperature, &object_temperature);
    t=temperature;
    o=object_temperature;
  }
  else {
    Serial.println("TSD305 is disconnected");
  }
}
void TEWeatherShield::measure_tsys01(float &t) {
  float temperature;    
  selectTSYS01();
  delay(50);
  for(int i=0;i<5;i++)
  { 
    if (TSYS01.is_connected())
    {
      break;
    }
  }
  if (TSYS01.is_connected()) {    
    TSYS01.read_temperature(&temperature);
    t=temperature;
  }
  else {
    Serial.println("TSYS01 is disconnected");
  }
}
void TEWeatherShield::measure_ms5637(float &t,float &p) {
  float temperature;
  float pressure;   
  selectMS5637();
  delay(50);
  for(int i=0;i<5;i++)
  { 
    if (MS5637.is_connected())
    {
      break;
    }
  }
  if (MS5637.is_connected()) {    
    MS5637.read_temperature_and_pressure(&temperature, &pressure);
    t=temperature;
    p=pressure;
  }
  else {
    Serial.println("MS5637 is disconnected");
  }
}

void TEWeatherShield::measure_ms8607(float &t,float &p,float &h) {
  float temperature;
  float pressure;
  float humidity;   
  selectMS8607();
  delay(50);
  for(int i=0;i<5;i++)
  { 
    if (MS8607.is_connected())
    {
      break;
    }
  }
  if (MS8607.is_connected()) {    
    MS8607.set_humidity_i2c_master_mode(ms8607_i2c_hold); 
    MS8607.read_temperature_pressure_humidity( &temperature, &pressure, &humidity);
    t=temperature;
    p=pressure;
    h=humidity;
  }
  else {
    Serial.println("MS8607 is disconnected");
  }
}
