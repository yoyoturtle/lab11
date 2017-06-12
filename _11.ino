#include <MsTimer2.h>
#include <LiquidCrystal.h> // include the library code
LiquidCrystal lcd(12, 7, 5, 4, 3, 2); // initialize interface pins
 char n[7]="100000";
void flash() {
 int i=0;
 while(Serial.available())
 {
  
   n[i++] = Serial.read();
  }
 //*******************************************************
   if(n[0]=='0'&&n[1]=='0'&&n[2]=='0'&&n[3]=='0'&&n[4]=='0'&&n[5]=='0')
    {
      digitalWrite(13, HIGH);
     }
   else if(n[5]!='0')
   {
   n[5]--;  
   }
   else if(n[5]=='0'&&n[4]!='0')
   {
   n[4]--; n[5]='9';
  }
  else if(n[5]=='0'&&n[4]=='0'&&n[3]!='0')  
   {
   n[3]--;n[4]='5'; n[5]='9';
  }
   else if(n[5]=='0'&&n[4]=='0'&&n[3]=='0'&&n[2]!='0')  
   {
   n[2]--; n[3]='9';n[4]='5'; n[5]='9';
  }
  else if(n[5]=='0'&&n[4]=='0'&&n[3]=='0'&&n[2]=='0'&&n[1]!='0')  
   {
   n[1]--; n[2]='5';n[3]='9';n[4]='5'; n[5]='9';
  }
  else if(n[5]=='0'&&n[4]=='0'&&n[3]=='0'&&n[2]=='0'&&n[1]=='0'&&n[0]!='0')  
   {
   n[0]--; n[1]='9'; n[2]='5';n[3]='9';n[4]='5'; n[5]='9';
  }
  Serial.write(n);
  Serial.println();
  lcd.setCursor(0, 1);
   lcd.write(n[0]); 
    lcd.write(n[1]); 
    lcd.write(":");
    lcd.write(n[2]); 
    lcd.write(n[3]); 
    lcd.write(":");
    lcd.write(n[4]); 
    lcd.write(n[5]); 

 
}

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  MsTimer2::set(1000, flash);
  MsTimer2::start();
  lcd.begin(20, 2);
}
void loop() {
 
}
