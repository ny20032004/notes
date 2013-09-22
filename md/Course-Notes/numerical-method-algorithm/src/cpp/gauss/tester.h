#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "gauss.h"

// define a type in order to initial a array without any parameters.
typedef Gauss* GaussArray;

// define the root directory of test data
const string TEST_DIR_ROOT = "../../test_data/";


// @defgroup Tester Gauss:Tester
// @author  Lyd.
// @version 2013/4/6
// @{
// This class read a format file which store the informations of
//  matrix A and b.
class GaussTester
{
private:
    // The path of nput format file.
    string in_file;

    // File to output.
    string out_file;

    // Objects of Gauss.
    GaussArray* objs;

    // Number of Objects.
    int test_case;

public:
    // Constructor
    //  string in_file   path of file to read.
    //  string out_file  path to output result.
    GaussTester(string in_file, string out_file);

    // Read information from input file,
    //  and build a list of Gauss objects in objs.
    // The format of input file:
    //  First line: number of test cases
    //   each case:
    //   number of x
    //   each number of matrix A
    //   each number of matrix b
    // Example:
    // 2
    // 3
    // 1.0 -0.4 -0.3
    // -0.3 0.9 -0.2
    // -0.2 -0.1 0.8
    // 60000 30000 50000
    // 3
    // 1.0e-8 2.0 3.0
    // -1.0 3.712 4.623
    // -2.0 1.072 5.643
    // 1.0 2.0 3.0
    void read();

    // Write result into output file.
    // Format:
    //  each line is the result of each case.
    void write();
};
// @}

// Constructor
//  string in_file   path of file to read.
//  string out_file  path to output result.
// The format of input file:
//  First line: number of test cases
//   each case:
//   number of x
//   each number of matrix A
//   each number of matrix b
GaussTester::GaussTester(string in_file, string out_file)
{
    this->in_file = TEST_DIR_ROOT + in_file;
    this->out_file = TEST_DIR_ROOT + out_file;
}


// Read information from input file,
//  and build a list of Gauss objects in objs.
// The format of input file:
//  First line: number of test cases
//   each case:
//   number of x
//   each number of matrix A
//   each number of matrix b
// Example:
// 2
// 3
// 1.0 -0.4 -0.3
// -0.3 0.9 -0.2
// -0.2 -0.1 0.8
// 60000 30000 50000
// 3
// 1.0e-8 2.0 3.0
// -1.0 3.712 4.623
// -2.0 1.072 5.643
// 1.0 2.0 3.0
void GaussTester::read()
{
    ifstream infile(in_file.c_str(), ios::in);
    int i, j;
    int number_of_x;
    infile >> test_case;
    objs = new GaussArray[test_case];
    for(i=0;i<test_case;++i)
    {
        infile >> number_of_x;
        double* A = new double[number_of_x * number_of_x];
        double* b = new double[number_of_x];
        for(j=0;j<number_of_x * number_of_x;++j)
        {
            infile >> A[j];
        }
        for(j=0;j<number_of_x;++j)
        {
            infile >> b[j];
        }
        objs[i] = new Gauss(A, b, number_of_x);
    }
}


// Write result into output file.
// Format:
//  each line is the result of each case.
void GaussTester::write()
{
    ofstream outfile(out_file.c_str(), ios::out);

    // Set output format.
    outfile << setprecision(PRECISION) << setiosflags(ios::fixed);
    cout << setprecision(PRECISION) << setiosflags(ios::fixed);

    int i, j;
    for(i=0;i<test_case;++i)
    {
        // Gaussian elimination with maximal column pivoting.
        double* x_maximal_column = objs[i]->gaussian_elimination_with_maximal_column_pivoting()->solve();

        outfile << "Gaussian elimination with maximal column pivoting." << endl;
        cout << "Gaussian elimination with maximal column pivoting." << endl;
        
        for(j=0;j<objs[i]->get_total();++j)
        {
            outfile << x_maximal_column[j] << "\t";
            cout << x_maximal_column[j] << "\t";
        }

        outfile << endl;
        cout << endl;

        // Gaussian elimination without maixmal column pivoting.
        double* x = objs[i]->gaussian_elimination()->solve();
        
        outfile << "Gaussian elimination without maximal column pivoting." << endl;
        cout << "Gaussian elimination without maximal column pivoting." << endl;

        for(j=0;j<objs[i]->get_total();++j)
        {
            outfile << x[j] << "\t";
            cout << x[j] << "\t";
        }
        outfile << endl << endl;
        cout << endl << endl;
    }
}
