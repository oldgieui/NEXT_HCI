int RED = 9; 
int YELLOW = 6;
int GREEN = 3;

void setup(){ 
  pinMode(RED, OUTPUT); 
  pinMode(YELLOW, OUTPUT); 
  pinMode(GREEN, OUTPUT); 
}

void loop(){ 
  digitalWrite(RED,HIGH); 
  digitalWrite(GREEN,LOW);
  delay(1500); 
  digitalWrite(YELLOW,HIGH); 
  digitalWrite(RED,LOW);
  delay(1500);
  digitalWrite(GREEN,HIGH); 
  digitalWrite(YELLOW,LOW);
  delay(3000);
}



