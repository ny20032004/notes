#ifndef _SECANT
#define _SECANT

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "public.h"

// 弦截法
double secant(struct funcArgs* args, double beginWith, double lastBeginWith){

    double difference = 9999;
    double result = beginWith;
    double lastResult = lastBeginWith;

    for(int i=0; i < MAX_ITERATE_TIMES && difference > PRECISION; ++i){
        double fxk = calculateFunc(result, args->coefficient, args->maxTimes);
        double fxks1 = calculateFunc(lastResult, args->coefficient, args->maxTimes);
        double tempResult = fxk * (result - lastResult);
        tempResult = tempResult / (fxk - fxks1);
        lastResult = result;
        result = result - tempResult;
        difference = fabs(tempResult);
    }

    return result;

}

#endif