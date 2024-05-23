#define linefinderGauche 2
#define linefinderDroite 4
#define linefinderCentre 7
#define boutonMarche A2
#define sensMGauche 12
#define marcheGauche 9
#define puissanceGauche 3
#define sensMDroit 13
#define marcheDroit 8
#define puissanceDroit 11

 byte SPEED = 255, AFOND = 150, nul = 0;

bool LFG = 0, LFD = 0, LFC = 0;
int X = 0;

void arret() {
  analogWrite(puissanceDroit, LOW);
  analogWrite(puissanceGauche, LOW);
  digitalWrite(marcheGauche, HIGH);
  digitalWrite(marcheDroit, HIGH);
}

void allerdroite(int v) {
  digitalWrite(sensMGauche, LOW);
  analogWrite(puissanceGauche, v);
  digitalWrite(marcheGauche, LOW);
}

void allergauche(int v) {
  digitalWrite(sensMDroit, LOW);
  analogWrite(puissanceDroit, v);
  digitalWrite(marcheDroit, LOW);
}

void avancer(int v) {
  digitalWrite(sensMGauche, LOW);
  analogWrite(puissanceGauche, v);
  digitalWrite(marcheGauche, HIGH);
  digitalWrite(sensMDroit, HIGH);
  analogWrite(puissanceDroit, v);
  digitalWrite(marcheDroit, HIGH);
}

byte acquisition() {
  LFD = digitalRead(linefinderDroite);
  LFG = digitalRead(linefinderGauche);
  LFC = digitalRead(linefinderCentre);

  if (LFG == 1 && LFC == 1 && LFD == 1) {
    return 4;
  } else if (LFG == 1 && LFC == 1 && LFD == 0) {
    return 2;
  } else if (LFG == 0 && LFC == 1 && LFD == 1) {
    return 1;
  } else if (LFG == 0 && LFC == 0 && LFD == 1) {
    return 1;
  } else if (LFG == 1 && LFC == 0 && LFD == 0) {
    return 2;
  } else if (LFG == 0 && LFC == 0 && LFD == 0) {
    return 3;
  } else if (LFG == 1 && LFC == 0 && LFD == 1) {
    return 3;
  } else if (LFG == 0 && LFC == 1 && LFD == 0) {
    return 3;
  }
}

void setup() {
  pinMode(sensMGauche, OUTPUT);
  pinMode(marcheGauche, OUTPUT);
  pinMode(puissanceGauche, OUTPUT);
  pinMode(sensMDroit, OUTPUT);
  pinMode(marcheDroit, OUTPUT);
  pinMode(puissanceDroit, OUTPUT);
  pinMode(linefinderGauche, INPUT);
  pinMode(linefinderDroite, INPUT);
  pinMode(linefinderCentre, INPUT);
  Serial.begin(9600);
  do {
    X = analogRead(boutonMarche);
    delay(20);
  } while (X < 1000);
}

void loop() {
  switch (acquisition()) {
    case 0:
      avancer(AFOND);
      Serial.println("case 0");
      break;
    case 1:
      allerdroite(AFOND);
      Serial.println("case 1");
      break;
    case 2:
      allergauche(AFOND);
      Serial.println("case 2");
      break;
    case 3:
      arret();
      Serial.println("case 5");
      break;
    case 4:
      avancer(AFOND);
      Serial.println("case 6");
      break;
    default:
      arret();
      Serial.println("défault");
      break;
  }
}
