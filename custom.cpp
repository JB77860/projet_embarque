#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
using namespace std;

int main(){
    cout << "Hello world\n";
    wiringPiSetupGpio();

    // Declaration des dells comme OUTPUT
    pinMode(13, OUTPUT); // rouge
    pinMode(19, OUTPUT); // orange
    pinMode(26, OUTPUT); // vert
    pinMode(20, INPUT);
    // Test des diodes
    digitalWrite(13, HIGH);
    digitalWrite(19, HIGH);
    digitalWrite(26, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(19, LOW);
    digitalWrite(26, LOW);
   
    while(true){
        if(digitalRead(20)) {
            digitalWrite(26, HIGH);
            digitalWrite(19, LOW);
            digitalWrite(13, LOW);
        } else {
            digitalWrite(19, HIGH);
            digitalWrite(13, LOW);
            digitalWrite(26, LOW);
        }
    }
   return 0;
}
