const int linefinderGauche = 2;
const int linefinderDroite = 4;
const int linefinderCentre = A3;
const int boutonMarche = A2;

const int sensMGauche = 12;
const int marcheGauche = 9;
const int puissanceGauche = 3;

const int sensMDroit = 13;
const int marcheDroit = 8;
const int puissanceDroit = 11;

const int AFOND = 130;
const int PRUDENT = 60;
const int NBMESURE = 4;

bool LFG = false, LFD = false, LFC = false;

void arret() {
  // S'arrête
  digitalWrite(marcheGauche, LOW);
  digitalWrite(marcheDroit, LOW);
}

void moteurDroite(int vitesse) {
  //Tourne à droite
  digitalWrite(sensMDroit, HIGH);
  analogWrite(puissanceDroit, vitesse);
}

void moteurGauche(int vitesse) {
  //Tourne a gauche
  digitalWrite(sensMGauche, HIGH);
  analogWrite(puissanceGauche, vitesse);
}

void moteurDroiteR(int vitesse) {
  //Tourne à droite en reculant
  digitalWrite(sensMDroit, LOW);
  analogWrite(puissanceDroit, vitesse);
}

void moteurGaucheR(int vitesse) {
  //Tourne à gauche en reculant
  digitalWrite(sensMGauche, LOW);
  analogWrite(puissanceGauche, vitesse);
}

byte acquisition() {
  LFG = digitalRead(linefinderGauche);
  LFD = digitalRead(linefinderDroite);
  LFC = digitalRead(linefinderCentre);

  if (LFD == LOW && LFG == LOW && LFC == LOW) {
    return 0;
  } else if (LFD == LOW && LFC == LOW) {
    return 1;
  } else if (LFG == LOW && LFC == LOW) {
    return 2;
  } else {
    return 3;
  }
}

void setup() {
  pinMode(linefinderGauche, INPUT);
  pinMode(linefinderDroite, INPUT);
  pinMode(linefinderCentre, INPUT);
  pinMode(boutonMarche, INPUT);
  
  pinMode(sensMGauche, OUTPUT);
  pinMode(marcheGauche, OUTPUT);
  pinMode(puissanceGauche, OUTPUT);

  pinMode(sensMDroit, OUTPUT);
  pinMode(marcheDroit, OUTPUT);
  pinMode(puissanceDroit, OUTPUT);
}

void loop() {
  switch (acquisition()) {
    case 0:
      arret();
      break;
    case 1:
      moteurDroite(AFOND);
      moteurGaucheR(AFOND);
      break;
    case 2:
      moteurDroiteR(AFOND);
      moteurGauche(AFOND);
      break;

    case 3 :
      moteurDroite(AFOND);
      moteurGaucheR(AFOND);

      moteurDroiteR(AFOND);
      moteurGauche(AFOND);
      break;

    default:
      arret();
      break;
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
