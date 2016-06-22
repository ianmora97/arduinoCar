/*
Proyect Arduino Car with solar panel

*/
int motorPin = 11;
int motor2 =10;
int ledR =12;
int ledG=13;
int pinLed1 = 2;

const int pinSensor2=A2;
const int pinSensor = A1;
int valorPotenciometro = 0;
int valorPotenciometro2=0;
int motorVel = 0;
int motor2Vel=0;

int pinLDR = A0;
int valorLDR = 0;  

void beep(unsigned char delayms){
  analogWrite(9, 4);  
  delay(delayms);      
  analogWrite(9, 0);  
  delay(delayms);  
} 

void lightsRed(){
  digitalWrite(ledR,HIGH);
}
void ifMotor(){
  digitalWrite(motor2, LOW);
  
}
void setup() {
 pinMode(pinSensor, INPUT);
 pinMode(pinSensor2, INPUT);
 pinMode(9, OUTPUT);
 pinMode(ledR,OUTPUT);
 pinMode(ledG,OUTPUT);
 pinMode(pinLed1, OUTPUT);
 pinMode(motor2, OUTPUT);  
 pinMode(motorPin, OUTPUT);
 Serial.begin(9600);
}
void loop() {
  valorLDR= analogRead(pinLDR);
  //Serial.println(valorLDR);
  
  valorPotenciometro = analogRead(pinSensor);
  motorVel = map(valorPotenciometro, 0, 1023, 0, 255);
  analogWrite(motorPin, motorVel);
  
  valorPotenciometro2 = analogRead(pinSensor2);
  motor2Vel = map(valorPotenciometro2, 0, 1023, 0, 255);
  analogWrite(motor2, motor2Vel);
  
  
  /*Serial.print("Motor 2 ");
  Serial.print(motor2Vel);
  Serial.print("     Motor 1 ");
  Serial.println(motorVel);
  */
  Serial.println(valorLDR);
  digitalWrite(pinLed1,HIGH);
  digitalWrite(ledG,HIGH);
  digitalWrite(ledR,LOW);
  
 if(valorLDR < 300){
    beep(1000);
  }
  
  if(valorLDR > 300){
    digitalWrite(ledG,LOW);
    ifMotor();
    lightsRed();
    beep(5000);
  }
  
  //El delay del beep tiene que estar despues de los motores y cualquier otra cosa
  //que tenga antes 
 
}
