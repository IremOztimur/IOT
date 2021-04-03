/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "7w5JHEp525mKELeYrfZ3pxvfvmBLUp27";
char ssid[] = "MeriRunzo";
char pass[] = "ifo0303.";

#define ldr A0
WidgetLCD lcd(V6);


BLYNK_WRITE(V0)

{

  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

  analogWrite(D1,pinValue);

  Blynk.virtualWrite(V1, pinValue);

  Serial.print("V0 Slider value is: ");

  Serial.println(pinValue);

}


void setup()
{
  
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();

  int deger = analogRead(ldr);

  if(deger > 5)
  {
    lcd.print(0,0, "Işık Açık!!!");
    lcd.print(0,1, "Işığı Kapatınız.");
  }
  else
  {
    lcd.clear();
  }
}
