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
    if (start == false) {
      start = true;
      delay(500);
    }
    else {
      start = false;
      delay(500);
    }
  }

  if (start == true) {
    digitalWrite(led, HIGH);
    digitalWrite(start_button, HIGH);
  } else {
    digitalWrite(start_button, LOW);
  }

  if (capteurGauche && capteurCentre && capteurDroit) {
    Serial.println("Bouton poussoir start"); //bouton 7  allumé
    Serial.println("led allumer"); //led allumé

    Serial.println("sens droit avancer"); // Sens Droit Avancer
    Serial.println("sens gauche avancer"); //Sens Gauche Avancer

    Serial.println("vitesse 255 droit"); //Vitesse 255 Droit
    Serial.println("vitesse 255 gauche"); //Vitesse 255 Gauche

    Serial.println("frein non engagé"); //Frein non engagé Droit
    Serial.println("frein non engagé gauche"); //Frein non engagé Gauche
  } else {
    if (capteurGauche) {
      Serial.println("sens droit avancer"); // Sens Droit Avancer
      Serial.println("sens gauche avancer"); //Sens Gauche Avancer

      Serial.println("frein 255 droit"); //Vitesse 255 Droit
      Serial.println("vitesse 0 gauche"); //Vitesse 0 Gauche

      Serial.println("frein engagé droit"); //Frein engagé Droit
      Serial.println("frein non engagé gauche"); //Frein non engagé Gauche
    } else if (capteurDroit) {
      Serial.println("sens droit avancer"); // Sens Droit Avancer
      Serial.println("sens gauche avancer"); //Sens Gauche Avancer

      Serial.println("vitesse 0 droit"); //Vitesse 0 Droit
      Serial.println("vitesse 255 gauche"); //Vitesse 255 Gauche

      Serial.println("frein non engagé"); //Frein non engagé Droit
      Serial.println("frein engagé gauche"); //Frein engagé Gauche
    } else {
      Serial.println("sens droit avancer"); // Sens Droit Avancer
      Serial.println("sens gauche avancer"); //Sens Gauche Avancer

      Serial.println("vitesse 0 droit"); //Vitesse 0 Droit
      Serial.println("vitesse 0 gauche"); //Vitesse 0 Gauche

      Serial.println("frein engagé droit"); //Frein engagé Droit
      Serial.println("frein engagé gauche"); //Frein engagé Gauche
    }
  }

  Serial.println("Bouton poussoir start"); //bouton 7
  Serial.println("led eteint"); //led eteint

  Serial.println("sens avancer droit"); // Sens Droit Avancer
  Serial.println("sens avancer gauche"); //Sens Gauche Avancer

  Serial.println("vitessee 0 droit"); //Vitesse 0 Droit
  Serial.println("vitesse 0 gache"); //Vitesse 0 Gauche

  Serial.println("frein engagé droit"); //Frein engagé Droit
  Serial.println("frein désangagé gauche"); //Frein engagé Gauche
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
