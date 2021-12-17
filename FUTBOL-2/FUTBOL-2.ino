//https://hetpro-store.com/TUTORIALES/bluetooth-hc-06-app-arduino/

#include <SoftwareSerial.h>
SoftwareSerial BT1(11,12); // RX, TX recorder que se cruzan

const int A1A = 4;//define pin 2 for A1A
const int A1B = 5;//define pin 3 for A1B

const int B1A = 2;//define pin 8 for B1A
const int B1B = 3;//define pin 9 for B1B

//bluetooth hc-06
int ledPin = LED_BUILTIN ; // usamos un pin de salida al LED
int state = 0; // Variable lectrura serial
int i=0;

void setup() {
    pinMode(ledPin, OUTPUT);   //Declara pin de Salida
    for(i=0;i<5;i++){
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
    
  pinMode(B1A,OUTPUT);// define pin as output
  pinMode(B1B,OUTPUT);
  
  pinMode(A1A,OUTPUT);
  pinMode(A1B,OUTPUT);
   
    Serial.begin(9600);
    BT1.begin(9600);
}
 
void loop() {
  if (BT1.available()){
    state=BT1.read();
    Serial.println(state);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
  }

  switch (state) {
  case 82:
    motorA('R');
    motorB('L');
    break;
  case 76:
    motorA('L');
    motorB('R');
    break;
  case 70:
    motorA('R');
    motorB('R');
    break;
  case 66:
    motorA('L');
    motorB('L');
    break;
  case 90:
    motorA('0');
    motorB('0');
    break;
  default:
    // statements
    break;
  }
  
  state=0;
/*
  motorA('R');// Turn motor A to RIGHT
  delay(100);
  motorA('L');// Turn motor A to LEFT
  delay(100);   
  motorA('O');// Turn motor A OFF
  delay(100); 
    
  motorB('R');// Turn motor B to RIGHT
  delay(100);
   motorB('L');// Turn motor B to LEFT
  delay(100); 
  motorB('O');// Turn motor B OFF
  delay(100);
   
  motorA('R');// Turn motor A to RIGHT
  motorB('R'); // Turn motor A to RIGHT 
  delay(100);
  motorA('L');// Turn motor A to LEFT
  motorB('L');// Turn motor B to LEFT     
  delay(100);
  motorA('O');// Turn motor A OFF
  motorB('O');// Turn motor B OFF
  delay(100);
  */
}

/*
 * @motorA
 * activation rotation of motor A
 * d is the direction
 * R = Right
 * L = Left
 */
void motorA(char d)
{
  if(d =='R'){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,HIGH); 
  }else if (d =='L'){
    digitalWrite(A1A,HIGH);
    digitalWrite(A1B,LOW);    
  }else{
    //Robojax.com L9110 Motor Tutorial
    // Turn motor OFF
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,LOW);    
  }
}// motorA end


/*
 * @motorB
 * activation rotation of motor B
 * d is the direction
 * R = Right
 * L = Left
 */
void motorB(char d)
{

    if(d =='R'){
      digitalWrite(B1A,LOW);
      digitalWrite(B1B,HIGH); 
    }else if(d =='L'){
      digitalWrite(B1A,HIGH);
      digitalWrite(B1B,LOW);    
    }else{
    //Robojax.com L9110 Motor Tutorial
    // Turn motor OFF      
      digitalWrite(B1A,LOW);
      digitalWrite(B1B,LOW);     
    }

}// motorB end
