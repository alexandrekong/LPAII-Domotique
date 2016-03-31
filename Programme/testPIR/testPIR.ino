
int PinPIR = A5;               // choose the input pin (for PIR sensor)
int valPIR = 0;                    // variable for reading the pin status

void setup() {
  
  pinMode(PinPIR, INPUT);     // declare sensor as input
  Serial.begin(9600);
 }


void loop(){
  valPIR = analogRead(PinPIR);  // read input value
  Serial.println(valPIR);
  if(valPIR<=100){
     Serial.println("Obstacle");
  }else{
    Serial.println("Pas Obstacle");
  }
  delay(500);
}

