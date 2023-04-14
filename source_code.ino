char t;

int LED = 9;
int LDRInput = A0; // setting analog input A0 

int trigger_pin = 7; 
int echo_pin = 8;
 
void setup() {
pinMode(13,OUTPUT);   // left side motors forward
pinMode(12,OUTPUT);   // left side mototrs backward
pinMode(11,OUTPUT);   // right side motors forward
pinMode(10,OUTPUT);   // right side motors backward
pinMode(LED,OUTPUT);    
Serial.begin(9600);

pinMode(LDRInput,INPUT);
pinMode(LED,OUTPUT);

pinMode(trigger_pin, OUTPUT); 
pinMode(echo_pin, INPUT);
}
 
void loop() {

int duration, distance; 
digitalWrite(trigger_pin, HIGH); //triggers the signal
delay(10);
digitalWrite(trigger_pin, LOW);
duration = pulseIn(echo_pin, HIGH); //listens and waits for return signal
distance = (duration/2) / 29.1;

if (distance < 100){
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
  delay(100);
}
else {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            // forward
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
}
 
else if(t == 'B'){      // backward
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
}
  
else if(t == 'L'){      // left 
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(10,LOW);
  digitalWrite(13,LOW);
}
 
else  if(t == 'R'){      // right 
  digitalWrite(13,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(10,LOW);
}

else if(t ==  'W'){    // light control
  digitalWrite(9,HIGH);
}
else if(t == 'w'){
  digitalWrite(9,LOW);
}
 
else if(t == 'S'){      // break
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}

int value=analogRead(LDRInput);// reads the ldr value 
if(value<300)
  {
    digitalWrite(LED,HIGH);// lights on at dark
  }
  else
  {
    digitalWrite(LED,LOW);// lights off during day
  }
//Serial.println(value);
// analogWrite(enb, 255);
}
delay(100);
}
