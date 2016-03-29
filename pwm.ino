int pinPwm1_A = 11;
int pinPwm1_B = 9;
int pinPwm2_A = 5;
int pinPwm2_B = 6;


void setup() {
  pinMode (pinPwm1_A, OUTPUT);
  pinMode (pinPwm1_B, OUTPUT);
  pinMode (pinPwm2_A, OUTPUT);
  pinMode (pinPwm2_B, OUTPUT);
}

void loop() {
  analogWrite(pinPwm1_A, 127);
  analogWrite(pinPwm1_B, 255);
  analogWrite(pinPwm2_A, 127);
  analogWrite(pinPwm2_B, 255);

}
