#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Count=4; //initial COunt
int IR1= 10;
int IR2 = 9;

    bool Flag1 = HIGH;
    bool Flag2 = HIGH;

void setup() {
    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);
    lcd.begin(16, 2);
    lcd.print("#People inside:=");  
}

void loop() {
    bool S_P_IR1=digitalRead(IR1);
    bool S_P_IR2=digitalRead(IR2);
    
    if(S_P_IR1==LOW && S_P_IR2==HIGH && Flag1==HIGH){
      Count=Count+1; 
      //Flag1=LOW;
      Flag2=LOW;
    }
    else if(S_P_IR2==LOW && S_P_IR1==HIGH && Flag2==HIGH){
      Count=Count-1; 
      Flag1=LOW;
      //Flag2=LOW;
    }
    if(S_P_IR1==HIGH && S_P_IR2==HIGH){
        Flag1=HIGH;
        Flag2=HIGH;
      }
  lcd.setCursor(0, 1);
  lcd.print(Count);
  delay(700); //Dependent on speed of walking 
}
 
