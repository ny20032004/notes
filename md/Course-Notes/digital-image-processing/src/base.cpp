#include "base.h"

BmpFile::BmpFile(){

}

BmpFile::BmpFile(const char* filename)
{
    pData = NULL;
    loadFile(filename);
}

void BmpFile::loadFile(const char* filename)
{
    FILE * p;
    int modbytes;

    if( !filename || strlen(filename) == 0 )
    {
        fprintf(stderr, "null filename\n");
        return ;
    }

    p = fopen(filename, "rb");

    if(!p)
    {
        fprintf(stderr, "Can not open file %s\n", filename);
        return ;
    }

    //fread(&bmpfilehead, sizeof(BmpFileHead), 1, p);
    //Read the first two bytes of bmp file, which must be "B" and "P".
    //sizeof(BmpFileHead) == 4 is true in some Operating Sysytem,
    //so it is not right to use the statement above, and it should be:
    fread(&(fileHead), 2, 1, p);

    //Read head information of bmp file
    fread(&(infoHead), sizeof(BmpInfoHead), 1, p);

    //If if the first two bytes if not "BM", we can assert this file is not a BMP file.
    if((fileHead.type1 != 'B' && fileHead.type1 != 'b') ||
       (fileHead.type2 != 'M' && fileHead.type2 != 'm'))
    {
        fprintf(stderr, "The file is not a BMP file" );
        fclose(p);
        return ;
    }

    //Check for the bmp file.
    //bitColor = 8, if the file is gray bmp.
    //bitColor = 24, if the file is rgb bmp.
    channels = infoHead.bitColor / 8;
    if( channels != 1 && channels != 3)
    {
        fprintf(stderr, "Only 1 or 3 channels images can be loaded." );
        fclose(p);
        return ;
    }

    //validate the rationality of height and width.
    if(infoHead.width <= 0 || infoHead.height <=0)
    {
        fprintf(stderr, "Bad image size");
        fclose(p);
        return ;
    }

    //Each line bytes must be the multiple of 4.
    modbytes = (infoHead.width * channels) % 4;
    step = modbytes ? ((infoHead.width * channels) - modbytes + 4) : (infoHead.width * channels);

    pData = new unsigned char[step * infoHead.height];

    //seek the begin of data area.
    fseek(p, infoHead.startPosition, SEEK_SET);

    //Read the data of bmp file.
    //BMP store data from the bottom of file, so transform the data into the 
    // normal form which look like a matrix.
    for(int idx=infoHead.height-1; idx >= 0 ; idx--)
    {
        int n = fread(pData + step*idx, step, 1, p);
        if(n!=1)
        {
            fprintf(stderr, "read image data error.\n");
            break;
        }
    }
    fclose(p);
}

int BmpFile::saveAsFile(const char* filename)
{
    if(!pData)
    {
        cout << "Have not loaded any file" << endl;
        return -1;
    }

    FILE * p;

    if( !filename || strlen(filename) == 0 )
    {
        fprintf(stderr, "null filename\n");
        return -1;
    }

    p = fopen(filename, "wb");

    if(!p)
    {
        fprintf(stderr, "Can not create file" );
        return -1;
    }

    //Write the head information of file.
    fwrite(&(fileHead), sizeof(BmpFileHead), 1, p);
    fwrite(&(infoHead), sizeof(BmpInfoHead), 1, p);

    //Write data into the file.
    if(channels == 1)
    {
        RGBA rgba;
        for(int idx =0; idx<256; idx++)
        {
            rgba.R=idx;
            rgba.G=idx;
            rgba.B=idx;
            rgba.A = 0;
            fwrite(&rgba, sizeof(RGBA), 1, p);
        }
    }

    // Write data.
    for(int idx = infoHead.height-1; idx >=0 ; idx--)
    {
        fwrite(pData + step * idx, step, 1, p);
    }

    fclose(p);

    return 0;
}

int BmpFile::saveAs(BmpFile*& dBmp){
    dBmp = new BmpFile();
    memcpy(dBmp, this, sizeof(BmpFile));
    dBmp->pData = new unsigned char[step * infoHead.height];
    memcpy(dBmp->pData, pData, step * infoHead.height);
    return 0;
}

