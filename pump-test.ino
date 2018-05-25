// set all moisture sensors PIN ID
int moisture1 = A0;
int moisture2 = A1;
int moisture3 = A2;
int moisture4 = A3;

// declare moisture values
int moisture1_value = 0;
int moisture2_value = 0;
int moisture3_value = 0;
int moisture4_value = 0;

// set water relays
int relay1 = 3;
int relay2 = 4;
int relay3 = 5;
int relay4 = 6;

// set water pump
int pump = 2;

void setup() {
  // declare relay as output
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  // declare pump as output
  pinMode(pump, OUTPUT);
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);  
}

void loop() {
int r=0;
 Serial.print(r);
for (int r=1;r<5;r++){
// go each switch and turn them off
 digitalWrite(relay1, LOW);
 digitalWrite(relay2, LOW);
 digitalWrite(relay3, LOW);
 digitalWrite(relay4, LOW); 

 Serial.print(r);
if (1){ 
if (r==1){
    digitalWrite(relay1, HIGH);
  }
  else if(r==2){
    digitalWrite(relay2, HIGH);
  }
  else if(r==3){
    digitalWrite(relay3, HIGH);
  }
  else if (r==4){
    digitalWrite(relay4, HIGH);
  }
   // let it water the plant for 5 seconds
   
   digitalWrite(pump, HIGH);
   delay(300);
   // turn the pump off
   digitalWrite(pump, LOW);
   delay(500);
}
}
}
