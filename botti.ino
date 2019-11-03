/*     Arduino Color Sensing Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
#define S0 4
#define S1 7
#define S2 8
#define S3 12
#define sensorOut 13
#define button 10
#include <Servo.h>

Servo servoV; //stop=94//Fw>94//Rw<94
Servo servoO;//stop=98//Fw<98//Rw>98
int painallus = 0;
int frequency = 0;
int nappi = 0;
int onGreen = 0;
int reverse = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(button, INPUT);
  servoV.attach(5);
  servoO.attach(3);
  int arr[3];
  arr[0]=0;
  arr[1]=0;
  arr[2]=0;

  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);
}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 0,150,255,0);
  // Printing the value on the serial monitor
  int arr[3];
  if (frequency > 255){
    frequency = 255;
    }
  if (frequency < 0){
    frequency = 0;
    }
  arr[0]=frequency;
  delay(20);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 5,200,255,0);
  // Printing the value on the serial monitor
  if (frequency > 255){
    frequency = 255;
    }
  if (frequency < 0){
    frequency = 0;
    }
  arr[1]=frequency;
  delay(20);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 0,170,255,0);
  // Printing the value on the serial monitor
  if (frequency > 255){
    frequency = 255;
    }
  if (frequency < 0){
    frequency = 0;
    }
  arr[2]=frequency;
  digitalWrite(button, HIGH);
  nappi = digitalRead(button);
  reverse = reverse;
  delay(20);
  //Serial.print("R= ");
  //Serial.print(arr[0]);
  //Serial.print(" ");
  //Serial.print("G= ");
  //Serial.print(arr[1]);
  //Serial.print(" ");
  //Serial.print("B= ");
  //Serial.print(arr[2]);
  //Serial.print(" Reverse = ");
  //Serial.println(reverse);
  
  //PUNAINEN (kääntyy oikealle)
  if (arr[0] > 190 && arr[0] > arr[1] && arr[0] > arr[2] && reverse == 0){
    servoV.write(114);
    servoO.write(118);
  }
  //SININEN (kääntyy vasemmalle)
   else if (arr[2] > 195 && arr[2] > arr[1] && arr[2] > arr[0] && reverse == 0){
    servoV.write(89);
    servoO.write(78);
   }
   //PUNAINEN (REVERSED)
    else if (reverse == 1 && arr[0] > 195 && arr[0] > arr[1] && arr[0] > arr[2]){
      servoV.write(89);
      servoO.write(78);
    }
    //SININEN (REVERSED)
    else if (reverse == 1 && arr[2] > 190 && arr[2] > arr[1] && arr[2] > arr[0]){
      servoV.write(114);
      servoO.write(118);
    }
   //arr[1] > 200 && arr[1] > arr[0] && arr[1] > arr[2] && 
   //VIHREÄ+NAPPI = SEIS + PYÖRÄYTYS
   else if (arr[1] > 195 && arr[1] > arr[0] && arr[1] > arr[2] && nappi == 0){
    servoV.write(140);
    servoO.write(140);
    delay(665);
    servoV.write(140);
    servoO.write(40);
    //muuta tarvittaessa
    delay(150);
    onGreen = 0;
     reverse = (reverse  -1) * (-1);
     delay(100);
    }
    
    //VIHREÄ
    else if (arr[1] > 195 && arr[1] > arr[0] && arr[1] > arr[2]){
      servoV.write(94);
      servoO.write(98);
      onGreen = 1;
      delay(100);
    }
    else if (onGreen == 1){
      servoV.write(94);
      servoO.write(98);
      delay(100);         
    }
    else{
      
      servoV.write(120);
      servoO.write(70);
     }
}
  
