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
 * @param word the word to search for
 * @param file the file to search through*/
void findWord(char *word , char *file){
    char line[1024];
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        return;
    }
    while (fgets(line , sizeof(line) , fp )!= NULL)
    {
        if (strstr(line , word )!= NULL)
        {
            printf("%s\n", file);
            break;
        }
    }
}

int main(int argc, char* argv[]) {

    // To run the program requires a word to search and at least one file to search through
    if (argc < 3) {
        printf("Error! Incorrect number of command-line arguments passed to program!\n"
               "Check README for help on how to use the program\n");
    }

    strcpy (word,argv[1]); // assign search word to variable

    for (int i = 2; i < argc; i++) {

        pid_t child;
        child = fork();

        if (child) {
            //Parent process
            //printf("in parent\n");
        }
        else {
            findWord(word, argv[i]);
            _exit(1);
        }
    }

    return 0;
}
