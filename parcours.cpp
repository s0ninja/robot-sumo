#define CAPTEUR_GAUCHE 8          // Capteur Gauche à la branche 1
#define CAPTEUR_CENTRE 2          // Capteur Centre à la branche 2
#define CAPTEUR_DROIT 3           // Capteur Droit à la branche 3

#define Roue_DROIT 6
#define Roue_GAUCHE 5

#define LED_PIN 7                 // Pin de la LED

#define start_button 4

void setup() {
  pinMode(CAPTEUR_GAUCHE, INPUT);
  pinMode(CAPTEUR_CENTRE, INPUT);
  pinMode(CAPTEUR_DROIT, INPUT);
  pinMode(Roue_GAUCHE, OUTPUT);
  pinMode(Roue_DROIT, OUTPUT);
  pinMode(start_button, INPUT);         // Boutton pour start le robot
  pinMode(LED_PIN, OUTPUT);       // Définir le pin de la LED comme une sortie
  Serial.begin(9600);             // Initialisation du moniteur série (vitesse)
}

void loop() {
  bool capteurGauche = digitalRead(CAPTEUR_GAUCHE) == true;
  bool capteurCentre = digitalRead(CAPTEUR_CENTRE) == true;
  bool capteurDroit = digitalRead(CAPTEUR_DROIT) == true;
  bool start = digitalRead(start_button) == true;

  if (start_button == true) {
    digitalWrite(start_button);
    
    if (capteurGauche) {
      if (capteurCentre) {
        if (capteurDroit) {
          digitalWrite(LED_PIN, HIGH);  // Allumer la LED si les capteurs sont dans la bonne configuration
        } else {
          digitalWrite(Roue_GAUCHE, HIGH);                // Mettre la broche de contrôle du moteur à HIGH pour avancer
          analogWrite(Roue_GAUCHE, vitesseMinimal);       // vitesse du moteur à la valeur |Ligne 10

          digitalWrite(Roue_DROIT, HIGH);                // Mettre la broche de contrôle du moteur à HIGH pour avancer
          analogWrite(Roue_DROIT, vitesseModérée);       // vitesse du moteur à la valeur |Ligne 10
        }
      } else {
         digitalWrite(Roue_GAUCHE, HIGH);                // Mettre la broche de contrôle du moteur à HIGH pour avancer
        analogWrite(Roue_GAUCHE, vitesseMinimal);       // vitesse du moteur à la valeur |Ligne 10

        digitalWrite(Roue_DROIT, HIGH);                // Mettre la broche de contrôle du moteur à HIGH pour avancer
        analogWrite(Roue_DROIT, vitesseModérée);       // vitesse du moteur à la valeur |Ligne 10
      }
    } else if (capteurDroit) {
      if (capteurCentre) {
        digitalWrite(Roue_GAUCHE, HIGH);                 // Mettre la broche de contrôle du moteur à HIGH pour avancer
        analogWrite(Roue_GAUCHE, vitesseMinimal);        // vitesse du moteur à la valeur |Ligne 8

        digitalWrite(Roue_DROIT, HIGH);                  // Mettre la broche de contrôle du moteur à HIGH pour avancer
        analogWrite(Roue_DROIT, vitesseModérée);         // vitesse du moteur à la valeur |Ligne 10
      } else {
        digitalWrite(Roue_GAUCHE, HIGH);                 // Mettre la broche de contrôle du moteur à HIGH pour avancer
        analogWrite(Roue_GAUCHE, vitesseMinimal);        // vitesse du moteur à la valeur |Ligne 8

        digitalWrite(Roue_DROIT, HIGH);                  // Mettre la broche de contrôle du moteur à HIGH pour avancer
        analogWrite(Roue_DROIT, vitesseModérée);         // vitesse du moteur à la valeur |Ligne 10
      }
    } else {
      digitalWrite(Roue_GAUCHE, HIGH);                 // Mettre la broche de contrôle du moteur à HIGH pour avancer
      analogWrite(Roue_GAUCHE, vitesseModérée);        // vitesse du moteur à la valeur |Ligne 8

      digitalWrite(Roue_DROIT, HIGH);                  // Mettre la broche de contrôle du moteur à HIGH pour avancer
      analogWrite(Roue_DROIT, vitesseModérée);         // vitesse du moteur à la valeur |Ligne 10

      digitalWrite(LED_PIN, HIGH);  // Allumer la LED si les capteurs sont dans la bonne configuration
    }

    digitalWrite(LED_PIN, LOW);  // Eteindre la LED si les capteurs sont dans la bonne configuration
    delay(1000);  // Ajout d'une pause d'une seconde entre les lectures
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
