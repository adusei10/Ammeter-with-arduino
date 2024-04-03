#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int analogInput=A0;
float vout=0.0; // voltage across R1
float vin=0.0; // input voltage
float R1=10000; 
float R2=1000;
int value=0;
float i=0.00000000000;
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.init();
  lcd.backlight();
pinMode(analogInput,INPUT);

}

void loop() {
  lcd.setCursor(1,1);
  // put your main code here, to run repeatedly:
value=analogRead(analogInput);
vout =(value*5)/1024.0;  
vin= vout / (R2/(R1+R2) );

i=vin/(R1+R2);

lcd.print("CURRENT:");
lcd.print(i*1/10000);
//lcd.print("");

delay(500);

}
