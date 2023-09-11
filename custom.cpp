#include <iostream>
#include <wiringPi.h>
#include <unistd.h> // pour utilisation fonction exit()
#include <signal.h> // pour catcher le signal de fermeture du programme
using namespace std;

// Fonction de gestion de l'extinction des diodes en fin de programme
void cleanup(int sig) {
    cout << "\nFin du programme\n";
    digitalWrite(13, LOW);
    digitalWrite(19, LOW);
    digitalWrite(26, LOW);
    exit(0);
}

int main(){
    cout << "Debut du programme de détection\n"; 
    wiringPiSetupGpio();

    // Initialisation du compteur
    int compteur = 0;

    // Initialisation des dells comme OUTPUT
    pinMode(13, OUTPUT); // rouge
    pinMode(19, OUTPUT); // orange
    pinMode(26, OUTPUT); // vert

    // Initialisation du detecteur de mouvement comme INPUT 
    pinMode(20, INPUT);

    // Test des diodes
    digitalWrite(13, HIGH);
    digitalWrite(19, HIGH);
    digitalWrite(26, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(19, LOW);
    digitalWrite(26, LOW);
    
    // Recupère le signal de fermeture du programme
    signal(SIGINT, cleanup);

    while(true){
        if(digitalRead(20)) {
            // si pas de detection, reinitialisation du compteur à 0
            compteur = 0;

            // Fonctionnement initial, diode vert ON, autres OFF
            digitalWrite(26, HIGH);
            digitalWrite(19, LOW);
            digitalWrite(13, LOW);

        } else {
 	    digitalWrite(26, LOW);
	    if(compteur >= 7) {
                // Allumage diode ROUGE quand detection continue
                digitalWrite(13, HIGH);
                digitalWrite(19, LOW);
            } else {
                // Allumage diode Jaune quand detection ponctuelle
                digitalWrite(19, HIGH);
            }
        compteur++;
        delay(300);
        }
    }
   return 0;
}
