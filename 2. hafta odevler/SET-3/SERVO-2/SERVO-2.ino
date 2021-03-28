
#include <Servo.h>

Servo servo180;
Servo servo90;

const byte pot1 = A0;
const byte pot2 = A1;


int pot_deger1;
int pot_deger2;


void setup() {

Serial.begin(9600);
servo180.attach(9);
servo90.attach(11);

}


void loop() {
 pot_deger1 = analogRead(pot1);
 int yeni_deger1 = map(pot_deger1, 0, 1023, 0, 180);
 servo180.write(yeni_deger1);
 delay(15);


 pot_deger2 = analogRead(pot2);
 int yeni_deger2 = map(pot_deger2, 0, 1023, 0, 90);
 servo90.write(yeni_deger2);
 delay(15);
}
