#include <iostream>
#include <fstream>
#include <string>
#include "doolittle.h"

// define a type in order to initial a array without any parameters.
typedef Doolittle* DoolittleArray;

// define the root directory of test data
const string TEST_DIR_ROOT = "../../test_data/";


// @defgroup Tester Doolittle:Tester
// @author  Lyd.
// @version 2013/4/9
// @{
// This class read a format file which store the informations of
//  matrix A and b.
class DoolittleTester
{
private:
    // The path of nput format file.
    string in_file;

    // File to output.
    string out_file;

    // Objects of Gauss.
    DoolittleArray* objs;

    // Number of Objects.
    int test_case;

public:
    // Constructor
    //  string in_file   path of file to read.
    //  string out_file  path to output result.
    DoolittleTester(string in_file, string out_file);

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
    // 4
    // 2 10 0 -3
    // -3 -4 -12 13
    // 1 2 3 -4
    // 4 14 9 -13
    // 10 5 -2 7
    // 3
    // 1 -1 3
    // 2 -4 6
    // 4 -9 2 
    // 1 4 1
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
DoolittleTester::DoolittleTester(string in_file, string out_file)
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
// 4
// 2 10 0 -3
// -3 -4 -12 13
// 1 2 3 -4
// 4 14 9 -13
// 10 5 -2 7
// 3
// 1 -1 3
// 2 -4 6
// 4 -9 2 
// 1 4 1
void DoolittleTester::read()
{
    ifstream infile(in_file.c_str(), ios::in);
    int i, j;
    int number_of_x;
    infile >> test_case;
    objs = new DoolittleArray[test_case];
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
        objs[i] = new Doolittle(A, b, number_of_x);
    }
}


// Write result into output file.
// Format:
//  each line is the result of each case.
void DoolittleTester::write()
{
    ofstream outfile(out_file.c_str(), ios::out);
    outfile << setprecision(PRECISION) << setiosflags(ios::fixed);
    int i, j;
    for(i=0;i<test_case;++i)
    {
        objs[i]->desperate();
        objs[i]->solve();
        double* x = objs[i]->getResult();
        for(j=0;j<objs[i]->get_total();++j)
        {
            outfile << x[j] << "\t";
        }
        outfile << endl << endl;
    }
}
