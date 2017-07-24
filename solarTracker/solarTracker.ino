int sensorPin0 = A0; // select the input pin for LDR
int sensorPin1 = A1; 
int sensorPin2 = A2; 
int sensorValue0 = 0; // variable to store the value coming from the sensor
int sensorValue1 = 0; 
int sensorValue2 = 0;


#define RELAY1  8
#define RELAY2  9
#define RELAY3  10
#define RELAY4  11

void setup() {
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT); 
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  digitalWrite(RELAY1,HIGH);
  digitalWrite(RELAY2,HIGH);
  digitalWrite(RELAY3,HIGH);
  digitalWrite(RELAY4,HIGH);
  // put your setup code here, to run once:
  Serial.begin(9600); //sets serial port for communication
}

void loop() {
  // read the value from the sensor
  sensorValue0 = analogRead(sensorPin0); 
  sensorValue1 = analogRead(sensorPin1); 
  sensorValue2 = analogRead(sensorPin2); 
  
  Serial.print(sensorValue0); //prints the values coming from the sensor on the screen
  Serial.print(" ");
  Serial.print(sensorValue1);
  Serial.print(" ");
  Serial.println(sensorValue2);
  if (sensorValue0 < 1022)  // Long actuator up
  {
    digitalWrite(RELAY1,LOW);
    delay(2000);
    digitalWrite(RELAY1,HIGH);
    delay(2000);
  }
  else if (sensorValue1 < 1022) // long actuator down
  {
    Serial.print("Sensor1 is higher");
    digitalWrite(RELAY2,LOW);
    delay(2000);
    digitalWrite(RELAY2,HIGH);
    delay(2000);
  }
  else if (sensorValue2 < 1022)
  {
    Serial.print("Sensor1 is higher");
    digitalWrite(RELAY3,LOW);
    delay(2000);
    digitalWrite(RELAY3,HIGH);
    delay(2000);
  }
}
