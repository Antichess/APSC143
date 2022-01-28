#include<math.h>
#include<stdio.h>
#include<stdlib.h>


int main() {
    srand(2);
    int x;
    // int x = rand() % range + min;
    // seed the random number and set x as the value

    int roadNum;
    // number of roads that will be used
    float n, l, y;
    // number, length, year respectively
    printf("Enter number of roads:");
    scanf("%d",&roadNum);
    // scan for # of roads
    float roads[roadNum][3]; // roads array
    
    for (int i = 0; i < roadNum; i++) { // for loop that runs for roadnum times
        printf("Enter number, length, build year of road %d:", i+1); // scan the roads one by one now
        scanf("%f%f%f", &n, &l, &y);
        roads[i][0] = n;
        roads[i][1] = l;
        roads[i][2] = y;
        
    }
    float newRoads[roadNum][4]; // newRoads array

    float oldest  = roads[0][2]; // we need to find out the oldest road, so we will set the first road as the longest
    float oldestroadnum = roads[0][0]; // we need to store the oldest road number, so we will set the number as well
    float average = 0; // average length of roads

    for (int i = 0; i < roadNum; i++) { // for loop that runs for roadnum times
    // the main job of this loop is to figure out the oldest road, and then store values into newroads

        if (oldest > roads[i][2]) { // if the current oldest road year is bigger than the current one being compared,
            oldest = roads[i][2]; // set the current one being compared as the new oldest road
            oldestroadnum = roads[i][0]; // store the highway number as well
            
        }
        x = rand() % 1501 + 2000; // recalculate x
        newRoads[i][0] = roads[i][0]; // transfer over hwy num
        newRoads[i][1] = roads[i][1]; // transfer over length
        newRoads[i][2] = roads[i][2]; // transfer over year
        average = average + roads[i][1]; // add the current length to the running average
        newRoads[i][3] = pow(x,(2021/(roads[i][2]))) * roads[i][1]; // calculate the fourth value of newroads, or the road cost

    }
    
    average = average/roadNum; // now that all the values have been added up, divide it by the roadnum

    printf("Highway %d is the oldest road\n", (int)oldestroadnum); // print out the oldest road number
    printf("Average road length = %0.2f km\n", average); // print out the average road length

    for (int i = 0; i < roadNum; i++) { 
        if (newRoads[i][3] < 550000) { // if the road cost is under $550,000,
            printf("%d is a viable maintenance project\n", (int)newRoads[i][0]); // output it as a "viable maintenance project"
        }
    }
    
    // print out the first road in the list
    printf("Highway %d: %0.2f km, built in %d. Expected cost: $%0.2f\n", (int)newRoads[0][0], newRoads[0][1], (int)newRoads[0][2], newRoads[0][3]);

    // print out the last road in the list. we know that it is roadNum-1, because the indicies start at 0.
    printf("Highway %d: %0.2f km, built in %d. Expected cost: $%0.2f\n", (int)newRoads[roadNum-1][0], newRoads[roadNum-1][1], (int)newRoads[roadNum-1][2], newRoads[roadNum-1][3]);


}