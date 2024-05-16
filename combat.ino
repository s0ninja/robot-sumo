// à faire: bouton marche/arret, débraillage et priorités

//ENTRÉES/SORTIES NUMÉRIQUES          
      //connecter le RIP des deux LEDs
          //leds
            #define ledRouge 5
            #define ledBleu 3 

      //connecter le RIP du bouton de marche arret à la broche logique D2
            #define bp A2
      
          //module bluetooth : 
            #define RxD 7 //le module bluetooth est raccordé à la broche D7 de la base shield
            #define TxD 8 //le module bluetooth est raccordé à la broche D7 de la base shield
            #include <SoftwareSerial.h> //appel de la bibliothèque qui permettra de "simuler" notre laision série
            
          //Initialisation de la communication série avec le module Bluetooth
            SoftwareSerial blueTooth(RxD,TxD);//initialisation de la communication sur deux broches digitales
            char octet_recu = 'M'; //carctère ASCII non étendu (128 caractères) qui reçoit les trames émises

      //connecter les 6 entrées de l'interface de puissance L298 
      //sont connectés via le "shield" aux pins suivants
          // moteur gauche
            #define sensMGauche 12
            #define freinGauche 9
            #define vitesseGauche 3
          // moteur droit
            #define sensMDroit 13
            #define freinDroit 8
            #define vitesseDroit 11

            //déclaration des variables
            bool etatbp = 0;
            byte AFOND = 80, nul = 0;
            

void setup(){
  //initialisation des pins de sortie
  //Setup moteurgauche
  pinMode(sensMGauche, OUTPUT); //Initialise la broche  "sens de rotation moteur gauche" 
  pinMode(freinGauche, OUTPUT);  //Initialise la broche   "mise en rotation" du moteur Gauche
  //Setup moteurdroite
  pinMode(sensMDroit, OUTPUT); //Initialise la broche  "sens de rotation moteur droit" 
  pinMode(freinDroit, OUTPUT);  //Initialise la broche  "mise en rotation" du moteur droit  

  //Module Bluetooth
  pinMode(RxD, INPUT);//on initilise la broche Rx de la liaison série en entrée
  pinMode(TxD, OUTPUT);//on initilise la broche Tx de la liaison série en sortie
  setupBluetooth();//initialise la communication blueTooth, voir détails ci-dessous

  //boutonMarche
  pinMode(bp, INPUT);
         
  //affichage moniteur série
  Serial.begin(9600);
}

void setupBluetooth()//fonction permettant d'initialiser notre module bluetooth en mode "reception"
{ 
  //les instructions suivantes sont necessaires au bon fonctionnement du module
  blueTooth.print("AT");//commande permettant d'entrer dans les réglages de notre module
  delay(400); 
  blueTooth.print("AT+DEFAULT"); //paramétrage des réglages d'origines
  delay(400); 
  blueTooth.print("AT+ROLES"); //le module bluetooth est en mode "reception" (SLAVE)
  delay(400); 
  blueTooth.print("AT+BAUD4");  //réglage de la vitesse de transmission
  delay(400);
  blueTooth.begin(9600); //réglage de la vitesse de transmission
  delay(400); 
  blueTooth.flush();//attente de la fin du message
}

void recevoir(){//fonction permettant de lire les caractères reçus par le module
  if (blueTooth.available()) {//si un caractère est émis sur la liaison bluetooth
   octet_recu=blueTooth.read();//on stocke le caractère dans la variable octet_recu
   blueTooth.flush();//attente de la fin de transmission sur la liaison série
   Serial.print("le caractère reçu est : ");
   Serial.println(octet_recu);//on affiche le caractère reçu
   Serial.print("la valeur décimale correspondant au carctère reçu (table ASCII) est :");
   Serial.println(int(octet_recu));//on affiche la valeur décimale correspondant au carctère reçu (table ASCII)
  }
}

