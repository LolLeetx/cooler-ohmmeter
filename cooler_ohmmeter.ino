#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int analogPin= 0;
int raw= 0;
int Vin= 5;
float Vout= 0;
float R1= 100000;// my resistor is 100kohm so can measure higher value
int R2= 0;
float buffer= 0;

void setup()
{
lcd.init();                   
lcd.init();
lcd.backlight();
Serial.begin(9600);
}

void loop()
{
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R2= R1 * buffer;
Serial.print("Vout: ");
Serial.println(Vout);
Serial.print("R2: ");
Serial.println(R2);
lcd.setCursor(0,0);
lcd.print("Ohmmeter");
lcd.setCursor(0,1);
lcd.print("Value:         ");
lcd.setCursor(6,1);
lcd.print(R2);
lcd.setCursor(15,1);
lcd.print("R");

delay(1000);
}
}