void BmpFile::transport_x()
{
    if(!pData)
    {
        cout << "Have not loaded any file" << endl;
        return ;
    }

    int i, j, k;
    int temp;

    for(i=0;i<infoHead.height;i++){
        for(j=0;j < step / 2 ;j++){
            temp = pData[i * step + j];
            pData[i * step + j] = pData[i * step + step - j - 1];
            pData[i * step + step - j - 1] = temp;
        }
        for(j=0;j<step / channels;j++){
            for(k=0;k< channels / 2;k++){
                temp = pData[i * step + channels * j + k];
                pData[i * step + channels * j] = pData[i * step + channels * j + channels - k - 1];
                pData[i * step + channels * j + channels - k - 1] = temp;
            }
        }
    }
}

void BmpFile::transport_y()
{
    if(!pData)
    {
        cout << "Have not loaded any file" << endl;
        return ;
    }

    int i, j;
    int temp;
    for(i=0; i<infoHead.height/2; i++){
        for(j=0; j<step; j++){
            temp = pData[i * step + j];
            pData[i * step + j] = pData[(infoHead.height - i - 1) * step + j];
            pData[(infoHead.height - i - 1) * step + j] = temp;
        }
    }
}

void BmpFile::inverse()
{
    if(!pData)
    {
        cout << "Have not loaded any file" << endl;
        return ;
    }
    int i;
    for(i=0; i<infoHead.height*step; i++)
    {
        pData[i] = 255 - pData[i];
    }
}

// decolurize
void BmpFile::decolourize()
{
    if(!pData)
    {
        cout << "Have not loaded any file" << endl;
        return ;
    }

    if(channels != 3){
        cout << "Bmp file's channel must be 3" << endl;
        return ;
    }

    int i, j;
    unsigned char R, G, B;
    double Gray;
    unsigned char* newData = new unsigned char[infoHead.height * step / 3];
    int index = 0;
    for(i=0; i<infoHead.height; i++){
        for(j=0; j<step; j+=3){
            R = pData[i * step + j + 2];
            G = pData[i * step + j + 1];
            B = pData[i * step + j];
            Gray = 0.299 * R + 0.587 * G + 0.114 * B;
            newData[index++] = (unsigned char)Gray;
        }
    }
    infoHead.bitColor = 8;
    channels = 1;
    int modbytes = (infoHead.width * channels) % 4;
    step = modbytes ? ((infoHead.width * channels) - modbytes + 4) : (infoHead.width * channels);
    pData = newData;
}


void BmpFile::binaryzation()
{

    if(channels == 3)
    {
        decolourize();
    }

    int n = infoHead.height * step;    // Total number of pixel.
    int n1;     // the pixel number which are larger than threshold.
    int n2;     // the pixel number which are smaller than threshold.
    int s1;     // total sum of pixel value which are large than threshold.
    int s2;     // total sum of pixel value which are smaller than threshold.
    double w1, w2;         // weght value
    double u1, u2;         // average
 
    double maxBetween = 0.0;
    double between;
    int threshold;
 
    for(int t=0; t<256; ++t)
    {
        n1 = 0;
        n2 = 0;
        s1 = 0;
        s2 = 0;
        for(int i=0; i<n; ++i)
        {
            if((int)pData[i] < t)
            {
                ++n1;
                s1 = s1 + (int)pData[i];
            }
            else
            {
                ++n2;
                s2 = s2 + (int)pData[i];
            }
        }
 
        w1 = (double)n1 / (double)n;
        w2 = (double)n2 / (double)n;
        u1 = (double)s1 / (double)n1;
        u2 = (double)s2 / (double)n2;
 
        between =  w1 * w2 * (u1 - u2) * (u1 - u2);
        
        if( n1 && n2 && maxBetween < between)
        {
            maxBetween = between;
            threshold = t;
        }  
       
    }
    for(int i=0; i<n; ++i)
    {
        pData[i] = pData[i] > threshold ? (char)255 : (char)0;
    }
}

void BmpFile::histogram(){
    int total = infoHead.height * step;
    int hist[256];
    memset(hist, 0, sizeof(hist));
    for (int i=0; i<total; ++i){
        hist[pData[i]]++;
    }
    for (int i=0; i<256; ++i){
        cout << i << ": " << hist[i] << endl;
    }
}