#ifndef _PUBLIC 
#define _PUBLIC

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define MAX_ITERATE_TIMES 20
#define SECTION 160
#define PRECISION 1e-6

struct funcArgs{
    int maxTimes;
    double* coefficient;
    double* derivativeCoefficient;
    double sectionStart;
    double sectionEnd;
};

// 导数
void calculateDerivative(struct funcArgs* args){

    int i;
    args->derivativeCoefficient = (double*) malloc(args->maxTimes *
                                                   sizeof(double));
    memset(args->derivativeCoefficient, 0, args->maxTimes*sizeof(double));

    for(i=0;i<args->maxTimes;++i)
        args->derivativeCoefficient[i] = args->coefficient[i + 1] * (i + 1);

}

struct funcArgs* loadFromFile(char* inputFile){

    struct funcArgs* args = (funcArgs*) malloc(sizeof(funcArgs));
    args->coefficient = (double*) malloc(((args->maxTimes) + 1) * sizeof(double));

    // The max times of the equation.
    int maxTimes;
    
    FILE *dataFile;

    if ((dataFile = fopen(inputFile, "r")) == NULL){
        printf("Cannot open file.\n");
        exit(1);
    }

    fscanf(dataFile, "%d", &args->maxTimes);

    printf("maxTimes: %d\n", args->maxTimes);

    // if(fread(&args->maxTimes, sizeof(int), 1, dataFile) != 1) {
    //     if(feof(dataFile)) {
    //         printf("Premature end of file when reading maxTimes.");
    //     }else {
    //         printf("File read error when reading maxTimes.");
    //     }
    // }

    args->coefficient = (double*) malloc(((args->maxTimes) + 1) * sizeof(double));

    for(int i=args->maxTimes; i>=0; --i){
        fscanf(dataFile, " %lf", &args->coefficient[i]);
        printf("Coefficient %d: %lf\t",i , args->coefficient[i]);
    }
   

    // if(fread(args->coefficient, sizeof(double), args->maxTimes + 1,
    //          dataFile) != (args->maxTimes + 1)) {
    //     if(feof(dataFile)) {
    //         printf("Premature end of file when reading coefficient.");
    //     }else{
    //         printf("File read error when reading coefficient.");
    //     }
    // }

    calculateDerivative(args);

    fscanf(dataFile, " %lf", &args->sectionStart);
    printf("\nsectionStart: %lf\t", args->sectionStart);
    // if(fread(&args->sectionStart, sizeof(double), 1, dataFile) != 1) {
    //     if(feof(dataFile)) {
    //         printf("Premature end of file when reading sectionStart.");
    //     }else {
    //         printf("File read error when reading sectionStart.");
    //     }
    // }

    fscanf(dataFile, " %lf", &args->sectionEnd);
    printf("\nsectionEnd: %lf\n\n", args->sectionEnd);
    // if(fread(&args->sectionEnd, sizeof(double), 1, dataFile) != 1) {
    //     if(feof(dataFile)) {
    //         printf("Premature end of file when reading sectionEnd.");
    //     }else {
    //         printf("File read error when reading sectionEnd.");
    //     }
    // }
    
    fclose(dataFile);
    
    return args;
}

void writeResult(struct funcArgs* args){

}

// 创建方程
struct funcArgs* createArgs(){
    
    int i;
    int maxTimes;

    printf("Please input the max times of equation: \n");
    scanf("%d", &maxTimes);

    struct funcArgs* args = (funcArgs*) malloc(sizeof(funcArgs));

    args->maxTimes = maxTimes;
    args->coefficient = (double*) malloc((maxTimes + 1) * sizeof(double));

    printf("Please input the coefficient of each times: \n");
    for(i=0;i<maxTimes+1;++i){
        scanf("%lf", &(args->coefficient[maxTimes-i]));
    }

    printf("The start of section: ");
    scanf("%lf", &args->sectionStart);

    printf("The end of section: ");
    scanf("%lf", &args->sectionEnd);

    calculateDerivative(args);
    return args;

}

// 计算函数
double calculateFunc(double x, double* coefficient, int maxTimes){

    int i;
    double result = 0.0;
    for(i=0;i<maxTimes+1;++i)
    {
        result += coefficient[i] * pow(x, i);
    }
    return result;

}

// 计算根区间
double* getSection(struct funcArgs* func, int maxSection, double* root){
    
    int total = 0;
    double step = (func->sectionEnd - func->sectionStart) / SECTION;
    double* section = (double*) malloc((maxSection + 1) * sizeof(double));

    for(double i=func->sectionStart; i<func->sectionEnd; i+=step){
        double frontResult = calculateFunc(i, func->coefficient,
                                           func->maxTimes);
        double behindResult = calculateFunc(i+step, func->coefficient,
                                            func->maxTimes);

        if(fabs(frontResult) <= PRECISION){
            int rootTotal = root[0];
            root[0] = ++rootTotal;
            root[rootTotal] = i;
            continue;
        }
        if (frontResult * behindResult < 0){
            total++;
            section[total] = i;
        }
    }
    section[0] = total;
    return section;
}


void printSet(int* ns, int n){
    int i;
    for(i=0;i<n;++i){
        printf("%d\t", n-i-1);
    }
    printf("\n");

    for(i=0;i<n;++i){
        printf("%d\t", ns[i]);
    }
    printf("\n\n");
}

#endif