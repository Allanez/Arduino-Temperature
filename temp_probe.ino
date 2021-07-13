#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

//initialize variables
float Celcius=0;
float Fahrenheit=0;
void setup(void)
{
  
  Serial.begin(9600);
  sensors.begin();
}

void loop(void)
{ 
  //read sensor
  sensors.requestTemperatures();
  delay(1000);
  //Get celsuis reading
  Celcius=sensors.getTempCByIndex(0);
  //Convert to fahrenheit
  Fahrenheit=sensors.toFahrenheit(Celcius);
  //Print values
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  
}
