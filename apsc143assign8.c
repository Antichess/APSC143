#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float randomize(float min, float max); // declare all the needed functions
float accelerate(float m, float q);
float deflect(float m, float q, float v);
void checkPath(float n, float a[][3], float curr);

int main() {
    srand(2); // declare srand seed as 2
    printf("Enter number of trials:");
    int n; // n is number of trials
    scanf("%d",&n);
    float m, q, r, v; // m is mass, q is charge, r is radius, v is velocity
    float a[n][3]; // declare the array as n x 3
    for (int i = 0; i < n; i++) { // for loop for n times
        m = randomize(0.001,1.08); // randomize mass
        q = randomize(1.00,9.00); // randomize charge
        printf("Trial %d: %.3f kg, %.3f C\n",i+1,m,q); // print out the mass and charge
        v = accelerate(m,q); // get the velocity
        printf("Accelerated to %.3f m/s\n",v); // print out the velocity
        r = deflect(m,q,v); // get the deflection
        printf("Deflection radius of %.3f m\n",r); // print out the deflection
        a[i][0] = m; // set the column as the values
        a[i][1] = q;
        a[i][2] = r;
        checkPath(n,a,r); // check if it's a new biggest deflection
    }
}

float randomize(float min, float max) {
    return ((float)rand() / RAND_MAX) * (max-min) + min; // code copied from the example in assignment 8
}
float accelerate(float m, float q) { 
    return sqrt(2*q*randomize(0.013,2.827)/m); // rearranged from qV = mv^2 for v
}
float deflect(float m, float q, float v) {
    return (m*v*v)/(q*v*randomize(0.058,1.603)); // rearranged from qvB = mv2^ / r for r
}
void checkPath(float n, float a[][3], float curr) {
    float max; // set maximum
    for (int k = 0; k < n; k++) { 
        if (a[k][2] > max) { // if the current one being checked is bigger than the max,
            max = a[k][2]; // set it as the max
        }
    }
    if (curr == max) { // if the most recent item is the maximum,
        printf("New largest deflection radius!\n"); // print out new largest
    }
}1