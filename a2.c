//
// Created by thirdeyechai on 24/09/18.
//

#include <stdio.h>
#include <string.h>

char word[50];

int main(int argc, char* argv[]) {

    if (argc < 3) {
        printf("Error! Incorrect number of command-line arguments passed to program!\n"
               "Check README for help on how to use the program\n");
    }

    strcpy (word,argv[1]); // assign search word to global variable



    return 0;
}
