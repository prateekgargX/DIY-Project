#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Count=4; //initial COunt
int IR1= 10;
int IR2 = 9;

bool S_P_IR1 = HIGH;
bool S_P_IR2 = HIGH;
bool S_PA_IR1 = HIGH;
bool S_PA_IR2 = HIGH;

void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  lcd.begin(16, 2);
  lcd.print("#People inside:=");
}

void loop() {
  	S_P_IR1=digitalRead(IR1);
  	S_P_IR2=digitalRead(IR2);
  if( S_P_IR1!=S_PA_IR1 || S_P_IR2!=S_PA_IR2){
  	if(S_P_IR1==HIGH && S_P_IR2==LOW ) Count++;
    if(S_P_IR2==HIGH && S_P_IR1==LOW ) Count--;
  }
  lcd.setCursor(0, 1);
  lcd.print(Count);
  S_PA_IR1=S_P_IR1;
  S_PA_IR2=S_P_IR2;
  
}
 
