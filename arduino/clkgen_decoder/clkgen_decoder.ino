int outPort=13;
int lsb=A0;
int nsb=A1;
int msb=A2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(outPort,OUTPUT);
  pinMode(lsb, INPUT);
  pinMode(nsb, INPUT);
  pinMode(msb, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(outPort,HIGH);
  delay(500);
  digitalWrite(outPort,LOW);
  delay(500);
  int C2=analogRead(msb);
  int C5=1;
  if(C2<200){
    C5=0;
  }
  int C1=analogRead(nsb);
  int C4=1;
  if(C1<200){
    C4=0;
  }
  int C0=analogRead(lsb);
  int C3=1;
  if(C0<200){
    C3=0;
  }
  int decimal=0;
  if (C5==1){
    decimal=decimal+4;
  }
  if (C4==1){
    decimal=decimal+2;
  }
  if(C3==1){
    decimal=decimal+1;
  }
  Serial.print("Binary: ");
  Serial.print(C5);
  Serial.print(' ');
  Serial.print(C4);
  Serial.print(' ');
  Serial.print(C3);
  Serial.print(' ');
  Serial.print("Decimal: ");
  Serial.print(decimal);
  Serial.println(' ');
}
