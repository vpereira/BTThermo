#include <SoftwareSerial.h>

int sensorPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
 
 
#define BT_TX 13
#define BT_RX 2
 
 
void setup()
{
  Serial.begin(38400);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
  pinMode(BT_RX,INPUT);
  pinMode(BT_TX,OUTPUT);
}


float getVoltage()
{
     //getting the voltage reading from the temperature sensor
     int reading = analogRead(sensorPin);  
 
     // converting that reading to voltage, for 3.3v arduino use 3.3
     float voltage = reading * 5.0;
     voltage /= 1024.0; 
 
     // now print out the temperature
       //converting from 10 mv per degree wit 500 mV offset
    return( (voltage - 0.5) * 100);
}


void loop()                     // run over and over again
{ 
  if(Serial.available()){
    float temperatureC = getVoltage();
    Serial.println(temperatureC,2);
  }
  delay(10000);                                     
}
