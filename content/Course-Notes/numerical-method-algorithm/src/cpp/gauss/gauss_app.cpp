#include <iomanip>
#include <iostream>
#include <stdlib.h>

#include "gauss.h"
#include "tester.h"

using namespace std;

int main()
{

    GaussTester tester("gauss/input.txt", "gauss/output-cpp.txt");
    tester.read();
    tester.write();

    system("pause");
    return 1;
}
