#include "filter.h"
#include "base.h"

Filter::Filter(int n, int div, int* matrix){
    num = n;
    division = div;
    templateMatrix = matrix;
}

int Filter::filterAround(BmpFile* file, int x, int y){
    int total = 0;  
    int step = file->step;
    int channels = file->channels;
    int xStart = x - num/2 * channels;
    int yStart = y - num/2;
    for (int i=0; i<num; ++i){
        for (int j=0; j<num; ++j){
            int xOffset = xStart + j * channels;
            int yOffset = yStart + i;
            int index = yOffset * step + xOffset;
            int filterValue = templateMatrix[i * num + j];
            total += file->pData[index] * filterValue;
        }
    }
    return total;
}

void Filter::filter(BmpFile* sBmp, BmpFile*& dBmp){
    int step = sBmp->step;
    int start = num / 2;
    int channels = sBmp->channels;
    int width = sBmp->infoHead.width;
    int height = sBmp->infoHead.height;
    for (int y=start; y<height-start; ++y){
        for (int x=start; x<width-start;++x){
            for (int k=0;k<sBmp->channels;++k){
                int xOffset = x * channels + k;
                int index = y * step + xOffset;
                int filteredValue = filterAround(sBmp, xOffset, y);
                dBmp->pData[index] = filteredValue / division;
            }
        }
    }
}