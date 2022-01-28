#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE* fr; // declare fr as the file reading variable
    FILE* fw; // declare fw as the file writing variable
    fr = fopen("parts.txt","r"); // prepare to read the file parts.txt
    fw = fopen("orders.txt","w"); // prepare to write to the file orders.txt
    int n; // n is the number of parts there is, hence the first line of parts.txt

    fscanf(fr,"%d", &n); // read the first line of parts.txt and assign it as n

    float **f = malloc(sizeof * f * n); // create a dynamic array of size n
    for (int i = 0; i < n; i++) {
        f[i] = malloc(sizeof *f[i] * 4); // in each of those elements in the array, make it so that each element will have four elements inside it
    }

    for (int x = 0; x < n; x++) { // for each line in the parts.txt (we know how many lines there will be afterward)
        fscanf(fr, "%f %f %f", &f[x][0], &f[x][1], &f[x][2]); // assign the three numbers as element 0, 1, and 2 in each array
        f[x][3] = f[x][1] * f[x][2]; // calculate the third column, which is just the price multiplied by the quantity
        printf("%.0f %.2f %.0f %.2f\n", f[x][0], f[x][1], f[x][2], f[x][3]); // print out everything in the console
    }

    float temp[4]; // we will use temp as a buffer because it is needed for sorting with bubble sort

    for (int i = 0; i < n-1; i++) { // bubblesort
        for (int j = 0; j < n-i-1; j++) { // n-i-1 for max efficiency
            if (f[j][3] > f[j+1][3]) { // if current element is bigger than the next one, swap it
                // i couldn't think of a better way to swap it. it sucks how c isn't dynamic like python
                // (where you could just do temp = f[x]) but this is all i could think of, or at least i could find
                temp[0] = f[j][0]; temp[1] = f[j][1]; temp[2] = f[j][2]; temp[3] = f[j][3]; // swapping
                f[j][0] = f[j+1][0]; f[j][1] = f[j+1][1]; f[j][2] = f[j+1][2]; f[j][3] = f[j+1][3];
                f[j+1][0] = temp[0]; f[j+1][1] = temp[1]; f[j+1][2] = temp[2]; f[j+1][3] = temp[3]; 
            }
        }
    }
    printf("Serial / Price / Units / Total\n"); // print out the first "row"
    fprintf(fw, "%s", "Serial / Price / Units / Total\n"); // write it to the text file
    
    for (int x = 0; x < n; x++) { // for the amount of rows there is,
    printf("%.0f %.2f %.0f %.2f\n", f[x][0], f[x][1], f[x][2], f[x][3]); // print it out to the console, then
        fprintf(fw, "%.0f %.2f %.0f %.2f\n", f[x][0], f[x][1], f[x][2], f[x][3]); // write it to the text file
    }
    free(f); // free the mem

}