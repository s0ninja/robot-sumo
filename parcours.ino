const int CAPTEUR_GAUCHE = 5; // Capteur Gauche à la broche A0
const int CAPTEUR_CENTRE = 6; // Capteur Centre à la broche A1
const int CAPTEUR_DROIT = 2; // Capteur Droit à la broche A2

const int vitesseDroite = 11;
const int vitesseGauche = 3;
const int sensDroite = 13;
const int sensGauche = 12;
const int freinDroite = 8;
const int freinGauche = 9;

const int start_button = 4; // Bouton pour démarrer le robot

const int led = 7;

bool capteurGauche;
bool capteurCentre;
bool capteurDroit;
bool start = false;
bool etatBouton = false;

void setup() {
  pinMode(CAPTEUR_GAUCHE, INPUT);
  pinMode(CAPTEUR_CENTRE, INPUT);
  pinMode(CAPTEUR_DROIT, INPUT);

  pinMode(vitesseDroite, OUTPUT);
  pinMode(vitesseGauche, OUTPUT);
  pinMode(sensDroite, OUTPUT);
  pinMode(sensGauche, OUTPUT);
  pinMode(freinDroite, OUTPUT);
  pinMode(freinGauche, OUTPUT);

  pinMode(led, OUTPUT);
  pinMode(start_button, INPUT); // Bouton pour démarrer le robot
}

void loop() {
  capteurGauche = digitalRead(CAPTEUR_GAUCHE);
  capteurCentre = digitalRead(CAPTEUR_CENTRE);
  capteurDroit = digitalRead(CAPTEUR_DROIT);
  etatBouton = digitalRead(start_button);
  

  if (etatBouton == true) {
    if (start == true) {
      start = false;
      delay(500);
    }
    else {
      start = true;
      delay(500);
    }
  }

  if (start = HIGH) {
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }

  if (capteurGauche && capteurCentre && capteurDroit) {
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);

    digitalWrite(13, HIGH); // Sens Droit Avancer
    digitalWrite(12, HIGH); //Sens Gauche Avancer

    analogWrite(11, 255); //Vitesse 255 Droit
    analogWrite(3, 255); //Vitesse 255 Gauche

    digitalWrite(8, LOW); //Frein non engagé Droit
    digitalWrite(9, LOW); //Frein non engagé Gauche
  } else {
    if (capteurGauche) {
      digitalWrite(13, HIGH); // Sens Droit Avancer
      digitalWrite(12, HIGH); //Sens Gauche Avancer

      analogWrite(11, 255); //Vitesse 255 Droit
      analogWrite(3, 0); //Vitesse 0 Gauche

      digitalWrite(8, HIGH); //Frein engagé Droit
      digitalWrite(9, LOW); //Frein non engagé Gauche
    } else if (capteurDroit) {
      digitalWrite(13, HIGH); // Sens Droit Avancer
      digitalWrite(12, HIGH); //Sens Gauche Avancer

      analogWrite(11, 0); //Vitesse 0 Droit
      analogWrite(3, 255); //Vitesse 255 Gauche

      digitalWrite(8, LOW); //Frein non engagé Droit
      digitalWrite(9, HIGH); //Frein engagé Gauche
    } else {
      digitalWrite(13, LOW); // Sens Droit Avancer
      digitalWrite(12, LOW); //Sens Gauche Avancer

      analogWrite(11, 0); //Vitesse 0 Droit
      analogWrite(3, 0); //Vitesse 0 Gauche

      digitalWrite(8, HIGH); //Frein engagé Droit
      digitalWrite(9, HIGH); //Frein engagé Gauche
    }
  }
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);

  digitalWrite(13, LOW); // Sens Droit Avancer
  digitalWrite(12, LOW); //Sens Gauche Avancer

  analogWrite(11, 0); //Vitesse 0 Droit
  analogWrite(3, 0); //Vitesse 0 Gauche

  digitalWrite(8, HIGH); //Frein engagé Droit
  digitalWrite(9, HIGH); //Frein engagé Gauche
}


/*
 _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____
|_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____|
  ____  ____    ___   _   _  ____   _____   _____
 / ___||  _ \  / _ \ | | | ||  _ \ | ____| |___  |
| |  _ | |_) || | | || | | || |_) ||  _|      / /
| |_| ||  _ < | |_| || |_| ||  __/ | |___    / /
 \____||_| \_\ \___/  \___/ |_|    |_____|  /_/
 _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____
|_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____|
 __  __               _
|  \/  |  __ _  _ __ (_) _ __    ___
| |\/| | / _` || '__|| || '_ \  / _ \
| |  | || (_| || |   | || | | ||  __/
|_|  |_| \__,_||_|   |_||_| |_| \___|
 ____
|  _ \   ___   _ __ ___   _   _
| |_) | / _ \ | '_ ` _ \ | | | |
|  _ < | (_) || | | | | || |_| |
|_| \_\ \___/ |_| |_| |_| \__, |
                          |___/
 ____   _
/ ___| | |_   ___ __   __  ___  _ __ 
\___ \ | __| / _ \\ \ / / / _ \| '_ \
 ___) || |_ |  __/ \ V / |  __/| | | |
|____/  \__| \___|  \_/   \___||_| |_|
 ____
/ ___|   ___   _ __   _   _
\___ \  / _ \ | '_ \ | | | |
 ___) || (_) || | | || |_| |
|____/  \___/ |_| |_| \__, |
                      |___/
 _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____
|_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____||_____|
*/
