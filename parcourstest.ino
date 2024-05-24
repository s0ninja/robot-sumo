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
  analogWrite(puissanceDroit, 0);
  analogWrite(puissanceGauche, 0);
  digitalWrite(marcheGauche, HIGH);
  digitalWrite(marcheDroit, HIGH);
}

void allergauche(int v) {
  digitalWrite(sensMGauche, HIGH);
  analogWrite(puissanceGauche, v);
  digitalWrite(marcheGauche, LOW);
}

void allerdroite(int v) {
  digitalWrite(sensMDroit, LOW);
  analogWrite(puissanceDroit, v);
  digitalWrite(marcheDroit, LOW);
}

void avancer(int v) {
  digitalWrite(sensMGauche, HIGH);
  analogWrite(puissanceGauche, v);
  digitalWrite(marcheGauche, LOW);
  digitalWrite(sensMDroit, HIGH);
  analogWrite(puissanceDroit, v);
  digitalWrite(marcheDroit, LOW);
}

byte acquisition() {
  LFD = digitalRead(linefinderDroite);
  LFG = digitalRead(linefinderGauche);
  LFC = digitalRead(linefinderCentre);

  if ((LFG == 1) && (LFC == 1) && (LFD == 1)) {   // STOP
    return 3; // Stop
  } else if (((LFG == 1) && (LFC == 1) && (LFD == 0))||((LFG == 1) && (LFC == 0) && (LFD == 0))) { // Allez à Gauche
    return 2; // Allez à Gauche
  } else if (((LFG == 0) && (LFC == 1) && (LFD == 1))||((LFG == 0) && (LFC == 0) && (LFD == 1))) { // Allez à Droite
    return 1; // Allez à Droite
  } else if ((LFG == 0) && (LFC == 1) && (LFD == 0)) { // Avancer
    return 0; // Avancer
  } else if (((LFG == 1) && (LFC == 0) && (LFD == 1))||((LFG == 0) && (LFC == 0) && (LFD == 0))) { // Cas Impossible
    return 3; // STOP
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
    case 0:                         // Case Avancer
      avancer(AFOND);
      Serial.println("case 0");
      break;
    case 1:                         // Case Allez à droite
      allerdroite(AFOND);
      Serial.println("case 1");
      break;
    case 2:                         // Case Allez à Gauche
      allergauche(AFOND);
      Serial.println("case 2");
      break;
    case 3:                         // Case Stop
      arret();
      Serial.println("case 3");
      break;
    default:                        // Case par Défault
      arret();
      Serial.println("défault");
      break;
  }
}
