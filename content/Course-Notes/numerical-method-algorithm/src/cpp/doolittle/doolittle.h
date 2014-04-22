#ifndef NM_DOOLITTLE_H
#define NM_DOOLITTLE_H

#include <iostream>
#include <math.h>
#include <memory.h>
#include "../linear/linearEquations.h"
using namespace std;

// precision
#define PRECISION 4
// control accuracy
#define EPS 1e-20


// @defgroup Doolittle
// @author  Lyd
// @version 2013/4/9
// @{
// This class use doolittle to calculate
//  a system of linear equations: Ax = b
class Doolittle
{

private:

    // define a matrix of A;
    double *A;

    // define a matrix of b;
    double *b;

    // define a matrix x, to store solution of equation set.
    double *x;

    // the number of x;
    int n;

    // Dootitle use desperate A into L and U. 
    //  It is  A = LU.
    // And, there will be:
    //   Ly = b
    //   Ux = y

    // define a matrix y
    double *y;

    // define a matrix L
    double *L;

    // define a matrix U
    double *U;

public:
    
    Doolittle(double* _A, double* _b, int _n);

    void desperate();

    void solve();

    int get_total(){ return n; }

    double* getResult(){ return this->x; }

};

Doolittle::Doolittle(double* _A, double* _b, int _n)
{
    this->A = _A;
    this->b = _b;
    this->n = _n;
}

void Doolittle::desperate()
{
    this->y = new double[n];
    this->L = new double[n*n];
    this->U = new double[n*n];

    int i, r, k;
    double sigma;

    // 初始化矩阵所有值都为 0  否则会出错！！
    memset(L, 0, n*n * sizeof(double));
    memset(U, 0, n*n * sizeof(double));

    // Set first row of matrix U.
    // 设置 L 的对角线
    for(i=0;i<n;++i)
    {
        this->U[i] = this->A[i];
        this->L[i*n + i] = 1;
    }

    // Set first column of matrix L.
    for(i=1;i<n;++i)
    {
        this->L[i*n] = this->A[i*n] / this->U[0];
    }

    for(r=1;r<n;++r)
    {

        // U
        for(i=r;i<n;++i)
        {
            sigma = 0.0;
            for(k=0;k<r;++k)
            {
                sigma += this->L[r*n + k] * this->U[k*n + i];
            }
            this->U[r*n + i] = this->A[r*n + i] - sigma;
        }

        // L
        for(i=r+1;i<n;++i)
        {
            sigma = 0.0;
            for(k=0;k<r;++k)
            {
                sigma += this->L[i*n + k] * this->U[k*n + r];
            }
            this->L[i*n + r] = (this->A[i*n + r] - sigma) / this->U[r*n + r];
        }
    }
    
}

void Doolittle::solve()
{

    // Ly = b;
    LinearEquation e_L(this->L, this->b, n);
    e_L.solve_lower();
    this->y = e_L.getResult();

    // Ux = y;
    LinearEquation e_U(this->U, this->y, n);
    e_U.solve_upper();
    this->x = e_U.getResult();

}

#endif
