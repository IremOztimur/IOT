
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
