//Tech Trends Shameer
//Control LED Using Blynk 2.0/Blynk IOT

//#define BLYNK_TEMPLATE_ID "TMPL4IBitIwh"
//#define BLYNK_DEVICE_NAME "led"
//#define BLYNK_AUTH_TOKEN "CWI8cdxBZ3q5vxPX_BYo0Uedftt6Dn6Z"

/*
 * #define BLYNK_TEMPLATE_ID "TMPLqaipdcQV"
#define BLYNK_DEVICE_NAME "IOT E CARE HAERT"
#define BLYNK_AUTH_TOKEN "t-nxa6-W8pqnKSEHiymMAurl9ITElcES"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "A";  // Enter your Wifi Username
char pass[] = "1234567890";  // Enter your Wifi password
////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
*/
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define REPORTING_PERIOD_MS     1000
PulseOximeter pox;
unsigned int move_index = 1;
uint32_t tsLastReport = 0;
////////////////////////////////////////////////////////////////////////////////////////////////
void onBeatDetected()
{
    Serial.println("Beat!");
}


//////////////////////////////////////////////////////////////////////////////////////// 
void setup()
{     
  Serial.begin(115200);
 
 //    gpsSerial.begin(GPSBaud); 
    Serial.print("Initializing pulse oximeter..");
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
     
        pox.setOnBeatDetectedCallback(onBeatDetected);

        // Blynk.begin(auth, ssid, pass);   
}




//////////////////////////////////////////////////////////////////////////////////////////



void loop()
{

  heartbeat();
 // Blynk.run();
 
}


////////////////////////////////////////////////////////////////////////////
void heartbeat(){
    // Make sure to call update as fast as possible
    pox.update();

    // Asynchronously dump heart rate and oxidation levels to the serial
    // For both, a value of 0 means "invalid"
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("Heart rate:");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2:");
        Serial.print(pox.getSpO2());
        Serial.println("%");
        tsLastReport = millis();
       //  Blynk.virtualWrite(V0,pox.getHeartRate());
    }
  
  
  }
