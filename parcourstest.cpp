#define CAPTEUR_GAUCHE 8          // Capteur Gauche à la branche 1
#define CAPTEUR_CENTRE 2          // Capteur Centre à la branche 2
#define CAPTEUR_DROIT 3          // Capteur Droit à la branche 3
#define LED_PIN 7                // Pin de la LED

void setup() {
  pinMode(CAPTEUR_GAUCHE, INPUT);
  pinMode(CAPTEUR_CENTRE, INPUT);
  pinMode(CAPTEUR_DROIT, INPUT);
  pinMode(LED_PIN, OUTPUT);     // Définir le pin de la LED comme une sortie
  Serial.begin(9600);           // Initialisation du moniteur série (vitesse)
}

void loop() {
  bool capteurGauche = digitalRead(CAPTEUR_GAUCHE) == HIGH;
  bool capteurCentre = digitalRead(CAPTEUR_CENTRE) == HIGH;
  bool capteurDroit = digitalRead(CAPTEUR_DROIT) == HIGH;

  if (capteurGauche) {
    if (capteurCentre) {
      if (capteurDroit) {
        Serial.println("Allez vers l'avant");
        digitalWrite(LED_PIN, HIGH);  // Allumer la LED si les capteurs sont dans la bonne configuration
      } else {
        Serial.println("Allez vers la gauche");
      }
    } else {
      Serial.println("Allez vers la gauche");
    }
  } else if (capteurDroit) {
    if (capteurCentre) {
      Serial.println("Allez vers la droite");
    } else {
      Serial.println("Allez vers l'avant");
    }
  } else {
    Serial.println("Allez vers l'avant");
  }

  delay(1000);  // Ajout d'une pause d'une seconde entre les lectures
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
