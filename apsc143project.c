#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void check(int r, int c, int g[][10], int v[][10]);
void reveal(int r, int c, int g[][10], int v[][10]);
void flag(int r, int c, int v[][10]);
void printGrid(int v[][10]);
int count(int v[][10]);


int main() {

    srand(2); // set random seed to 2
    int l = 10; // length of the grid is 10, l is going to be the variable
    int g[l][l]; // g is the grid with the mines
    int v[l][l]; // v is the visible grid, the ones that the player has revealed
    // 9 denotes not revealed yet
    // 10 denotes a mine
    // 11 denotes a flag
    int mines = 10; // the number of mines should be 10. this is going to be used as a benchmark
    for (int i = 0; i < mines;) {
        int x = rand() % l; // set two random
        int y = rand() % l;
        if (g[x][y] != 10) { // if they don't overlap,
            g[x][y] = 10; // set this to a mine
            i++; // add one to the counter
        }
    }
    for (int i = 0; i < l; i++) { // make everything a 9, 9 is not revealed yet
        for (int j = 0; j < l; j++) {
            v[i][j] = 9; 
        }
    }
    char s[2]; // s is the input
    int r,c; // r is row input, c is column input
    int mine = 0; // mine is going to be set as 1 if a mine has been hit
    while (mine == 0 && count(v) < 90) { // while a mine has not been hit, and the count of the mines revealed is less than 90,
        printGrid(v); // print the grid out
        printf("Enter 'c' for check cell, 'f' for flag cell.\n");
        printf("Enter command & cell row col:");
        scanf("%s %d %d", &s, &r, &c); // scan for the c or f, and row and col
        printf("\n"); 
        if (strcmp(s,"c") == 0) { // if the letter is c,
            check(r,c,g,v); // check if it is a mine. makes the cell the number of mines around it
            if (v[r][c] == 0) { // if the current cell being checked is 0, which would've been set by the check from the line above
                reveal(r,c,g,v); // reveal the cells around it, recursively
            } else if (v[r][c] == 10) { // else if the cell is a mine,
                mine = 1; // set the mine as 1, which will start the process of ending the game
            } 
            if (mine == 1) { // if mine detected
                printGrid(v); // print grid one last time
                printf("You hit a mine, game over."); // game over
            }
            if (count(v) >= 90) { // else if 90 cells have been revealed (all but the 10 mines)
                printGrid(v); // print grid one last time
                printf("Congratulations! You win!"); // print you win
            }
        } else { // else if the letter is not c (assume it is f because autograder will never put a wrong input), 
            flag(r,c,v); // flag the cell
        }
    }
}

void check(int r, int c, int g[][10], int v[][10]) { // check function to see how many mines are around the current checked cell
    int sum = 0; // how many mines there are around it
    if (g[r][c] != 10) { // if the current cell is not a mine, 
        for (int i = -1; i < 2; i++) { // loop around the cell in a 3x3 grid having the cell being checked as the center
            for (int j = -1; j < 2; j++) {
                if (10 > r+i && r+i > -1 && 10 > c+j && c+j > -1) { // check if that the addition is not out of bounds, if it it then do nothing
                    if (g[r+i][c+j] == 10) { // if the cell around it is a mine, then add one to the sum
                        sum++;
                    }
                }
            }
        }
        v[r][c] = sum; // set the current cell as the amount of mines around it
    } else { // else if the current one is a mine, then set the cell as a mine, or 10
        v[r][c] = 10;
    }
}

void reveal(int r, int c, int g[][10], int v[][10]) { // if the cell that was just checked was 0,
    for (int i = -1; i < 2; i++) { // check all the other cells. 
        for (int j = -1; j < 2; j++) {
           if (10 > r+i && r+i > -1 && 10 > c+j && c+j > -1 && v[r+i][c+j] != 0) { // check that the new index is going to be valid
               check(r+i,c+j,g,v); // check the new index
               if (v[r+i][c+j] == 0) { // if that index is also zero, 
                   reveal(r+i,c+j,g,v); // recursively reveal around it
               }
           }
        }
    }
}

void flag(int r, int c, int v[][10]) { // flag cell
    if (v[r][c] == 9) { // if the current cell is a bomb
        v[r][c] = 11; // set as flag
    }
}

void printGrid(int v[][10]) { // print the grid
     for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (v[i][j] == 9) { // if the index is empty,
                    printf("*  "); // print star
                } else if (v[i][j] == 10) { // if the index is a mine,
                    printf("M  "); // print mine
                } else if (v[i][j] == 11) { // if the index is a flag,
                    printf("F  "); // print flag
                } else {
                    printf("%d  ", v[i][j]); // otherwise print the numbers
                }
            }
            printf("\n");
        }
}

int count(int v[][10]) { // count the number of cells that are revealed
    int c = 0; 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (v[i][j] != 9) { // if it isn't 9, which means if it's revealed
                c++; // add one to the count
            }
        }
    }
    return c; // return the count
}
