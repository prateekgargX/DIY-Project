int Count=4; //initial COunt
int IR1= 10;
int IR2 = 9;

    bool Flag1 = HIGH;
    bool Flag2 = HIGH;

void setup() {
    Serial.begin(9600);
    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);
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
  Serial.println("");
  Serial.print("No. of People inside = ");
  Serial.print(Count);
  delay(700); //Dependent on speed of walking 
}
 
