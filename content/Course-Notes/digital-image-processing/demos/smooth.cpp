#include "../src/base.h"
#include <iostream>
#include "../src/filter.h"
using namespace std;

int main(int argc, char* argv[])
{

    //读入图像
    BmpFile pGrayBmpFile("lena.gray.bmp");
    BmpFile pRGBBmpFile("lena.rgb.bmp");

    BmpFile* dGrayBmp;
    BmpFile* dRBGBmp;

    pGrayBmpFile.saveAs(dGrayBmp);
    pRGBBmpFile.saveAs(dRBGBmp);

    int* averageFilterMatrix = new int[3 * 3];
    memset(averageFilterMatrix, 1, 9);
    Filter averageFilter(3, 9, averageFilterMatrix);
    averageFilter.filter(&pGrayBmpFile, dGrayBmp);
    averageFilter.filter(&pRGBBmpFile, dRBGBmp);

    dGrayBmp->saveAsFile("gray.average.filter.bmp");
    dRBGBmp->saveAsFile("rgb.average.filter.bmp");

    int* gaussianFilterMatrix = new int [3 * 3]{1, 2, 1, 2, 4, 2, 1, 2, 1};
    Filter guassianFilter(3, 16, gaussianFilterMatrix);
    guassianFilter.filter(&pGrayBmpFile, dGrayBmp);
    guassianFilter.filter(&pRGBBmpFile, dRBGBmp);

    dGrayBmp->saveAsFile("gray.guassian.filter.bmp");
    dRBGBmp->saveAsFile("rgb.guassian.filter.bmp");

    return 0;
}
