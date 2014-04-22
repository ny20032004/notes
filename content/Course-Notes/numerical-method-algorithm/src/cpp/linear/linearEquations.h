#ifndef NM_LINEAR_EQUATIONS_H
#define NM_LINEAR_EQUATIONS_H

#include <iostream>
using namespace std;

class LinearEquation
{
private:

    // matrix A must be a triangular matrix.
    double* A;

    double* b;

    double* x;

    int n;

public:

    LinearEquation(double* A, double* b, int n):A(A), b(b), n(n){}

    void solve_upper();

    void solve_lower();

    double* getResult();

    void print_x();

};

void LinearEquation::solve_upper()
{

    if (this->A[n-1 * n + n-1] == 0)
    {
        cout << "The value of Matrix determinant is zero!" << endl;
    }

    int i, j;

    double* _b = new double[n];

    for(i=0;i<n;++i){
        _b[i] = this->b[i];
    }

    this->x = new double[n];

    this->x[n-1] = this->b[n-1] / this->A[(n-1) * n + (n-1)];
    
    for(i=n-2;i>=0;--i)
    {
        for(j=n-1;j>i;--j)
        {
            _b[i] = _b[i] - this->A[i * n + j] * this->x[j];
        }
        this->x[i] = _b[i] / this->A[i*n + i];
    }
}

void LinearEquation::solve_lower()
{
    int i, j;

    double* _b = new double[n];
    for(i=0;i<n;++i)
        _b[i] = this->b[i];

    this->x = new double[n];

    this->x[0] = this->b[0] / this->A[0];

    for(i=1;i<n;++i)
    {
        for(j=0;j<i;++j)
        {
            _b[i] = _b[i] - this->A[i * n + j] * this->x[j];
        }
        
        this->x[i] = _b[i] / this->A[i*n + i];
    }
}

void LinearEquation::print_x()
{
    int i;
    for(i=0;i<n;++i)
    {
        cout << "x" << i << ": " << this->x[i] << endl;
    }
}

double* LinearEquation::getResult()
{
     return this->x;
}

#endif
