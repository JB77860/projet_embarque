#include <iostream>
#include <pigpio.h>
#include <unistd.h> // for exit() function
#include <signal.h> // for catching program termination signal

#include <thread>
#include <chrono>


using namespace std;

// Function to handle LED cleanup on program termination
void cleanup(int sig) {
    cout << "\nProgram termination\n";
    gpioWrite(13, PI_LOW);
    gpioWrite(19, PI_LOW);
    gpioWrite(26, PI_LOW);
    gpioTerminate();
    exit(0);
}

int main() {
    cout << "Starting the motion detection program\n";

    if (gpioInitialise() < 0) {
        cerr << "pigpio initialization failed." << endl;
        return 1;
    }

    // Initialize the counter
    int compteur = 0;

    // Set LEDs as OUTPUT
    gpioSetMode(13, PI_OUTPUT); // red
    gpioSetMode(19, PI_OUTPUT); // orange
    gpioSetMode(26, PI_OUTPUT); // green

    // Set motion detector as INPUT
    gpioSetMode(20, PI_INPUT);

    // Test the LEDs
    gpioWrite(13, PI_HIGH);
    gpioWrite(19, PI_HIGH);
    gpioWrite(26, PI_HIGH);
    sleep(1);
    gpioWrite(13, PI_LOW);
    gpioWrite(19, PI_LOW);
    gpioWrite(26, PI_LOW);

    // Capture the termination signal
    signal(SIGINT, cleanup);

    while (true) {
        if (gpioRead(20)) {
            // If no motion detection, reset the counter to 0
            compteur = 0;

            // Initial operation: green LED ON, others OFF
            gpioWrite(26, PI_HIGH);
            gpioWrite(19, PI_LOW);
            gpioWrite(13, PI_LOW);
        } else {
            gpioWrite(26, PI_LOW);
            if (compteur >= 7) {
                // Turn on the red LED for continuous detection
                gpioWrite(13, PI_HIGH);
                gpioWrite(19, PI_LOW);
            } else {
                // Turn on the orange LED for intermittent detection
                gpioWrite(19, PI_HIGH);
            }
            compteur++;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));

        }
    }

    gpioTerminate();
    return 0;
}
