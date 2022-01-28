#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    char s[50]; // s is the string that will be inputted
    int curr, count; // declare current index and count
    char compare[8] = "LEXICON"; // compare is going to be declared as lexicon, or cipher that will be repeated
    int diff; // difference will calculate the difference between the lexicon word and the original message
    char message[50] = ""; // output message
    char buffer[1]; // buffer to use for strcat
    printf("Enter secret message: ");

    fgets(s, 50, stdin); // get input

    // string removal is embedded within the entire code. it's just controlled by an if statement in line 38

    for (int i = 0; i < strlen(s); i++) { // repeat the loop for the amount of characters that are in the original message
        if(s[i] >= 'A' && s[i] <= 'Z') { // if the current letter is capital, A-Z
            curr = count % 7; // this modulus function ensures that the lexicon will loop
            // for example, if count is 0, it will be at "L". if it's at 1, it will be at "E". same if it loops around. 7 is "L", and 8 is "E".
            // just a smarter way to repeat than to check against another array or something
            diff = (int)compare[curr]-(int)s[i]; // the difference is the keyword subtracted by the current letter in the original message
            if (diff < 0) { // if the difference is negative (i.e. the keyword is behind the letter in the original message)
                diff += 26; // add 26 so it can loop around. this works because adding a negative difference to the current letter works the same
            }
            if((diff + compare[curr]) > 90) { // if the difference plus the current letter is over 90 (meaning it is not a capital letter, invalid)
                buffer[0] = (char)((int)compare[curr] + diff - 26); // make encrypted letter, difference to current letter and subtract by 26 to make it not overflow
                strncat(message,&buffer[0],1); // concat to final message
            } else if ((diff + compare[curr]) < 90) { // if the difference plus the current letter is under 90 (meaning it is a capital letter, valid)
                buffer[0] = (char)((int)compare[curr] + diff); // make encrypted letter, difference to current letter
                strncat(message,&buffer[0],1);
            } else { // else if the letter is the same as the keyword
                buffer[0] = (char)(s[i]); // the encrypted letter is the same
                strncat(message,&buffer[0],1);
            }
            count++; // add one to the count, because "LEXICON" must repeat
        } else if (s[i] != 32) {  // if the character is not a string (meaning it is just added on)
            buffer[0] = (char)(s[i]); // add the letter to the message without any modification
            strncat(message,&buffer[0],1);
        }
    }
    printf("*BEGIN_MESSAGE*\n%s\n*END_MESSAGE*\n",message); // print
}