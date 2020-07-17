int inRelay = 5; //pin for the relay for the pump that pumps water into the filter
int fullLED = 6; //pin for full led indicator
int outRelay = 7; //pin for the relay for the pump that pumps water to user
int outInput = 9; //pin for input to turn on the pump to give the user water

bool full = false;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(inRelay, OUTPUT);
  pinMode(fullLED, OUTPUT);
  pinMode(outRelay, OUTPUT);
  pinMode(outInput, INPUT);
}
int buttonState;
// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(A0);
  delay(1);        // delay in between reads

  if (sensorValue < 180) {
    digitalWrite(inRelay, HIGH); //turns on relay for pump that pumps in water
    digitalWrite(fullLED, LOW); //turns of the led that shows that the container is full

    //prints out the container is not full in the serial monitor
    Serial.println("Not Full");
  } else {
    digitalWrite(inRelay, LOW); // turns off relay for pump that pumps in water.
    digitalWrite(fullLED, HIGH); //turns on an led that indicates the container is full

    //prints out the container is full in the serial monitor
    Serial.println("Full");
  }

  //user button input
  buttonState = digitalRead(outInput); //saves the state of the button (on or off)
  if(buttonState == 0){
    digitalWrite(outRelay,HIGH);
    Serial.println("Using water");
  }else{
    digitalWrite(outRelay,LOW);
  }
}
