#ifndef _NEWTON
#define _NEWTON

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "public.h"

// 牛顿
double newton(struct funcArgs* args, double beginWith){

    int i;

    double tempResult;
    double difference = 9999;
    double result = beginWith;

    for(i=0; i < MAX_ITERATE_TIMES && difference > PRECISION ;++i){
        tempResult = calculateFunc(result, args->coefficient, args->maxTimes);
        tempResult = tempResult / calculateFunc(result, args->derivativeCoefficient, args->maxTimes-1);
        result = result - tempResult;
        difference = fabs(tempResult);
    }

    return result;

}

#endif