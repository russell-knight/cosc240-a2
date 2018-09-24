//
// Created by thirdeyechai on 24/09/18.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char word[50];

int main(int argc, char* argv[]) {

    // To run the program requires a word to search and at least one file to search through
    if (argc < 3) {
        printf("Error! Incorrect number of command-line arguments passed to program!\n"
               "Check README for help on how to use the program\n");
    }

    strcpy (word,argv[1]); // assign search word to global variable

    for (int i = 2; i < argc; i++) {

        int result;
        const char *filename = argv[i];
        result = access(filename, F_OK);

        if (result == 0) {
            printf("%s exists!!\n",filename);
        }
        else {
            printf("ERROR: %s doesn't exist!\n",filename);
        }
    }




    return 0;
}
