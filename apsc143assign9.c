#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float getVelocity(float w[], float v, int n); // declare functions
float getIntensity(float w[], float v, int n);

int main() {
    float w[12] = {-0.03, -0.18, 0.34, 0, -0.23, -0.31, 0.18, 0.03, -0.08, -0.21, -0.10, 0.25}; // w is the hardcoded values for the array
    float i, v; // i is max intensity, v is max velocity
    printf("Enter max relative intensity & wave velocity:");
    scanf("%f %f", &i, &v); // input
    printf("Vibrations have max initial velocity of %.3f m/s\n",getVelocity(w,v,0)); // outputs, directly call it
    printf("Blast site has max relative intensity of %.3f",i+getIntensity(w,v,11)); // the intensity is added at the end here   

}

float getVelocity(float w[], float v, int n) {
    if (n < 12) { // if it's in range of the function, 0 - 11;
        return getVelocity(w,v/(1+w[n]),n+1); // return the array, velocity divided by the modifier, and then add one to the index
    } else {
        return v; // return the velocity if it's at the building
    }
}
float getIntensity(float w[], float v, int n) {
    if (n >= 0) { // if it's in the range of the function, 11 - 0;
        return (n)/getVelocity(w,v,n) + getIntensity(w,v,n-1); // return the index (number of bands between) by the current velocity, and then
                                                               // recursively call the getintensity again
    } else {
        return 0; // otherwise if it's out of range (at the blast), add nothing to it and stop the recursion
    }
    
}