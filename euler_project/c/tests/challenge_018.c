//
// Created by sadount on 09/10/2023.
//
#include <stdio.h>
#include <stdlib.h>


int main() {

    FILE *fptr;
    fptr = fopen("misc/challenge_018.txt","r");


    int n_lines = 15;
    int **lines = calloc(n_lines, sizeof(int*));


    for (int i = 0; i < n_lines; i++) {
        *(lines + i) = calloc(i, sizeof(int));
        for (int j = 0; j <= i; j++) {
            fscanf(fptr, "%i", *(lines + i) + j);
            printf("%i", *(*(lines + i) + j));
        }
    }


    return EXIT_SUCCESS;
}
