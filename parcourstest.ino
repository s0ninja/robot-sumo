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

 byte SPEED = 255, AFOND = 150, nul = 0;

bool LFG = 0, LFD = 0, LFC = 0;
int X = 0;

void arret(int v) {
  analogWrite(puissanceDroit, v);
  analogWrite(puissanceGauche, v);
  digitalWrite(marcheGauche, HIGH);
  digitalWrite(marcheDroit, HIGH);
}

void allerdroite(int v) {
  digitalWrite(sensMGauche, LOW);
  analogWrite(puissanceGauche, v);
  digitalWrite(marcheGauche, LOW);
}

void allergauche(int v) {
  digitalWrite(sensMDroit, HIGH);
  analogWrite(puissanceDroit, v);
  digitalWrite(marcheDroit, LOW);
}

void avancer(int v) {
  digitalWrite(sensMGauche, LOW);
  analogWrite(puissanceGauche, v);
  digitalWrite(marcheGauche, HIGH);
  digitalWrite(sensMDroit, HIGH);
  analogWrite(puissanceDroit, v);
  digitalWrite(marcheDroit, HIGH);
}

byte acquisition() {
  LFD = digitalRead(linefinderDroite);
  LFG = digitalRead(linefinderGauche);
  LFC = digitalRead(linefinderCentre);

  if (LFG == 1 && LFC == 1 && LFD == 1) {
    return 6;
  } else if (LFG == 1 && LFC == 1 && LFD == 0) {
    return 2;
  } else if (LFG == 0 && LFC == 1 && LFD == 1) {
    return 1;
  } else if (LFG == 0 && LFC == 0 && LFD == 1) {
    return 1;
  } else if (LFG == 1 && LFC == 0 && LFD == 0) {
    return 2;
  } else if (LFG == 0 && LFC == 0 && LFD == 0) {
    return 5;
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
      allerdroite(AFOND);
      break;
    case 4:
      allergauche(AFOND);
      break;
    case 5:
      arret(nul);
      break;
    case 6:
      avancer(AFOND);
      break;
    default:
      arret(nul);
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
