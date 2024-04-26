#define capteur_GAUCHE D8          //Capteur Gauche à la branche 1
#define capteur_CENTRE D2          //Capteur Centre à la branche 2
#define capteur_DROIT D3          //Capteur Droit à la branche 3

#define Roue_GAUCHE D4          //Roue Gauche à la branche 4
#define Roue_DROIT D5          //Roue Droit à la branche 5

const int vitesseMinimal = 50;
const int vitesseMoyenne = 180;
const int vitesseModérée = 210;
const int vitesseMaximale = 255;

void setup() {
  pinMode(CAPTEUR_GAUCHE, INPUT);
  pinMode(CAPTEUR_CENTRE, INPUT);
  pinMode(CAPTEUR_DROITE, INPUT);
  Serial.begin(9600);               // Initialisation du moniteur série (vitesse)
  pinMode(Roue_GAUCHE, OUTPUT);     // La broche de contrôle du moteur est en sortie du côté Gauche
  pinMode(Roue_DROIT, OUTPUT);     // La broche de contrôle du moteur est en sortie du côté Droit
}

void loop() {
  bool capteurGauche = digitalRead(capteur_GAUCHE) == HIGH;
  bool capteurCentre = digitalRead(capteur_CENTRE) == HIGH;
  bool capteurDroit = digitalRead(capteur_DROIT) == HIGH;

  if (capteurGauche) {
    if (capteurCentre) {
      if (capteurDroit) {
       digitalWrite(Roue_GAUCHE, HIGH);                // Mettre la broche de contrôle du moteur à HIGH pour avancer
       analogWrite(Roue_GAUCHE, vitesseModérée);       // vitesse du moteur à la valeur |Ligne 10

       digitalWrite(Roue_DROIT, HIGH);                 // Mettre la broche de contrôle du moteur à HIGH pour avancer
       analogWrite(Roue_DROIT, vitesseModérée);        // vitesse du moteur à la valeur |Ligne 10

      } else {
        digitalWrite(Roue_GAUCHE, HIGH);                // Mettre la broche de contrôle du moteur à HIGH pour avancer
        analogWrite(Roue_GAUCHE, vitesseMinimal);       // vitesse du moteur à la valeur |Ligne 8
        
        digitalWrite(Roue_DROIT, HIGH);                // Mettre la broche de contrôle du moteur à HIGH pour avancer
        analogWrite(Roue_DROIT, vitesseModérée);       // vitesse du moteur à la valeur |Ligne 10
      }
    } else {
      digitalWrite(Roue_GAUCHE, HIGH);                 // Mettre la broche de contrôle du moteur à HIGH pour avancer
      analogWrite(Roue_GAUCHE, vitesseMinimal);        // vitesse du moteur à la valeur |Ligne 8

      digitalWrite(Roue_DROIT, HIGH);                  // Mettre la broche de contrôle du moteur à HIGH pour avancer
      analogWrite(Roue_DROIT, vitesseModérée);         // vitesse du moteur à la valeur |Ligne 10
      }
    }
  } else if (capteurGauche) {
    if (capteurCentre) {
      if (capteurDroit) {
        digitalWrite(Roue_GAUCHE, LOW);                // Mettez la broche de contrôle du moteur gauche à LOW pour faire reculer
        analogWrite(Roue_GAUCHE, vitesseModérée);      // vitesse du moteur à la valeur |Ligne 10

        digitalWrite(Roue_DROIT, LOW);                 // Mettez la broche de contrôle du moteur droit à LOW pour faire reculer
        analogWrite(Roue_DROIT, vitesseModérée);       // vitesse du moteur à la valeur |Ligne 10
      } else {
        digitalWrite(Roue_GAUCHE, HIGH);               // Mettre la broche de contrôle du moteur à HIGH pour avancer
        analogWrite(Roue_GAUCHE, vitesseModérée);      // vitesse du moteur à la valeur |Ligne 8

        digitalWrite(Roue_DROIT, HIGH);                // Mettre la broche de contrôle du moteur à HIGH pour avancer
        analogWrite(Roue_DROIT, vitesseMinimal);       // vitesse du moteur à la valeur |Ligne 10
      }
      digitalWrite(Roue_GAUCHE, HIGH);                 // Mettre la broche de contrôle du moteur à HIGH pour avancer
      analogWrite(Roue_GAUCHE, vitesseModérée);        // vitesse du moteur à la valeur |Ligne 8

      digitalWrite(Roue_DROIT, HIGH);                  // Mettre la broche de contrôle du moteur à HIGH pour avancer
      analogWrite(Roue_DROIT, vitesseMinimal);         // vitesse du moteur à la valeur |Ligne 10
    } else {
      return;
    }
  } else {
    return;
  }
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
