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

 byte SPEED = 255, AFOND = 175, nul = 0;

bool LFG = 0, LFD = 0, LFC = 0;
int X = 0;

void arret(int v) {
  digitalWrite(sensMGauche, HIGH); 
  digitalWrite(marcheGauche, HIGH);   
  analogWrite(puissanceGauche, v);
  digitalWrite(sensMDroit, LOW);
  digitalWrite(marcheDroit, HIGH);   
  analogWrite(puissanceDroit, v);

  delay(200);
}

void allergauche(int v) {
  digitalWrite(sensMGauche, HIGH);
  analogWrite(puissanceGauche, v);
  digitalWrite(marcheGauche, LOW);

  delay(200);
}

void allerdroite(int v) {
  digitalWrite(sensMDroit, LOW);
  analogWrite(puissanceDroit, v);
  digitalWrite(marcheDroit, LOW);

  delay(200);
}

void avancer(int v) {
  digitalWrite(sensMGauche, HIGH);
  analogWrite(puissanceGauche, v);
  digitalWrite(marcheGauche, LOW);
  digitalWrite(sensMDroit, LOW);
  analogWrite(puissanceDroit, v);
  digitalWrite(marcheDroit, LOW);

  delay(200);
}

byte acquisition() {
  LFD = digitalRead(linefinderDroite);
  LFG = digitalRead(linefinderGauche);
  LFC = digitalRead(linefinderCentre);

  if ((LFG == 0) && (LFC == 0) && (LFD == 0)) {   // Avancer
    return 0; // Avancer
  } else if (((LFG == 1) && (LFC == 1) && (LFD == 0))||((LFG == 1) && (LFC == 0) && (LFD == 0))) { // Allez à Gauche
    return 2; // Allez à Gauche
  } else if (((LFG == 0) && (LFC == 1) && (LFD == 1))||((LFG == 0) && (LFC == 0) && (LFD == 1))) { // Allez à Droite
    return 1; // Allez à Droite
  } else if ((LFG == 1) && (LFC == 0) && (LFD == 1)) { // Avancer
    return 3; // STOP
  } else if (((LFG == 1) && (LFC == 0) && (LFD == 1))||((LFG == 1) && (LFC == 1) && (LFD == 1))) { // Cas Impossible
    return 3; // STOP
  }
  return 100;
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
      arret(nul);
      Serial.println("case 3");
      break;
    default:                        // Case par Défault
      arret(nul);
      Serial.println("défault");
      break;
  }
}
