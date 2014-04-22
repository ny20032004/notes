#ifndef _NEWTON_DOWNHILL
#define _NEWTON_DOWNHILL

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "public.h"


// 牛顿下山法
double newton_downhill(struct funcArgs* args, double beginWith){

    double lambda = 1.0;
    double lastResult = beginWith;
    double result;
    double currentSolution, currentDervicativeSolution;
    double nextSolution;
    double difference;

    while(1){

        currentSolution = calculateFunc(result, args->coefficient,
                                        args->maxTimes);
        currentDervicativeSolution = calculateFunc(result,
                                                   args->derivativeCoefficient,
                                                   args->maxTimes);

        result = lastResult - ((lambda * currentSolution) /
                               currentDervicativeSolution);

        difference = fabs(result - lastResult);

        nextSolution = calculateFunc(result, args->coefficient, args->maxTimes);

        if (fabs(nextSolution) < fabs(currentSolution)){
            if (difference < PRECISION){
                return result;
            }else{
                lastResult = result;
                continue;
            }
        }else{
            if (lambda > PRECISION && fabs(nextSolution) > PRECISION){
                lambda = lambda / 2;
                continue;
            }else{
                if (lambda < PRECISION && fabs(nextSolution) < PRECISION){
                    return result;
                }else{
                    printf("Please change a input.");
                    return 0;
                }
            }
        }
    }

}

#endif