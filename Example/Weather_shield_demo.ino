#include "TEWeatherShield.h"
static TEWeatherShield weatherShield;
float t;
float h;
float p;
float t_o;
void setup() {
  Serial.begin(115200);
  Serial.println("TE Connectivity Sensor Solutions");
  Serial.println("==== Arduino Weather Shield ===="); 
  Serial.println();
  weatherShield.begin();
}

void loop() {            
  weatherShield.measure_ms5637(t,p);
    Serial.println("============ MS5637 ============"); 
    Serial.print("- Temperature : ");
    Serial.print(t, 1);
    Serial.print((char)176);
    Serial.println("C");
    Serial.print("- Pressure : ");
    Serial.print(p, 1);
    Serial.println (" hPa");
    Serial.println();
  weatherShield.measure_ms8607(t,p,h);
    Serial.println("============ MS8607 ============"); 
    Serial.print("- Tempeature : ");
    Serial.print(t);
    Serial.print((char)176);
    Serial.println("C");
    Serial.print("- Pressure : ");
    Serial.print(p);
    Serial.println(" hPa");
    Serial.print("- Humidity : ");
    Serial.print(h);
    Serial.println("%RH");
    Serial.println();
  weatherShield.measure_tsys01(t);
    Serial.println("============ TSYS01 ============");
    Serial.print("- Temperature : ");
    Serial.print(t, 1);
    Serial.print((char)176);
    Serial.println("C");
    Serial.println();
  weatherShield.measure_tsd305(t,t_o);
    Serial.println("============ TSD305 ============");
    Serial.print("- Temperature : ");
    Serial.print(t, 1);
    Serial.print((char)176);
    Serial.println("C");
    Serial.print("- Object Temperature : ");
    Serial.print(t_o,1);
    Serial.print((char)176);
    Serial.println("C");
    Serial.println();
  weatherShield.measure_htu21d(t,h);
    Serial.println("============ HTU21D ============");
    Serial.print("- Temperature : ");
    Serial.print(t, 1);
    Serial.print((char)176);
    Serial.println("C");
    Serial.print("- Humidity : ");
    Serial.print(h, 1);
    Serial.println(" %RH");
    Serial.println();
  delay(500); 
  Serial.println("================================");
}
