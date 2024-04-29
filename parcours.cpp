#define CAPTEUR_GAUCHE 8          // Capteur Gauche à la broche 8
#define CAPTEUR_CENTRE 2          // Capteur Centre à la broche 2
#define CAPTEUR_DROIT 3           // Capteur Droit à la broche 3

#define Roue_DROIT A1
#define Roue_GAUCHE B1

#define LED_PIN 7                 // Broche de la LED

#define start_button 4

int vitesseMinimale = 100; // Vitesse minimale des moteurs
int vitesseModeree = 200; // Vitesse modérée des moteurs

void setup() {
  pinMode(CAPTEUR_GAUCHE, INPUT);
  pinMode(CAPTEUR_CENTRE, INPUT);
  pinMode(CAPTEUR_DROIT, INPUT);
  pinMode(Roue_GAUCHE, OUTPUT);
  pinMode(Roue_DROIT, OUTPUT);
  pinMode(start_button, INPUT);         // Bouton pour démarrer le robot
  pinMode(LED_PIN, OUTPUT);       // Définir le pin de la LED comme une sortie
  Serial.begin(9600);             // Initialisation du moniteur série (vitesse)
}

void loop() {
  bool capteurGauche = digitalRead(CAPTEUR_GAUCHE);
  bool capteurCentre = digitalRead(CAPTEUR_CENTRE);
  bool capteurDroit = digitalRead(CAPTEUR_DROIT);
  bool start = digitalRead(start_button);

  while (start) {
    if (capteurGauche && capteurCentre && capteurDroit) {
      digitalWrite(LED_PIN, HIGH);  // Allumer la LED si les capteurs sont dans la bonne configuration
    } else {
      if (capteurGauche) {

        digitalWrite(Roue_GAUCHE, HIGH);
        analogWrite(Roue_GAUCHE, vitesseMinimale);
        digitalWrite(Roue_DROIT, HIGH);
        analogWrite(Roue_DROIT, vitesseModeree);

      } else if (capteurDroit) {

        digitalWrite(Roue_GAUCHE, HIGH);
        analogWrite(Roue_GAUCHE, vitesseModeree);
        digitalWrite(Roue_DROIT, HIGH);
        analogWrite(Roue_DROIT, vitesseMinimale);

      } else {

        digitalWrite(Roue_GAUCHE, HIGH);
        analogWrite(Roue_GAUCHE, vitesseModeree);
        digitalWrite(Roue_DROIT, HIGH);
        analogWrite(Roue_DROIT, vitesseModeree);

      }
    }

    delay(100);  // Ajout d'une pause plus courte pour ne pas bloquer la boucle
    start = digitalRead(start_button);  // Mise à jour de l'état du bouton
    
  }
  // Arrêter les moteurs lorsque le bouton est relâché
  digitalWrite(Roue_GAUCHE, LOW);
  digitalWrite(Roue_DROIT, LOW);
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
