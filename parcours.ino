#define capteurDeLigneGauche 5
#define capteurDeLigneDroite 4
#define capteurDeLigneCentre A1

#define bouton A2
#define led A0

#define sensMoteurGauche 12
#define marcheMoteurGauche 9
#define puissanceMoteurGauche 3

#define sensMoteurDroite 13
#define marcheMoteurDroite 8
#define puissanceMoteurDroite 11

byte SPEED = 255, AFOND = 75, nul = 0;

bool sensMoteurGaucheV = LOW;
bool sensMoteurDroitB = LOW;

bool sensMoteurGenerale = LOW;

bool LFG = 0, LFD = 0, LFC = 0;
bool etatBouton = 0, marche = 0;
int X = 0;

void arret(int v) {
  digitalWrite(sensMoteurGauche, HIGH); 
  digitalWrite(marcheMoteurGauche, HIGH);   
  analogWrite(puissanceMoteurGauche, v);
  digitalWrite(sensMoteurDroite, HIGH);
  digitalWrite(marcheMoteurDroite, HIGH);   
  analogWrite(puissanceMoteurDroite, v);
}

void allergauche(int v) {
  digitalWrite(sensMoteurGauche, HIGH);
  analogWrite(puissanceMoteurGauche, v);
  digitalWrite(marcheMoteurGauche, LOW);

  digitalWrite(sensMoteurDroite, LOW);
  analogWrite(puissanceMoteurDroite, nul);
  digitalWrite(marcheMoteurDroite, HIGH);
}

void allerdroite(int v) {
  digitalWrite(sensMoteurGauche, HIGH);
  analogWrite(puissanceMoteurGauche, nul);
  digitalWrite(marcheMoteurGauche, HIGH);

  digitalWrite(sensMoteurDroite, LOW);
  analogWrite(puissanceMoteurDroite, v);
  digitalWrite(marcheMoteurDroite, LOW);
}

void avancer(int v) {
  digitalWrite(sensMoteurGauche, HIGH);
  analogWrite(puissanceMoteurGauche, v);
  digitalWrite(marcheMoteurGauche, LOW);

  digitalWrite(sensMoteurDroite, LOW);
  analogWrite(puissanceMoteurDroite, v);
  digitalWrite(marcheMoteurDroite, LOW);
}

byte acquisition() {
  LFD = digitalRead(capteurDeLigneDroite);
  LFG = digitalRead(capteurDeLigneGauche);
  LFC = digitalRead(capteurDeLigneCentre);

  if ((LFG == 0) && (LFC == 0) && (LFD == 0)) {
    return 0;
  } else if (((LFG == 0) && (LFC == 0) && (LFD == 1)) || ((LFG == 0) && (LFC == 1) && (LFD == 1))) {
    return 2;
  } else if (((LFG == 1) && (LFC == 0) && (LFD == 0)) || ((LFG == 1) && (LFC == 1) && (LFD == 0))) {
    return 3;
  } else if (((LFG == 1) && (LFC == 1) && (LFD == 1)) || ((LFG == 1) && (LFC == 0) && (LFD == 1))) {
    return 1;
  } else {
    return 1;
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

  pinMode(led, OUTPUT);
  pinMode(bouton, INPUT);

  //pinMode(capteurDeLigneCentre, INPUT);
  Serial.begin(9600);

}

void loop() {
  etatBouton = analogRead(bouton);

  if (etatBouton == 1) {
    if (marche == 0) {
      marche = 1;
    } else {
      marche = 0;
    }
    delay(500);
  }

  Serial.println(marche);

  if (marche == 1) {
    analogWrite(led, HIGH);
  switch (acquisition()) {
    case 0:                         // Case Avancer
      avancer(AFOND);
      Serial.println("case 0, avancer");
      break;
    case 1:      // Case Stopper
      arret(nul);                   
      Serial.println("case 1, Arret");
      break;
    case 2:                         // Case Aller à droite
      allerdroite(AFOND);
      Serial.println("case 2, tourner à droite");
      break;
    case 3:                         // Case Aller à gauche
      allergauche(AFOND);
      Serial.println("case 3, tourner à gauche");
      break;
    default:                        // Case par Défaut
      arret(nul);
      Serial.println("défault");
      break;
  }
  } else {
    analogWrite(led, LOW);
    arret(nul);
  } 
}
