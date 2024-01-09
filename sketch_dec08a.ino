#define BLYNK_TEMPLATE_ID "TMPL3AfhuGayK"
#define BLYNK_TEMPLATE_NAME "saline bottle"
#define BLYNK_AUTH_TOKEN "Z9OEQMRc0RqFOb_qVpnDXPBIQev_dxit"

#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "vivo 1811";  // type your wifi name
char pass[] = "sandhya naik";  // type your wifi password

int sensor1 = D2;
int sensor2 = D1;
int data1 = 0;
int data2 = 0;
int sensorThres = 100;


BlynkTimer timer;

void sendSensor()
{
 
 int data1 = digitalRead(sensor1);

 Blynk.virtualWrite(V0, data1);
  Serial.print("sensor: ");
  Serial.println(data1);


  int data2 = digitalRead(sensor2);

 Blynk.virtualWrite(V1, data2);
  Serial.print("sensor: ");
  Serial.println(data2);


   if (data2 == 1)
  {
    Blynk.logEvent("alert", "i need help patient bed NO 2");
  }
}

void setup(){
  pinMode(sensor1, INPUT);
   pinMode(sensor2, INPUT);
   Serial.begin(115200);
   timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
