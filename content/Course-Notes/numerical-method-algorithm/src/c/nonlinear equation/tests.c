#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "public.h"
#include "newton.h"
#include "newton_downhill.h"
#include "dichotomy.h"
#include "secant.h"

int main(){

    struct funcArgs* args;


    // args = createArgs();
    // double r = calculateFunc(1.0, args->coefficient, args->maxTimes);
    // assert (r == -2.0);
    // free(args);


    // args = (funcArgs*) malloc(sizeof(funcArgs));
    // args->maxTimes = 5;
    // args->coefficient = (double*) malloc((5 + 1) * sizeof(double));
    // args->coefficient[0] = -1;
    // args->coefficient[1] = 1;
    // args->coefficient[2] = 0;
    // args->coefficient[3] = -3;
    // args->coefficient[4] = 0;
    // args->coefficient[5] = 1;
    // double* section = getSection(args, -8, 8);
    // assert(section[0] == 3);
    // assert(section[1] == -2);
    // assert(section[2] == -2);
    // assert(section[3] == 3);
    // free(args);


    // args = (funcArgs*) malloc(sizeof(funcArgs));
    // args->maxTimes = 3;
    // args->coefficient = (double*) malloc((3 + 1) * sizeof(double));
    // args->coefficient[0] = 5;
    // args->coefficient[1] = 7;
    // args->coefficient[2] = 2;
    // args->coefficient[3] = 4;

    // calculateDerivative(args);

    // assert(args->derivativeCoefficient[0] == 7);
    // assert(args->derivativeCoefficient[1] == 4);
    // assert(args->derivativeCoefficient[2] == 12);
    // free(args);


    args = (funcArgs*) malloc(sizeof(funcArgs));
    args->maxTimes = 5;
    args->coefficient = (double*) malloc((5 + 1) * sizeof(double));
    args->coefficient[0] = -1.0;
    args->coefficient[1] = 1.0;
    args->coefficient[2] = 0.0;
    args->coefficient[3] = -3.0;
    args->coefficient[4] = 0.0;
    args->coefficient[5] = 1.0;
    args->sectionStart = -8;
    args->sectionEnd = 8;

    calculateDerivative(args);

    printf("%lf\n", dichotomy(-8.0, -1.3, args));
    printf("%lf\n", dichotomy(-1.6, 1.6, args));
    printf("%lf\n", dichotomy(1.6, 8, args));
    // assert(dichotomy(0.0, 8.0, args) - (1.690284) < PRECISION);

    double* root = (double*) malloc( (5+1) * sizeof (double));
    root[0] = 0; // Initial
    double* result = getSection(args, 5, root);

    // for(int i=0;i<result[0];++i){
        // printf("%lf\n", secant(args, result[i], result[i] + 0.1));
    // }

    // printf("\n");
    
    // for(int i=0;i<root[0];++i){
    //     printf("%lf\n", root[i+1]);
    // }

    printf("\n");
    printf("%lf\n", newton(args, result[1]));
    printf("%lf\n", newton(args, result[2]));
    printf("%lf\n", newton(args, result[3]));

    // printf("\n");
    // printf("%lf\n", newton_downhill(args, result[1]));
    // printf("%lf\n", newton_downhill(args, result[2]));
    // printf("%lf\n", newton_downhill(args, result[3]));


    return 1;

}