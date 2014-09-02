/*
  NAVER Software Education Project(Arduino): Car Robot
 Copyright (C) 2014  Kyoungchin SEO, NHN NEXT
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//#include "Ultrasonic.h"

int MOTOR_A_DIR = 12;
int MOTOR_A_BRAKE = 9;
int MOTOR_A_PWM = 3;

int MOTOR_B_DIR = 13;
int MOTOR_B_BRAKE = 8;
int MOTOR_B_PWM = 11;

int MOTOR_SPEED = 255;
int delayTime = 300;

//Ultrasonic ultrasonic(7);

#define echoPin 7 // Echo Pin 
#define trigPin 4 // Trigger Pin

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed

long distance,duration;

char order;
boolean isBlocked = false;
boolean isSonarValid = false;

void setup() 
{
  Serial.begin(9600);

  pinMode(MOTOR_A_DIR,OUTPUT);
  pinMode(MOTOR_A_BRAKE, OUTPUT);  
  pinMode(MOTOR_B_DIR,OUTPUT);
  pinMode(MOTOR_B_BRAKE,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{  
  getDistance();
  //  Serial.println(distance);

  if(Serial.available()>0){
    order = Serial.read();
    if(order == 'w'){
      Serial.println("Go Forward");
      goForward();
    }
    else if(order == 's'){
      Serial.println("Go Backward");
      goBackward();
    }
    else if(order == 'a'){
      Serial.println("Turn Left");
      turnLeft();
    }
    else if(order == 'd'){
      Serial.println("Turn Right");
      turnRight();
    }
    else if(order == 'b'){
      Serial.println("Brake");
      brake();
    }
    else if(order == 'p'){
      Serial.println("Auto Pilot");
      autoPilot();
    }
    else if(order == 'c'){
      Serial.println("Let's Dance!");
      dance();
    }
  }
}

void getDistance() 
{
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound. 
  distance = duration/58.2;

  if(distance >= maximumRange || distance <= minimumRange){
    isSonarValid = false;
  }
  else{
    isSonarValid = true;
  }
  if (isSonarValid == false){ 
    Serial.println("I can't see well!");
  }

  if (distance < 15){
    isBlocked = true;
  }
  else{
    isBlocked = false;
  }
  if(isBlocked == true) {
    Serial.println("Something is in front of me.");
  } 

}

void goForward(){
  digitalWrite(MOTOR_A_DIR,HIGH);
  digitalWrite(MOTOR_A_BRAKE, LOW);
  analogWrite(MOTOR_A_PWM,MOTOR_SPEED);    
  digitalWrite(MOTOR_B_DIR,HIGH);
  digitalWrite(MOTOR_B_BRAKE,LOW);
  analogWrite(MOTOR_B_PWM,MOTOR_SPEED);
  delay(delayTime);
}

void goBackward(){
  digitalWrite(MOTOR_A_DIR,LOW);
  digitalWrite(MOTOR_A_BRAKE, LOW);
  analogWrite(MOTOR_A_PWM,MOTOR_SPEED);    
  digitalWrite(MOTOR_B_DIR,LOW);
  digitalWrite(MOTOR_B_BRAKE,LOW);
  analogWrite(MOTOR_B_PWM,MOTOR_SPEED);
  delay(delayTime);
}

void brake(){
  digitalWrite(MOTOR_A_BRAKE, HIGH);
  digitalWrite(MOTOR_B_BRAKE, HIGH);
  delay(delayTime);
}

void turnLeft(){
  //��ㅼ��濡���� MOTOR_B 諛⑺�μ�쇰�� ������
  digitalWrite(MOTOR_A_DIR,HIGH);
  digitalWrite(MOTOR_A_BRAKE, LOW);
  analogWrite(MOTOR_A_PWM,MOTOR_SPEED);    
  digitalWrite(MOTOR_B_DIR,LOW);
  digitalWrite(MOTOR_B_BRAKE,LOW);
  analogWrite(MOTOR_B_PWM,MOTOR_SPEED);
  delay(delayTime);
}

void turnRight(){
  //��ㅼ��濡���� MOTOR_A 諛⑺�μ�쇰�� ������
  digitalWrite(MOTOR_A_DIR,LOW);
  digitalWrite(MOTOR_A_BRAKE, LOW);
  analogWrite(MOTOR_A_PWM,MOTOR_SPEED);    
  digitalWrite(MOTOR_B_DIR,HIGH);
  digitalWrite(MOTOR_B_BRAKE,LOW);
  analogWrite(MOTOR_B_PWM,MOTOR_SPEED);
  delay(delayTime);
}

void dance(){
  turnLeft();
}

void autoPilot(){

  if (distance > 40) 
  {
    goForward();
  } 
  else if (distance < 10) 
  {
    brake();
  } 
  else 
  {      
    turnRight();
  }
}













