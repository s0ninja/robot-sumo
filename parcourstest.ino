#define capteurDeLigneGauche 2
#define capteurDeLigneDroite 4
#define capteurDeLigneCentre 7

#define boutonMarche 6
#define led 5

#define sensMoteurGauche 12
#define marcheMoteurGauche 9
#define puissanceMoteurGauche 3

#define sensMoteurDroite 13
#define marcheMoteurDroite 8
#define puissanceMoteurDroite 11

#define AFOND 130
#define PRUDENT 60

bool LFD = 0, LFC = 0, LFG = 0;
int X = 0;

void arret(int v) {
  digitalWrite(sensMoteurGauche, HIGH); 
  digitalWrite(marcheMoteurGauche, LOW);   
  analogWrite(puissanceMoteurGauche, v);

  digitalWrite(sensMoteurDroite, HIGH);
  digitalWrite(marcheMoteurDroite, LOW);   
  analogWrite(puissanceMoteurDroite, v);
}

void allergauche(int v) {
  digitalWrite(sensMoteurGauche, HIGH);
  analogWrite(puissanceMoteurGauche, v);
  digitalWrite(marcheMoteurGauche, HIGH);

  digitalWrite(sensMoteurDroite, LOW);
  analogWrite(puissanceMoteurDroite, v);
  digitalWrite(marcheMoteurDroite, LOW);
}

void allerdroite(int v) {
  digitalWrite(sensMoteurGauche, LOW);
  analogWrite(puissanceMoteurGauche, v);
  digitalWrite(marcheMoteurGauche, LOW);

  digitalWrite(sensMoteurDroite, HIGH);
  analogWrite(puissanceMoteurDroite, v);
  digitalWrite(marcheMoteurDroite, HIGH);
}

void avancer(int v) {
  digitalWrite(sensMoteurGauche, HIGH);
  analogWrite(puissanceMoteurGauche, v);
  digitalWrite(marcheMoteurGauche, HIGH);

  digitalWrite(sensMoteurDroite, HIGH);
  analogWrite(puissanceMoteurDroite, v);
  digitalWrite(marcheMoteurDroite, HIGH);
}

byte acquisition() {
  LFD = digitalRead(capteurDeLigneDroite);
  LFG = digitalRead(capteurDeLigneGauche);
  LFC = digitalRead(capteurDeLigneCentre);

  if ((LFG == 0) && (LFC == 0) && (LFD == 0)) {
    return 0; // Avancer
  } else if (((LFG == 1) && (LFC == 1) && (LFD == 0)) || ((LFG == 1) && (LFC == 0) && (LFD == 0))) {
    return 3; // Allez à Gauche
  } else if (((LFG == 0) && (LFC == 1) && (LFD == 1)) || ((LFG == 0) && (LFC == 0) && (LFD == 1))) {
    return 2; // Allez à Droite
  } else if ((LFG == 1) && (LFC == 0) && (LFD == 1)) {
    return 1; // STOP
  } else {
    return 1; // STOP
  }
}

void setup() {
  pinMode(sensMoteurGauche, OUTPUT);
  pinMode(marcheMoteurGauche, OUTPUT);
  pinMode(puissanceMoteurGauche, OUTPUT);

  pinMode(sensMoteurDroite, OUTPUT);
  pinMode(marcheMoteurDroite, OUTPUT);
  pinMode(puissanceMoteurDroite, OUTPUT);

  pinMode(capteurDeLigneGauche, INPUT);
  pinMode(capteurDeLigneDroite, INPUT);
  pinMode(capteurDeLigneCentre, INPUT);

  pinMode(led, OUTPUT);

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
      Serial.println("case 0, avancer");
      break;
    case 1:
      arret(AFOND);
      Serial.println("case 1, Arret");
      break;
    case 2:
      allerdroite(AFOND);
      Serial.println("case 2, tourner à droite");
      break;
    case 3:
      allergauche(AFOND);
      Serial.println("case 3, tourner à gauche");
      break;
    default:
      arret(AFOND);
      Serial.println("défault");
      break;
  }
}
