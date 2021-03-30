#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <SPI.h>




const int RST_PIN = (5);
const int SS_PIN = (4);

//56 116 65 49
// 180 57 179 

MFRC522 rfid(SS_PIN, RST_PIN);
const byte ID1[4] = {156, 116, 65, 49};
const byte ID2[4] = {0, 0, 0, 0};
const int red = (2);
const int grn = (0);
char auth[] = "7w5JHEp525mKELeYrfZ3pxvfvmBLUp27";
char ssid[] = "MeriRunzo";
char pass[] = "ifo0303.";




WidgetLCD lcd(V1);
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(red, OUTPUT);
  pinMode(grn, OUTPUT);
}
void loop() {
  Blynk.run();
  if ( ! rfid.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! rfid.PICC_ReadCardSerial())    {
    return;
  }
  if (rfid.uid.uidByte[0] == ID1[0] &&
    rfid.uid.uidByte[1] == ID1[1] &&
    rfid.uid.uidByte[2] == ID1[2] &&
    rfid.uid.uidByte[3] == ID1[3] ) {
    lcd.clear();
    lcd.print(0,0,"İyi Günler, ");
    lcd.print(0,1,"İrem Öztimur!");
    writeid();
    digitalWrite (grn, 1);
    digitalWrite (red, 0);
    delay (2500);
    digitalWrite (grn, 0);
    digitalWrite (red, 0);
    lcd.clear();
  }
  else if (rfid.uid.uidByte[0] == ID2[0] &&
    rfid.uid.uidByte[1] == ID2[1] &&
    rfid.uid.uidByte[2] == ID2[2] &&
    rfid.uid.uidByte[3] == ID2[3] ) {
    lcd.clear();
    lcd.print(0,0,"İyi Günler,");
    lcd.print(0,1,"Melisa Ural!");
    writeid();
    digitalWrite (grn, 1);
    digitalWrite (red, 0);
    delay (2500);
    digitalWrite (grn, 0);
    digitalWrite (red, 0);
    lcd.clear();
  }
  else {
    lcd.clear();
    lcd.print(0,0,"Bilinmeyen Kart  !");
    writeid();
    digitalWrite (grn, 0);
    digitalWrite (red, 1);
    delay (2500);
    digitalWrite (grn, 0);
    digitalWrite (red, 0);
    lcd.clear();
  }
  rfid.PICC_HaltA();
}

void writeid(){
  Serial.print("ID No: ");
  for(int cardid = 0; cardid < 4; cardid++){
    Serial.print(rfid.uid.uidByte[cardid]);
    Serial.print(" ");
  }
  Serial.println("");
}
