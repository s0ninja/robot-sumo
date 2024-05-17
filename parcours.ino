#define linefinderGauche 2
#define linefinderDroite 4
#define linefinderCentre 7
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

void allerdroite(int v) {
  digitalWrite(sensMGauche, HIGH);
  digitalWrite(puissanceGauche, AFOND);
  digitalWrite(marcheGauche, HIGH);
}

void allergauche(int v) {
  digitalWrite(sensMDroit, LOW);
  digitalWrite(puissanceDroit, AFOND);
  digitalWrite(marcheDroit, HIGH);
}

void avancer(int v) {
  digitalWrite(sensMGauche, HIGH);
  digitalWrite(puissanceGauche, AFOND);
  digitalWrite(marcheGauche, LOW);
  digitalWrite(sensMDroit, LOW);
  digitalWrite(puissanceDroit, AFOND);
  digitalWrite(marcheDroit, LOW);
}

byte acquisition() {
  LFD = digitalRead(linefinderDroite);
  LFG = digitalRead(linefinderGauche);
  LFC = digitalRead(linefinderCentre);

  if (LFG == 1 && LFC == 1 && LFD == 1) {
    return 5;
  } else if (LFG == 1 && LFC == 1 && LFD == 0) {
    return 1;
  } else if (LFG == 0 && LFC == 1 && LFD == 1) {
    return 2;
  } else if (LFG == 0 && LFC == 0 && LFD == 1) {
    return 2;
  } else if (LFG == 1 && LFC == 0 && LFD == 0) {
    return 1;
  } else if (LFG == 0 && LFC == 0 && LFD == 0) {
    return 0;
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
      avancer(AFOND);
      break;
    case 1:
      allerdroite(AFOND);
      break;
    case 2:
      allergauche(AFOND);
      break;
    case 3:
      allerdroite(PRUDENT);
      break;
    case 4:
      allergauche(PRUDENT);
      break;
    case 5:
      arret();
      break;
    case 6:
      avancer(AFOND);
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
