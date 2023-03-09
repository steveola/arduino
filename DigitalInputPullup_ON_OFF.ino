int LEDState = 0;
int LEDpin = 7;
int btnPin = 12;
int btnOLD = 1;
int btnNEW;
int dt = 100;
void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  int btnNEW = digitalRead(btnPin);
  Serial.println(btnNEW);
  
  if(btnOLD == 1 && btnNEW == 0){
//  if(btnOLD == 0 && btnNEW == 1){    //TOGGLE DOWN
    if(LEDState == 0){
      digitalWrite(LEDpin, HIGH);
      LEDState = 1;
    }else{
      digitalWrite(LEDpin, LOW);
      LEDState = 0;      
    }
  }
  btnOLD = btnNEW;
  delay(dt);  
}
