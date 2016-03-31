#define pwm 0 // rapporte cyclique valeur de 0 a 255

int pinPwm1 = 5;
int pinPwm2 = 6;
int pinIN1 = A0;
int pinIN2 = A1;
int pinIN3 = A2;
int pinIN4 = A3;

void avancer() {
  analogWrite(pinPwm1, pwm);
  digitalWrite(pinIN1,HIGH);
  digitalWrite(pinIN2,LOW);
  analogWrite(pinPwm2, pwm);
  digitalWrite(pinIN3,HIGH);
  digitalWrite(pinIN4,LOW);
  delay(1);
}

void reculer() {
  analogWrite(pinPwm1, pwm);
  digitalWrite(pinIN1,LOW);
  digitalWrite(pinIN2,HIGH);
  analogWrite(pinPwm2, pwm);
  digitalWrite(pinIN3,LOW);
  digitalWrite(pinIN4,HIGH);
  delay(1);
}

void setup() {
  pinMode (pinPwm1, OUTPUT);
  pinMode (pinIN1, OUTPUT);
  pinMode (pinIN2, OUTPUT);
  pinMode (pinPwm2, OUTPUT);
  pinMode (pinIN3, OUTPUT);
  pinMode (pinIN4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //avancer();
  reculer();
}
