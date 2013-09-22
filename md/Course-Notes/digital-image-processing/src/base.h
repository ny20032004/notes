#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class BmpFile
{
public:

    class BmpFileHead
    {
        public:
        char type1;
        char type2;
    };

    class BmpInfoHead
    {
    public:
        unsigned int    imageSize;
        unsigned int    blank;
        unsigned int    startPosition;
        unsigned int    length;
        unsigned int    width;
        unsigned int    height;
        unsigned short  colorPlane;
        unsigned short  bitColor;
        unsigned int    zipFormat;
        unsigned int    realSize;
        unsigned int    xPels;
        unsigned int    yPels;
        unsigned int    colorUse;
        unsigned int    colorImportant;
    };

    struct RGBA
    {
        unsigned char G;
        unsigned char B;
        unsigned char R;
        unsigned char A;
    };

    int step;
    int channels;

    BmpFileHead fileHead;
    BmpInfoHead infoHead;
    unsigned char *pData;

    BmpFile();
    BmpFile(const char*);

    void loadFile(const char*);

    int saveAsFile(const char*);
    int saveAs(BmpFile*&);

    void transport_x();
    void transport_y();

    void inverse();
    void decolourize();
    void binaryzation();
    void histogram();

};

#endif