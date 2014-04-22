#ifndef _DICHOTOMY
#define _DICHOTOMY

#ifndef PRECISION
#define PRECISION 1e-6
#endif

// 二分法
double dichotomy(double startWith, double endWith, struct funcArgs* args)
{
    double mid;
    double startValue, midValue, endValue;
    double start = startWith;
    double end = endWith;
    startValue = calculateFunc(start, args->coefficient, args->maxTimes);
    endValue = calculateFunc(end, args->coefficient, args->maxTimes);
    while(fabs(end - start) > PRECISION)
    {
        mid = (end + start) / 2.0;
        midValue = calculateFunc(mid, args->coefficient, args->maxTimes);

        if(midValue * endValue <= 0)
        {
            start = mid;
        }else{
            end = mid;
            endValue = calculateFunc(end, args->coefficient, args->maxTimes);
        }
        
    }

    mid = (start + end) / 2.0;

    return mid;
}

#endif