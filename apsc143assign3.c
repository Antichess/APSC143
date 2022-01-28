#include<math.h>
#include<stdio.h>

int main() {
    printf("Enter time:");
    float t;
    // initializing the variable t, to substitute into the sine function
    scanf("%f",&t);
    // scan
    float i = fabs(sin(t/4)/6);
    // calculate the current with the sine function
    float v;
    // initialize voltage
    if (t > 0) { // if the circuit is active
        printf("The circuit is active\nCurrent circuit = %.3f A\n",i); // print the current
        if (t < 14.9) { // if the time is before 14.9 seconds
            v = (20+30) * i; // voltage is resistance multiplied by the current. the resistance is 20 + 30 because the led and resistor are both active
            printf("The switch is open\nCircuit voltage = %.3f V\n",v); // print switch is open
        } else { // else if the time is after 14.9 seconds
            v = 30 * i; // voltage is just 30 because the resistor is not active
            printf("The switch is closed\nCircuit voltage = %.3f V\n",v); // print switch is closed
        }
        if (v > 2.2 && v < 4.7) { // if the voltage is between 2.2 and 4.7
            printf("The LED is illuminated"); // print led is illuminated
        } else { // otherwise led is not illuminated
            printf("The LED is not illuminated");
        } // end of if statements for when the circuit is active


    } else { // else if the circuit is off,
        printf("The circuit is shut off"); // print the circuit is switched off
    }

    return 0;
}