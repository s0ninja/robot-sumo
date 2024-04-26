#define X A0                                                                        
#define Y A1

int joy_X;
int joy_Y;

#define Roue_GAUCHE 4          //Roue Gauche à la branche 4
#define Roue_DROIT 5          //Roue Droit à la branche 5

const int vitesseMinimal = 50;
const int vitesseMoyenne = 180;
const int vitesseModérée = 210;
const int vitesseMaximale = 255;

void setup() {
  pinMode(Roue_GAUCHE);
  pinMode(Roue_DROIT);
  Serial.begin(9600);               // Initialisation du moniteur série (vitesse)
  pinMode(Roue_GAUCHE, OUTPUT);     // La broche de contrôle du moteur est en sortie du côté Gauche
  pinMode(Roue_DROIT, OUTPUT);     // La broche de contrôle du moteur est en sortie du côté Droit

}

void loop() {

  joy_X = analogRead(X);  // acquisition de position du joystick sur l'axe X | stockée dans la variable joy_X (position sur axe X comprise entre 200 et 700)
  joy_Y = analogRead(Y);  //acquisition de position du joystick sur l'axe Y | stockée dans la variable joy_Y (position sur axe Y comprise entre 200 et 700)
    if joy_X = analogRead(X); {
      
    } else {

    }
}
