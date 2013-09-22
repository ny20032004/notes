#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "public.h"
#include "dichotomy.h"
#include "newton.h"
#include "newton_downhill.h"
#include "secant.h"


void run(char* method, char* input, char* output){

    printf("Params:\n method: %s\t inputFile: %s\t outputFile: %s\n\n",
           method, input, output);

    // Get data from input file.
    struct funcArgs *equation = loadFromFile(input);

    // Define a double pointer to store the roots when section the region.
    double* root = (double*) malloc((equation->maxTimes+1) * sizeof (double));
    // Initial the number of roots;
    root[0] = 0;

    double* section = getSection(equation, equation->maxTimes, root);

    if (root[0] > 0){
        printf("There are %d root(s) found when calculate the section.\n", (int)root[0]);
        for(int i=1;i<root[0]+1;++i){
            printf("Root %d: %lf\t", i, root[i]);
        }
    }
    printf("\n");
    printf("\n");

    if (section[0] > 0){
        printf("There are %d section(s) found when calculate the section.\n", (int)section[0]);
        for(int i=1;i<section[0]+1;++i){
            printf("Section %d: %lf\t", i, section[i]);
        }
    }

    printf("\n");
    printf("\n");
    
    
    if (strcmp(method, "dichotomy") == 0){
        printf("Using dichotomy method:\n");
        printf("%lf\n", dichotomy(equation->sectionStart, section[1], equation));
        for(int i=1;i<section[0]+1;++i){
            printf("%lf\n", dichotomy(section[i], section[i+1], equation));
        }
        printf("%lf\n", dichotomy(section[(int)section[0]-1], equation->sectionEnd, equation));
    }
   

    if (strcmp(method, "newton") == 0){
        printf("Using newton method:\n");
        for(int i=1;i<section[0]+1;++i){
            printf("%lf\n", newton(equation, section[i]));
        }
    }

    if (strcmp(method, "newton_downhill") == 0){
        printf("Using newton_downhill method:\n");
        for(int i=1;i<section[0]+1;++i){
            printf("%lf\n", newton_downhill(equation, section[i]));
        }
    }

    if (strcmp(method, "secant") == 0){
        printf("Using secant method:\n");
        for(int i=0;i<section[0]+1;++i){
            printf("%lf\n", secant(equation, section[i], section[i] + 0.1));
        }
    }

    // Analyse param method
    if (strcmp(method, "all") == 0){
        printf("Using dichotomy method:\n");
        // // printf("%lf\n", dichotomy(equation->sectionStart, section[1], equation));
        // for(int i=1;i<section[0];++i){
        //     printf("%lf\n", dichotomy(section[i], section[i+1], equation));
        // }
        // // printf("%lf\n", dichotomy(section[(int)section[0]-1], equation->sectionEnd, equation));


        printf("%lf\n", dichotomy(-8.0, -1.6, equation));
        printf("%lf\n", dichotomy(-1.6, 1.6, equation));
        printf("%lf\n", dichotomy(1.6, 8.0, equation));

        printf("\n");


        printf("Using newton method:\n");
        for(int i=1;i<section[0]+1;++i){
            printf("%lf\n", newton(equation, section[i]));
        }
        printf("\n");

        printf("Using newton_downhill method:\n");
        for(int i=1;i<section[0]+1;++i){
            printf("%lf\n", newton_downhill(equation, section[i]));
        }
        printf("\n");

        printf("Using secant method:\n");
        for(int i=0;i<section[0]+1;++i){
            printf("%lf\n", secant(equation, section[i], section[i] + 0.1));
        }
    }

}


// @param -m: The method to calculate the equation.
//  Chosen in [dichotomy, newton, newton_downhill, secant, all]
// @param -i: The path of input data file.
// @param -o: The path of output file.
int main(int args, char* argv[]){

    // Define a string to store the method user chose to use.
    char method[16] = "all";

    // Define a string to store the input data file's path.
    char inputFile[100] = "./data/input.txt";

    // Define a string to store the path where results output.
    char outputFile[100] = "./result.txt";

    for(int i=0;i<args; ++i)
    {
        // -m means method
        if (strcmp(argv[i], "-m") == 0){
            strcpy(method, argv[i + 1]);
            continue;
        }

        // -i means the path of input file.
        if (strcmp(argv[i], "-i") == 0){
            strcpy(inputFile, argv[i + 1]);
        }

        // -o means the path of output file.
        if (strcmp(argv[i],  "-o") == 0){
            strcpy(outputFile, argv[i + 1]);
        }
    }

    run (method, inputFile, outputFile);

    return 1;

}