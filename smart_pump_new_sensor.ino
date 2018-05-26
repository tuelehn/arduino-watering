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
const int relay1 = 3;
const int relay2 = 4;
const int relay3 = 5;
const int relay4 = 6;

int thres = 450;
// wait in minutes between checks
float waitInMin = 180;//60.0 * 6;
float interval = 1000.0 * 60 * waitInMin;
float waterInSec = 5;

// set water pump
int pump = 2;

// For timing
unsigned long previousMillis = 0;

void setup() {
  // declare relay as output
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  // declare pump as output
  pinMode(pump, OUTPUT);

  Serial.begin(9600);
  Serial.println("------------------");
  Serial.println("INIT ...");
  previousMillis = -interval - 1000;
}

void loop() {
  unsigned long currentMillis = millis();
  //Serial.println("------------------");
  //Serial.println("In loop ...");
  //Serial.print(currentMillis);
  //Serial.print(" ");
  //Serial.println(previousMillis);
  // wait given time (in minutes) and repeat the process

  // previous mille starts blow "interval" to ensure a run at start up 
  if (currentMillis - previousMillis >= interval) {
  //if(1){  
    Serial.println("------------------");
    Serial.println("Start ...");
    previousMillis = currentMillis;

    int runCheck = 1;
    // check if plants needs water, if they do keep checking if they got sufficient
    while (runCheck > 0) {
      runCheck = run_watering();
      Serial.println("D------------------");
      Serial.println(runCheck);
      if (runCheck) {
        Serial.println("d------------------");
        Serial.println("Let water sink in ...");
        delay(5000);
      }
    }
  }
}

int run_watering() {
  int neededWater;
  Serial.println("c1------------------");
  // read the value from the moisture sensors:
  moisture1_value = analogRead(moisture1);
  moisture2_value = analogRead(moisture2);
  moisture3_value = analogRead(moisture3);
  moisture4_value = analogRead(moisture4);
  // Other sensor type for senor 4, 
  //moisture4_value = 500 - moisture4_value;

  Serial.println("c2------------------");
  Serial.println(moisture1_value);
  Serial.println(moisture2_value);
  Serial.println(moisture3_value);
  Serial.println(moisture4_value);
  Serial.println("c3------------------");
  // check which plant need water
  // if so run the watering function
  neededWater = 0;
//For debug below uncomentng below lines will bypass the waering nd just dislay sensor values
//return 1;
//  }
  
//  int dummy(){
//  int neededWater = 1;

  if (moisture1_value < thres) {
    Serial.println("b1------------------");
    Serial.println("Plant 1");
    water(relay1);
    neededWater = 1;
  }
  if (moisture2_value < thres) {
    Serial.println("b2------------------");
    Serial.println("Plant 2");
    water(relay2);
    neededWater = 1;
  }
  if (moisture3_value < thres) {
    Serial.println("b3------------------");
    Serial.println("Plant 3");
    water(relay3);
    neededWater = 1;
  }
  if (moisture4_value < thres) {
    Serial.println("b4a------------------");
    neededWater = 1;
    Serial.println("b4b------------------");
    Serial.println("Plant 4a");
    water(relay4);
    Serial.println("Plant 4b");
  }
  Serial.flush();
  Serial.println("A1------------------");
  //Serial.println(neededWater);
  Serial.println("A2------------------");

  return neededWater;

}

void water(int rel) {
  Serial.println("W1a------------------");
  //turn switch on
  digitalWrite(rel, HIGH);
  Serial.println("W1b------------------");
  //turn pump on
  digitalWrite(pump, HIGH);
  Serial.println("W1c------------------");
  // water for the given number of seconds
  delay(1000.0 * waterInSec);
  //delay(2000);
  Serial.println("W1d------------------");
  // turn the pump off
  digitalWrite(pump, LOW);
  Serial.println("W1e------------------");
  // turn switch off
  digitalWrite(rel, LOW);
  Serial.println("W2------------------");
  return;
}


