#define linefinderGauche 2
#define linefinderDroite 4
#define linefinderCentre 3
#define boutonMarche A2
#define sensMGauche 12
#define marcheGauche 9
#define puissanceGauche 3
#define sensMDroit 13
#define marcheDroit 8
#define puissanceDroit 11
#define AFOND 130
#define PRUDENT 60

bool LFG = 0, LFD = 0, LFC = 0;
int X = 0;

void arret() {
  digitalWrite(puissanceDroit, LOW);
  digitalWrite(puissanceGauche, LOW);
  digitalWrite(marcheGauche, HIGH);
  digitalWrite(marcheDroit, HIGH);
}

void moteurDroite(int v) {
  digitalWrite(sensMGauche, HIGH);
  analogWrite(puissanceGauche, v);
  digitalWrite(marcheGauche, HIGH);
}

void moteurGauche(int v) {
  digitalWrite(sensMDroit, HIGH);
  analogWrite(puissanceDroit, v);
  digitalWrite(marcheDroit, HIGH);
}

void moteurDroite2(int v) {
  digitalWrite(sensMGauche, HIGH);
  analogWrite(puissanceGauche, 100);
  digitalWrite(sensMDroit, HIGH);
  analogWrite(puissanceDroit, v);
}

void moteurGauche2(int v) {
  digitalWrite(sensMDroit, HIGH);
  analogWrite(puissanceDroit, 100);
  digitalWrite(sensMGauche, HIGH);
  analogWrite(puissanceGauche, v);
}

void moteurCentre(int v) {
  digitalWrite(sensMGauche, HIGH);
  analogWrite(puissanceGauche, v);
  digitalWrite(sensMDroit, HIGH);
  analogWrite(puissanceDroit, v);
}

byte acquisition() {
  LFD = digitalRead(linefinderDroite);
  LFG = digitalRead(linefinderGauche);
  LFC = digitalRead(linefinderCentre);

  if (LFG == false && LFD == false && LFC == true) {
    return 0;
  } else if (LFC == false && LFD == true && LFG == false) {
    return 1;
  } else if (LFC == false && LFG == true && LFD == false) {
    return 2;
  } else if (LFC == true && LFG == false && LFD == true) {
    return 3;
  } else if (LFC == true && LFG == true && LFD == false) {
    return 4;
  } else if (LFC == false && LFG == true && LFD == true) {
    return 5;
  } else if (LFC == true && LFG == true && LFD == true) {
    return 6;
  }
}

void setup() {
  pinMode(sensMGauche, OUTPUT);
  pinMode(marcheGauche, OUTPUT);
  pinMode(puissanceGauche, OUTPUT);
  pinMode(sensMDroit, OUTPUT);
  pinMode(marcheDroit, OUTPUT);
  pinMode(puissanceDroit, OUTPUT);
  pinMode(linefinderGauche, INPUT);
  pinMode(linefinderDroite, INPUT);
  pinMode(linefinderCentre, INPUT);
  Serial.begin(9600);
  do {
    X = analogRead(boutonMarche);
    delay(20);
  } while (X < 1000);
}

void loop() {
  switch (acquisition()) {
    case 0:
      moteurCentre(AFOND);
      break;
    case 1:
      moteurDroite(AFOND);
      break;
    case 2:
      moteurGauche(AFOND);
      break;
    case 3:
      moteurDroite2(PRUDENT);
      break;
    case 4:
      moteurGauche2(PRUDENT);
      break;
    case 5:
      moteurCentre(AFOND);
      break;
    case 6:
      moteurCentre(0);
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
