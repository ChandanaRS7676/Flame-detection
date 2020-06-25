#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "QkOcC4F8cWeZwTgwjaTnm0YN7djsGwrr"; //Auth code sent via Email
char ssid[] = "nayana"; //Wifi name
char pass[] = "sunilus9";  //Wifi Password
int flag=0;
void notifyOnFire()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==1 && flag==0) {
    Serial.println("Fire in the House");
    Blynk.notify("Alert : Fire in the House");
    Blynk.email("chandurschandu@gmail.com","{DEVICE_NAME}:Alarm","Your {DEVICE_NAME} has fire in it!"
    );
    flag=1;
  }
  else if (isButtonPressed==0)
  {
    flag=0;
  }
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(D1,INPUT_PULLUP);
timer.setInterval(1000L,notifyOnFire); 
}
void loop()
{
  Blynk.run();
  timer.run();
 }
