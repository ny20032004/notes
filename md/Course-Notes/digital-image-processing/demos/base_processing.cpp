#include "../src/base.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

    //读入图像
    BmpFile pGrayBmpFile("lena.gray.bmp");
    BmpFile pRGBBmpFile("lena.rgb.bmp");

    //打印 "lena.gray.bmp 信息头中的宽度。
    cout << "Gray Image's Width: " << pGrayBmpFile.infoHead.width << endl;
    //打印 "lena.gray.bmp 信息头中的高度。
    cout << "Gray Image's Height: " << pGrayBmpFile.infoHead.height << endl;

    //打印 "lena.rgb.bmp 信息头中的宽度。
    cout << "RGB Image's Width: " << pRGBBmpFile.infoHead.width << endl;
    //打印 "lena.rgb.bmp 信息头中的高度。
    cout << "RGB Image's Height: " << pRGBBmpFile.infoHead.height << endl;
    cout << endl;
    

    int x = 37;
    int y = 60;

    //分别读出两幅图像里指定位置的像素值，赋值给下面四个变量
    unsigned char GRAY, R, G, B;

    // pData 用指针以二维矩阵形式保存，故 (x,y) 点的位置应该为 [(y * width) + x]。
    GRAY = pGrayBmpFile.pData[y * pGrayBmpFile.step + x];
    
    // RGB文件每个像素需 3 个存储单位来保存R、G、B的值
    // BMP 保存时 三色顺序为 BGR
    R = pRGBBmpFile.pData[y * pRGBBmpFile.step + (x * 3) + 2];
    G = pRGBBmpFile.pData[y * pRGBBmpFile.step + (x * 3) + 1];
    B = pRGBBmpFile.pData[y * pRGBBmpFile.step + (x * 3)];


    //在命令行打印从两幅图像读出的像素值
    cout << "Gray: " << (int)GRAY << endl;
    cout << "R: " << (int)R << endl;
    cout << "G: " << (int)G << endl;
    cout << "B: " << (int)B << endl;
    cout << endl;


    //按照实验报告模板要求，修改像素值，并使用SaveBMPImage函数保存到文件

    // 保存位置
    const char* new_gray_filename = "new.gray.generated.bmp"; 
    const char* new_rgb_filename = "new.rgb.generated.bmp";

    // 修改指定的值
    int gray_modify_position = y * pGrayBmpFile.step  + x;
    pGrayBmpFile.pData[gray_modify_position] = 0;
    pGrayBmpFile.saveAsFile(new_gray_filename);

    int rgb_modify_position[3] = {y * pRGBBmpFile.step + (x * 3) + 2,
                                  y * pRGBBmpFile.step + (x * 3) + 1,
                                  y * pRGBBmpFile.step + (x * 3)};
    pRGBBmpFile.pData[rgb_modify_position[0]] = 0;
    pRGBBmpFile.pData[rgb_modify_position[1]] = 0;
    pRGBBmpFile.pData[rgb_modify_position[2]] = 255;

    pRGBBmpFile.saveAsFile(new_rgb_filename);

    pGrayBmpFile.transport_x();
    pGrayBmpFile.saveAsFile("new_x.gray.generated.bmp");
    pGrayBmpFile.transport_x();

    pRGBBmpFile.transport_x();
    pRGBBmpFile.saveAsFile("new_x.rgb.generated.bmp");
    pRGBBmpFile.transport_x();

    pGrayBmpFile.transport_y();
    pGrayBmpFile.saveAsFile("new_y.gray.generated.bmp");
    pGrayBmpFile.transport_y();

    pRGBBmpFile.transport_y();
    pRGBBmpFile.saveAsFile("new_y.rgb.generated.bmp");
    pRGBBmpFile.transport_y();

    pGrayBmpFile.inverse();
    pGrayBmpFile.saveAsFile("inverse.gray.generated.bmp");
    pGrayBmpFile.inverse();

    pRGBBmpFile.inverse();
    pRGBBmpFile.saveAsFile("inverse.rgb.generated.bmp");
    pRGBBmpFile.inverse();

    pRGBBmpFile.decolourize();
    pRGBBmpFile.saveAsFile("decolourize.rgb.generated.bmp");

    return 0;
}

