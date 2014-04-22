#include "../src/base.h"
#include <iostream>
using namespace std;

int compare(BmpFile one, BmpFile two)
{
    int n1 = one.infoHead.height * one.step;
    int n2 = two.infoHead.height * two.step;
    if(n1 != n2)
    {
        return -1;
        //error
    }

    int r=0;
    for(int i=0; i<n1; ++i)
    {
        r += (int)one.pData[i] ^ (int)two.pData[i];
    }
    return r;
    
}

int main()
{

    BmpFile origin_bmp("origin-rgb.bmp");
    BmpFile com_bmp_1("origin-rgb-1.bmp");
    BmpFile com_bmp_2("origin-rgb-2.bmp");
 
    origin_bmp.binaryzation();
    origin_bmp.saveAsFile("origin.binaryzation.generated.bmp");

    com_bmp_1.binaryzation(); 
    com_bmp_1.saveAsFile("compare.bmp.1.generated.bmp");
    

    com_bmp_2.binaryzation();
    com_bmp_2.saveAsFile("compare.bmp.2.generated.bmp");

    int c1 = compare(origin_bmp, com_bmp_1);
    int c2 = compare(origin_bmp, com_bmp_2);
 
    if(c1 < c2){
        cout << "similar: Pic1" << endl;
    }
    if(c1 == c2){
        cout << "Equal" << endl;
    }
    if(c1 > c2){
        cout << "similar: Pic2" << endl;
    }
    cout << "c1=" << c1 << " c2=" << c2 << endl;

    return 1;
}