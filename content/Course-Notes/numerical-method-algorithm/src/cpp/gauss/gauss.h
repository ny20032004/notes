#ifndef NM_GAUSS_H
#define NM_GAUSS_H

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

// A program used Gaussian elimination with maximal column pivoting to calculate equation set.
//
// Algorithm description:
//  1. For the first line, find the largest absolute 
//     value of each number in line, and exchange
//     the first row and the row contain the largest number.
//  2. Eliminate each row.
//  3. Repeat step one and two for each line.
//  4. To solve the equation set.
//

// precision
#define PRECISION 4
// control accuracy
#define EPS 1e-20


// @defgroup Gauss
// @author  Lyd
// @version 2013/4/6
// @{
// This class use gaussian elimination to calculate
//  a system of linear equations: Ax = b
class Gauss
{
private:
    // Matrix A;    
    double* A;

    // Matrix b
    double* b;

    // A copy of matrix A
    double* _A;

    // A copy of matrix b
    double* _b;

    // Total number of x
    int n;

    // Reset martix _A and _b
    void reset_A_b();

public:
    
    // Initial the object.
    //  double* A is the coefficient matrix.
    //  double* b is the result matrix.
    //  int n is the number of unknown variables.
    // Initial matrix x, which refers to the unknown variables.
    Gauss(double* A, double* b, int n);

    // Use Gaussian elimination with maximal column pivoting to calculate the result.
    Gauss* gaussian_elimination_with_maximal_column_pivoting();

    // Use gaussian elimination(without maximal column pivoting) to calculate the result.
    Gauss* gaussian_elimination();

    // Solve out the equation set.
    double* solve();

    // Return a integer
    //  the total number of x
    int get_total();

    // Print matrix A and b
    void print();

};
// @}


// Initial the object.
//  double* A is the coefficient matrix.
//  double* b is the result matrix.
//  int n is the number of unknown variables.
// Initial matrix x, which refers to the unknown variables.
Gauss::Gauss(double* input_A, double* input_b, int _n)
{
    this->A = input_A;
    this->b = input_b;
    this->n = _n;

    this->_A = new double[n*n];
    this->_b = new double[n];
}

void Gauss::print()
{
    int i, j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            cout << A[i*n + j] << " ";
        }
        cout << b[i] << " " << endl;
    }
    cout << endl;
}

// Reset matrix _A and _b
void Gauss::reset_A_b()
{
    int i, j, r;
    for(i=0;i<n;++i)
    {
        r = i*n;
        for(j=0;j<n;++j)
        {
            _A[r + j] = A[r + j];
        }
        _b[i] = b[i];
    }
}


// Use Gaussian elimination with maximal column pivoting to calculate the result.
Gauss* Gauss::gaussian_elimination_with_maximal_column_pivoting()
{

    int i, j, k, l;
    double temp;

    // Reset _A and _b
    reset_A_b();

    // define a integer to record the index of each line's max absolute value.
    int principal_element_index;

    // defina a double to record the max absolute value of each line.
    double principal_element;

    // In this loop, the matrix will be eliminated.
    for(i=0;i<n;++i)
    {
        // Begin calculate the max (absolute) number of each
        // line, called principal element.
        principal_element_index = i;
        principal_element = _A[i + n * principal_element_index];

        for(j=i+1;j<n;++j)
        {
            if(fabs(principal_element) < fabs(_A[i + n * j]))
            {
                principal_element = _A[i + n * j];
                principal_element_index = j;
            }
        }
        // Finished calculting the principal element

        // Ensure the pricinple element larger enough.
        if(fabs(_A[principal_element_index * n + i]) < EPS)
        {
            cout << "No limited solutions of equations." << endl;
            system("pause");
            exit(0);
        }

        // Exchange the rows.
        // Making a row contained pricinple element placed
        // at the first row.
        if(i != principal_element_index)
        {
            // Exchange matrix _A.
            for(l=i; l<n;++l)
            {
                temp = _A[i * n + l];
                _A[i * n + l] = _A[principal_element_index * n + l];
                _A[principal_element_index * n + l] = temp;
            }

            // Exchange matrix b.
            temp = _b[i];
            _b[i] = _b[principal_element_index];
            _b[principal_element_index] = temp;
        }

        // Eliminate matrix.
        double m;
        for(j=i+1;j<n;++j)
        {
            m = _A[j * n + i] / _A[i * n + i];
            for(k=i;k<n;++k)
            {
                _A[j * n + k] = _A[j * n + k] - m * _A[i * n + k];
            }
            _b[j] = _b[j] - m * _b[i];
        }

    }
    
    return this;
}


// Use gaussian elimination(without maximal column pivoting) to calculate the result.
Gauss* Gauss::gaussian_elimination()
{

    int i, j, k, l;

    // Reset _A and _b
    reset_A_b();

    // In this loop, the matrix will be eliminated.
    for(i=0;i<n;++i)
    {
        // Eliminate matrix.
        double m;
        for(j=i+1;j<n;++j)
        {
            m = _A[j * n + i] / _A[i * n + i];
            for(k=i;k<n;++k)
            {
                _A[j * n + k] = _A[j * n + k] - m * _A[i * n + k];
            }
            _b[j] = _b[j] - m * _b[i];
        }
    }

    return this;
}


double* Gauss::solve()
{
    int j, k;

    if (_A[n-1 * n + n-1] == 0)
    {
        cout << "The value of Matrix determinant is zero!" << endl;
        system("pause");
        exit(-1);
    }

    // Begin to solve the equation set.

    _b[n-1] = _b[n-1] / _A[(n-1) * n + (n-1)];
    // Be careful!
    // Don't make the stupid mistake!:
    //  _A[n-1 * n + n-1];

    for(k=n-2;k>=0;--k)
    {
        for(j=n-1;j>k;--j)
        {
            _b[k] = _b[k] - _A[k * n + j] * _b[j];
        }
        _b[k] = _b[k] / _A[k * n + k];
    }

    return _b;
}

// Return total number of x
int Gauss::get_total()
{
    return n;
}

#endif
