#include<math.h>
#include<stdio.h>

int main() {
    printf("Enter initial ammonia & oxygen concentrations: ");
    float nh3, o2, n2, h2o; // initialize the variables for the products and reactants
    float k = 0.0114; // initialize k
    scanf("%f%f",&nh3,&o2); //scanf
    float nh3start = nh3; // initialize the variable that will store the initial value of nh3, will be used to output the last line
    float rate; // initialize rate
    float nh3rate, o2rate, n2rate, h2orate; // initialize the rate for the different products and reactants, this is what we will be using to subctract
    float avgh2orate; // average h2orate because the h2o is printed as an average
    int t = 0; // i am using integers for time because there are floating point errors.

    for (rate = 1; rate >= 0.04; t += 1) { // while the rate is bigger than 0.04. the rate is set as 1 to enter the loop, and add 1 to t every time
    // the program "ends" once rate is under 0.04, so this is why it is our while statement.


        if (t == 38) { // if t is 38, then print out the concentration of nh3 when it's 0.38s
            printf("Concentration of ammonia after 0.38s = %.3f mol/L\n", nh3);
        }
        rate = k * nh3 * o2 * o2; // recalculate rate
        nh3rate = rate * (4 * 0.01); // recalculate all the rate of changes according to the formula.
        o2rate = rate * (3 * 0.01);
        n2rate = rate * (2 * 0.01);
        h2orate = rate * (6 * 0.01);

        o2 -= o2rate; // subtract or add depending on what equation 2 says
        nh3 -= nh3rate;
        n2 += n2rate;
        h2o += h2orate;

        avgh2orate += h2o; // add the running average to the h2o
 
    }
    printf("%.2fs required for rate to drop below 0.040 mol/(L*s)\n",(float)t/100); // print time for nh3 to drop
    printf("Concentration of nitrogen gas after %.2fs = %.3f mol/L\n",(float)t/100,n2); // print n2 gas
    printf("Average concentration of water after %.2fs = %.3f mol/L\n",(float)t/100,avgh2orate/t); // print average concentration of water
    if ((nh3 / 2) < nh3start) { // if nitrogen is less than half of what it was when it started,
        printf("Reaction has passed 50%% completion\n"); // print it has passed 50% completion
    } else { // else,
        printf("Reaction has not passed 50%% completion\n"); // print it has not passed
    }


    return 0;
}