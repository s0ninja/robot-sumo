#define capteur_GAUCHE D8          //Capteur Gauche à la branche 1
#define capteur_CENTRE D2          //Capteur Centre à la branche 2
#define capteur_DROIT D3          //Capteur Droit à la branche 3

const int vitesseMinimal = 50;
const int vitesseMoyenne = 180;
const int vitesseModérée = 210;
const int vitesseMaximale = 255;

void setup() {
  pinMode(CAPTEUR_GAUCHE, OUTPUT);
  pinMode(CAPTEUR_CENTRE, OUTPUT);
  pinMode(CAPTEUR_DROITE,OUTPUT);
  Serial.begin(9600);               // Initialisation du moniteur série (vitesse)
}

void loop() {
  bool capteurGauche = digitalRead(capteur_GAUCHE) == HIGH;
  bool capteurCentre = digitalRead(capteur_CENTRE) == HIGH;
  bool capteurDroit = digitalRead(capteur_DROIT) == HIGH;

  if (capteurGauche) {
    if (capteurCentre) {
      if (capteurDroit) {
       Serial.print("Allez vers l'avant")
      } else {
        Serial.print("Allez vers la gauche")
      }
    } else {
      Serial.print("Allez vers la gauche")
      }
    }
  } else if (capteurGauche) {
    if (capteurCentre) {
      if (capteurDroit) {
        Serial.print("Allez vers l'avant")
      } else {
        Serial.print("Allez vers la droite")
      }
      Serial.print("Allez vers la droite")
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