void avance(int v){
  //Serial.println("J'avance");
  //commande MCC gauche
  digitalWrite(sensMGauche, HIGH); 
  digitalWrite(freinGauche, LOW);   
  analogWrite(vitesseGauche, v);
  //commande MCC droit
  digitalWrite(sensMDroit, LOW);
  digitalWrite(freinDroit, LOW);   
  analogWrite(vitesseDroit, v);
}
void recule(int v){
  //Serial.println("Je recule");
  //commande MCC gauche
  digitalWrite(sensMGauche, LOW); 
  digitalWrite(freinGauche, LOW);   
  analogWrite(vitesseGauche, v);
  //commande MCC droit
  digitalWrite(sensMDroit, HIGH); 
  digitalWrite(freinDroit, LOW);   
  analogWrite(vitesseDroit, v); 
}
void tourneGauche(int v){
  //Serial.println("Je tourne à gauche en avançant");
  //commande MCC gauche
  digitalWrite(sensMGauche, LOW); 
  digitalWrite(freinGauche, LOW);   
  analogWrite(vitesseGauche, v);
  //commande MCC droit
  digitalWrite(sensMDroit, LOW);
  digitalWrite(freinDroit, LOW);   
  analogWrite(vitesseDroit, 0);
}
void tourneDroite(int v){
  //Serial.println("J'avance");
  //commande MCC gauche
  digitalWrite(sensMGauche, HIGH); 
  digitalWrite(freinGauche, LOW);   
  analogWrite(vitesseGauche, 0);
  //commande MCC droit
  digitalWrite(sensMDroit, HIGH);
  digitalWrite(freinDroit, LOW);  
  analogWrite(vitesseDroit, v);
}
void arret(int v){
  //Serial.println("Je stoppe");
  digitalWrite(freinDroit, HIGH);   //Frein engagé moteur droit
  digitalWrite(freinGauche, HIGH);   //Frein engagé moteur gauche
  digitalWrite(vitesseGauche, LOW);  //vitesse des deux moteurs à 0
  digitalWrite(vitesseDroit, LOW);
}

void marche(int v){
  digitalWrite(freinDroit, HIGH);   //Frein désactivé moteur droit
  digitalWrite(freinGauche, HIGH);   //Frein désactivé moteur gauche
  digitalWrite(vitesseGauche, LOW);  //vitesse des deux moteurs à 0
  digitalWrite(vitesseDroit, LOW);
}

void pivoterDroite(int v){
  //commande des deux moteurs pour pivoter à droite
  digitalWrite(sensMGauche, HIGH); 
  digitalWrite(freinGauche, LOW);   
  analogWrite(vitesseGauche, v);
  digitalWrite(sensMDroit, HIGH); 
  digitalWrite(freinDroit, LOW);
  analogWrite(vitesseDroit, v);
}

void pivoterGauche(int v){
  //commande des deux moteurs pour pivoter à gauche
  digitalWrite(sensMGauche, LOW); 
  digitalWrite(freinGauche, LOW);   
  analogWrite(vitesseGauche, v);
  digitalWrite(sensMDroit, LOW); 
  digitalWrite(freinDroit, LOW);
  analogWrite(vitesseDroit, v);
}

void loop() {
  recevoir();
  
  if (digitalRead(bp) == HIGH) { // Si le bouton est enfoncé
    if (octet_recu == 5) { //stop
      arret(AFOND)  ;
    } 
    else if (octet_recu == 6) { //marche
      marche(nul);
    } 
    else if (octet_recu == 2) { //go
      avance(AFOND);
    } 
    else if (octet_recu == 1) { //back
      recule(AFOND);
    } 
    else if (octet_recu == 3) { //droite
      tourneDroite(AFOND);
    } 
    else if (octet_recu == 4) { //gauche
      tourneGauche(AFOND);
    }
  } else { // Si le bouton est relâché, arrêter les moteurs
    arret(AFOND) ;
  }
}
