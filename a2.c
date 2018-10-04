//
// Created by Russell Knight
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

char word[100];

/**
 * findWord searches a file for an instance of a given string
 * @param word - the word to search for
 * @param file - the file to search through
 * @returns 1 if found, 0 if not found, 255 if error*/

int findWord(char *word, char *file){
    char line[1024];
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        return 255; // error file not found
    }
    while (fgets(line, sizeof(line) , fp )!= NULL)
    {
        if (strstr(line, word )!= NULL)
        {
            return 1; // word found!
        }
    }
    return 0; // word not found
}

int main(int argc, char* argv[]) {

    // To run, the program requires a word to search for and at least one file to search through
    if (argc < 3) {
        printf("Error! Incorrect number of command-line arguments passed to program!\n"
               "Check README for help on how to use the program\n");
    }

    strcpy (word,argv[1]); // assign search word to variable

    for (int i = 2; i < argc; i++) {

        int result; // stores value returned from findWord function
        int status;
        pid_t child;
        child = fork();

        if (child) {
            //Parent process
            if (-1 == wait(&status)) {
                printf("No child to wait for.");
            }
            else if (WIFEXITED(status)) {
                // if child exits with 1 then word was found so we print the file name
                if (WEXITSTATUS(status) == 1) {
                    printf("%s\n", argv[i]);
                }
                else { // word was not found so we move on
                    continue;
                }
            }
            else {
                printf("Child exited abnormally.");
            }
        }
        else {
            // Child process
            result = findWord(word, argv[i]);
            return result;
        }
    }

    return 0;
}
