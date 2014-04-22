#include <iomanip>
#include <iostream>
#include <stdlib.h>

#include "doolittle.h"
#include "tester.h"

using namespace std;

int main()
{
    // Set output format.
    cout << setprecision(PRECISION) << setiosflags(ios::fixed);

    DoolittleTester tester("doolittle/input.txt", "doolittle/output-cpp.txt");
    tester.read();
    tester.write();

    system("pause");
    return 1;
}
