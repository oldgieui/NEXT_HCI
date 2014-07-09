int TOP = 7;
int TOP_LEFT = 6;
int MIDDLE = 5;
int BOTTOM_LEFT = 4;
int BOTTOM = 3;
int TOP_RIGHT = 2;
int BOTTOM_RIGHT = 8;

int msg;

void setup(){ 
  pinMode(TOP, OUTPUT); 
  pinMode(TOP_LEFT, OUTPUT); 
  pinMode(MIDDLE, OUTPUT);
  pinMode(BOTTOM_LEFT, OUTPUT);
  pinMode(BOTTOM, OUTPUT);
  pinMode(TOP_RIGHT, OUTPUT); 
  pinMode(BOTTOM_RIGHT, OUTPUT); 
  Serial.begin(9600);
}

void loop(){ 
  if(Serial.available()){
    msg = Serial.read();
    if (msg == '0'){
      digitalWrite(TOP,HIGH); 
      digitalWrite(TOP_LEFT,HIGH); 
      digitalWrite(MIDDLE,LOW); 
      digitalWrite(BOTTOM_LEFT,HIGH); 
      digitalWrite(BOTTOM,HIGH); 
      digitalWrite(TOP_RIGHT,HIGH); 
      digitalWrite(BOTTOM_RIGHT, HIGH);
    }
    else if (msg == '1'){
      digitalWrite(TOP,LOW); 
      digitalWrite(TOP_LEFT,LOW); 
      digitalWrite(MIDDLE,LOW); 
      digitalWrite(BOTTOM_LEFT,LOW); 
      digitalWrite(BOTTOM,LOW); 
      digitalWrite(TOP_RIGHT,HIGH); 
      digitalWrite(BOTTOM_RIGHT, HIGH);
    }
    else if (msg == '2'){
      digitalWrite(TOP,HIGH); 
      digitalWrite(TOP_LEFT,LOW); 
      digitalWrite(MIDDLE,HIGH); 
      digitalWrite(BOTTOM_LEFT,HIGH); 
      digitalWrite(BOTTOM,HIGH); 
      digitalWrite(TOP_RIGHT,HIGH); 
      digitalWrite(BOTTOM_RIGHT, LOW);
    }
    else if (msg == '3'){
      digitalWrite(TOP,HIGH); 
      digitalWrite(TOP_LEFT,LOW); 
      digitalWrite(MIDDLE,HIGH); 
      digitalWrite(BOTTOM_LEFT,LOW); 
      digitalWrite(BOTTOM,HIGH); 
      digitalWrite(TOP_RIGHT,HIGH); 
      digitalWrite(BOTTOM_RIGHT, HIGH);
    }
    else if (msg == '4'){
      digitalWrite(TOP,LOW); 
      digitalWrite(TOP_LEFT,HIGH); 
      digitalWrite(MIDDLE,HIGH); 
      digitalWrite(BOTTOM_LEFT,LOW); 
      digitalWrite(BOTTOM,LOW); 
      digitalWrite(TOP_RIGHT,HIGH); 
      digitalWrite(BOTTOM_RIGHT, HIGH);
    }
    else if (msg == '5'){
      digitalWrite(TOP,HIGH); 
      digitalWrite(TOP_LEFT,HIGH); 
      digitalWrite(MIDDLE,HIGH); 
      digitalWrite(BOTTOM_LEFT,LOW); 
      digitalWrite(BOTTOM,HIGH); 
      digitalWrite(TOP_RIGHT,LOW); 
      digitalWrite(BOTTOM_RIGHT, HIGH);
    }
    else if (msg == '6'){
      digitalWrite(TOP,HIGH); 
      digitalWrite(TOP_LEFT,HIGH); 
      digitalWrite(MIDDLE,HIGH); 
      digitalWrite(BOTTOM_LEFT,HIGH); 
      digitalWrite(BOTTOM,HIGH); 
      digitalWrite(TOP_RIGHT,LOW); 
      digitalWrite(BOTTOM_RIGHT, HIGH);
    }
    else if (msg == '7'){
      digitalWrite(TOP,HIGH); 
      digitalWrite(TOP_LEFT,HIGH); 
      digitalWrite(MIDDLE,LOW); 
      digitalWrite(BOTTOM_LEFT,LOW); 
      digitalWrite(BOTTOM,LOW); 
      digitalWrite(TOP_RIGHT,HIGH); 
      digitalWrite(BOTTOM_RIGHT, HIGH);
    }
    else if (msg == '8'){
      digitalWrite(TOP,HIGH); 
      digitalWrite(TOP_LEFT,HIGH); 
      digitalWrite(MIDDLE,HIGH); 
      digitalWrite(BOTTOM_LEFT,HIGH); 
      digitalWrite(BOTTOM,HIGH); 
      digitalWrite(TOP_RIGHT,HIGH); 
      digitalWrite(BOTTOM_RIGHT, HIGH);
    }
    else if (msg == '9'){
      digitalWrite(TOP,HIGH); 
      digitalWrite(TOP_LEFT,HIGH); 
      digitalWrite(MIDDLE,HIGH); 
      digitalWrite(BOTTOM_LEFT,LOW); 
      digitalWrite(BOTTOM,HIGH); 
      digitalWrite(TOP_RIGHT,HIGH); 
      digitalWrite(BOTTOM_RIGHT, HIGH);
    }
    else{
      digitalWrite(TOP,HIGH); 
      digitalWrite(TOP_LEFT,HIGH); 
      digitalWrite(MIDDLE,HIGH); 
      digitalWrite(BOTTOM_LEFT,HIGH); 
      digitalWrite(BOTTOM,HIGH); 
      digitalWrite(TOP_RIGHT,LOW); 
      digitalWrite(BOTTOM_RIGHT,LOW);
    }
  }
}











