#include <wiringPi.h>
#include <iostream>
#include <unistd.h>

#define FEU_ROUGE_GPIO 33
#define FEU_ORANGE_GPIO 35
#define FEU_VERT_GPIO 37

void toggleLight(int gpioPin) {
    digitalWrite(gpioPin, HIGH);
    delay(1000); // Wait for 1 second with the light on
    digitalWrite(gpioPin, LOW);
    delay(1000); // Wait for 1 second with the light off
}

int main() {
    wiringPiSetupGpio();

    pinMode(FEU_ROUGE_GPIO, OUTPUT);
    pinMode(FEU_ORANGE_GPIO, OUTPUT);
    pinMode(FEU_VERT_GPIO, OUTPUT);

    while (1) {
        std::cout << "Testing Red Light..." << std::endl;
        toggleLight(FEU_ROUGE_GPIO);

        std::cout << "Testing Orange Light..." << std::endl;
        toggleLight(FEU_ORANGE_GPIO);

        std::cout << "Testing Green Light..." << std::endl;
        toggleLight(FEU_VERT_GPIO);
    }

    return 0;
}

