#include<math.h>
#include<stdio.h>

int main() {
    float pi = 3.14159;
    float l, w, h;
    // define pi and the length, width, and height respectively
    printf("Enter length, width, height of box: ");
    scanf("%f%f%f", &l, &w, &h);
    // print message to scan the values, %f for float
    float vol = l * w * h;
    // calculate the volume of the box in cm3 by multiplying the three values
    printf("The box is %0.2f cm3\n", vol);
    // print the cm3 of the box
    int cookies = l / 1.8;
    cookies = cookies * 2;
    // to figure out how many cookies there were, i first figured out how much a stack of cookies were. I did this by dividing the length by 1.8, the height of a cookie.
    // i then casted it into an int, which floored it. i want to floor it in the case that multiplying it would produce an odd number.
    printf("%d cookies can fit into the box\n", cookies);
    float percent = (cookies * pi * 2.6 * 2.6 * 1.8) / vol * 100;
    // calculate the percentage of the box that is cookies by multiplying the number of cookies by it's volume, then dividing it by the volume. *100 for percentage
    float price = 1.23 * ((cookies * pi * 2.6 * 2.6 * 1.8) * 0.0082 + (l * w * 2 + w * h * 2 + l * h * 2) * 0.003);
    // calculate price
    printf("Cookies take up %0.2f%% of the box\n", percent);
    printf("The product price is $%0.2f", price);
}