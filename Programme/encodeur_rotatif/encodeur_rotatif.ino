#define MENU_0 0
#define MENU_1 1
#define MENU_2 2
#define MENU_3 3
#define MENU_4 4
#define MENU_5 5
#define MENU_6 6
#define MENU_7 7
#define MENU_8 8
#define MENU_9 9

int pinA = 3; // Connected to CLK intteruption 0
int pinB = 2; // Connected to DT interruption 1
int pinC = 4;
int encoderPosCount = 0;
const int encoderPosMax = 10;
int etatMenu = 0;
int sens;
int etatPinCAnterieur = 0;
int etatPinC = LOW;
volatile unsigned long last_micros;
long debouncing_time = 100;
void sensHoraire() {
  if(encoderPosCount < 10)
  {
    encoderPosCount++;
  }else{
    encoderPosCount = 0;
  }
  Serial.println ("Sens horaire"); // sens horaire
  Serial.print("Encoder Position: ");
  Serial.println(encoderPosCount);
}

void sensAntiHoraire() {
    if(encoderPosCount > 0)
  {
    encoderPosCount--;
  }else{
    encoderPosCount = 10;
  }
  Serial.println("Sens anti Horaire"); // sens anti horaire
  Serial.print("Encoder Position: ");
  Serial.println(encoderPosCount);
}

void antiRebondHoraire(){
   if((long)(micros() - last_micros) >= debouncing_time * 1000) {
    sensHoraire();
    last_micros = micros();
  }
}
void antiRebondAntiHoraire(){
   if((long)(micros() - last_micros) >= debouncing_time * 1000) {
    sensAntiHoraire();
    last_micros = micros();
  }
}

void setup() {
  pinMode (pinA, INPUT);
  pinMode (pinB, INPUT);
  pinMode (pinC, INPUT);

  attachInterrupt(0, antiRebondHoraire, CHANGE); // (param1 = numero de l'interruption 0 ou 1, para2 = fonction appeler, para 3= type de changement d'etat ici juste un changement d'etat
  attachInterrupt(1, antiRebondAntiHoraire, CHANGE);
  Serial.begin (115200);
}

void lireEtatEncodeur() {
  etatPinC = digitalRead(pinC);
  if (etatPinC != etatPinCAnterieur) {
    if (etatPinC == HIGH) {
      //Serial.print("appui detecter \n");

      etatMenu = encoderPosCount;
      afficheMenu();
    }
  }
  etatPinCAnterieur = etatPinC;
}

void loop() {
lireEtatEncodeur();
}

void afficheMenu() {
  switch (etatMenu) {
    case MENU_0 :
      Serial.print("Vous ete dans le menu 0 \t | ");
      break;
    case MENU_1 :
      Serial.print("Vous ete dans le menu 1 \t | ");

      break;
    case MENU_2 :
      Serial.print("Vous ete dans le menu 2 \t | ");

      break;
    case MENU_3 :
      Serial.print("Vous ete dans le menu 3 \t | ");

      break;
    case MENU_4 :
      Serial.print("Vous ete dans le menu 4 \t | ");

      break;
    case MENU_5 :
      Serial.print("Vous ete dans le menu 5 \t | ");

      break;
    case MENU_6 :
      Serial.print("Vous ete dans le menu 6 \t | ");

      break;
    case MENU_7 :
      Serial.print("Vous ete dans le menu 7 \t | ");

      break;
    case MENU_8 :
      Serial.print("Vous ete dans le menu 8 \t | ");

      break;
    case MENU_9 :
      Serial.print("Vous ete dans le menu 9 \t | ");

      break;
    default:
      Serial.print("ERREUR");

      break;
  }

}
