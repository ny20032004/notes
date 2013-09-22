## BMP 图像的基本操作

### 结构定义
BMP 文件头 ( 2 Bytes, B and M)

    // Copyright Yu Shiqi
    typedef struct
    {
        char type1;
        char type2;
    }BmpFileHead;

BMP 信息头 (52 Bytes)

    // Copyright Yu Shiqi
    typedef struct
    {
        unsigned int imageSize;
        unsigned int blank;
        unsigned int startPosition;
        unsigned int    length;
        unsigned int    width;
        unsigned int    height;
        unsigned short    colorPlane;
        unsigned short    bitColor;
        unsigned int    zipFormat;
        unsigned int    realSize;
        unsigned int    xPels;
        unsigned int    yPels;
        unsigned int    colorUse;
        unsigned int    colorImportant;
    }BmpInfoHead;

 BMP 文件结构：

    // Copyright Yu Shiqi
    typedef struct
    {
        BmpFileHead fileHead;
        BmpInfoHead infoHead;
        unsigned char * pData;
    }BmpFile;

 颜色信息：

    // Copyright Yu Shiqi
    typedef struct{
        unsigned char G;
        unsigned char B;
        unsigned char R;
        unsigned char A;
    }RGBA;

### 基本操作

 读取 BMP 文件

    // Copyright Yu Shiqi
    // @param   const char* filename    the path of BMP file.
    // @return  A pointer of BmpFile which contain information of input BMP file.
    //
    BmpFile* LoadBMPImage(const char* filename)
    {
        int channels;
        FILE * p;
        BmpFile *pBmpFile = NULL;
        int step, modbytes, idx;
        if( !filename || strlen(filename) == 0 )
        {
            fprintf(stderr, "null filename\n");
            return NULL;
        }
        //打开文件
        p = fopen(filename, "rb");
        if(!p)
        {
            fprintf(stderr, "Can not open file %s\n", filename);
            return NULL;
        }
        pBmpFile = (BmpFile*)malloc( sizeof(BmpFile));
        //fread(&bmpfilehead, sizeof(BmpFileHead), 1, p);
        //从文件中读BmpFileHead，在一些系统中sizeof(BmpFileHead)=4
        //所以不能使用上面那行代码，而要使用下面这行
        fread(&(pBmpFile->fileHead), 2, 1, p);
        //从文件中读取BmpInfoHead
        fread(&(pBmpFile->infoHead), sizeof(BmpInfoHead), 1, p);
        //如果文件的前两个字节不是'BM'，则不是BMP文件
        if( (pBmpFile->fileHead.type1 != 'B' && pBmpFile->fileHead.type1 != 'b') ||
        (pBmpFile->fileHead.type2 != 'M' && pBmpFile->fileHead.type2 != 'm') )
        {
            fprintf(stderr, "The file is not a BMP file" );
            fclose(p);
            free(pBmpFile);
            return NULL;
        }
        //对读入的数据进行检查
        //对于Gray图像, bitColor=8;
        //对于RGB图像, bitColor=24
        channels = pBmpFile->infoHead.bitColor / 8;
        if(channels != 1 && channels != 3)
        {   //只支持1个或3个通道的图像
            fprintf(stderr, "Only 1 or 3 channels images can be loaded." );
            fclose(p);
            free(pBmpFile);
            return NULL;
        }
        //检查宽度和高度是否合理
        if(pBmpFile->infoHead.width <= 0 || pBmpFile->infoHead.height <=0)
        {
            fprintf(stderr, "Bad image size");
            fclose(p);
            free(pBmpFile);
            return NULL;
        }
        //每行像素占的字节数为4的倍数，计算出这个数值step
        modbytes = (pBmpFile->infoHead.width * channels)%4;
        step = modbytes ? ((pBmpFile->infoHead.width*channels)-modbytes+4)  : (pBmpFile->infoHead.width*channels);
        pBmpFile->pData = (unsigned char*)malloc(step * pBmpFile->infoHead.height);
        //跳到文件中的数据区开始位置
        fseek(p, pBmpFile->infoHead.startPosition, SEEK_SET);
        //将所有图像数据读入，由于BMP以底端为第一行存储，
        //而图像一般以上端为第一行存储
        for(idx=pBmpFile->infoHead.height-1; idx >= 0 ; idx--)
        {
            int n = fread(pBmpFile->pData + step*idx, step, 1, p);
            if(n!=1)
            {
                fprintf(stderr, "read image data error.\n");
                break;
            }
        }
        fclose(p);
        return pBmpFile;
    }

保存 BMP 文件

    // Copyright Yu Shiqi
    int SaveBMPImage( const char* filename, const BmpFile * pBmpFile )
    {
        FILE * p;
        int channels;
        int modbytes, step;
       
        if( !filename || strlen(filename) == 0 )
        {
            fprintf(stderr, "null filename\n");
            return -1;
        }

        if(!pBmpFile)
        {
            fprintf(stderr, "null BMP file data\n");
            return -1;
        }
        
        //读取通道数目
        channels = pBmpFile->infoHead.bitColor / 8;
        //每行像素占的字节数为4的倍数，计算出这个数值step
        modbytes = (pBmpFile->infoHead.width * channels)%4;
        step = modbytes ? ((pBmpFile->infoHead.width*channels)-modbytes+4)  : (pBmpFile->infoHead.width*channels);
        
        p = fopen(filename, "wb");
        if(!p)
        {
            fprintf(stderr, "Can not create file" );
            return -1;
        }
        
        //写入数据头信息
        fwrite(&(pBmpFile->fileHead), sizeof(BmpFileHead), 1, p);
        fwrite(&(pBmpFile->infoHead), sizeof(BmpInfoHead), 1, p);
        
        //写入数据信息
        if(channels==1)
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
        //写入数据
        for(int idx = pBmpFile->infoHead.height-1; idx >=0 ; idx--)
            fwrite(pBmpFile->pData + step*idx, step, 1, p);
        
        fclose(p);
        
        return 0;
    }

 1. 取某个像素点的值
   2. 调用 `BmpFile* LoadBMPImage(const char* filename) `
   2.` BmpFile->pData` 是数据区的信息。可以理解为一个二维矩阵。需要特别提示的是，`LoadBMPImage` 函数已将矩阵转正（存储顺序从左上角开始）。
   2. 对于 [BMP存储格式](The Storage Format of BMP File) 中提到的 BMP 数据区的存储宽度问题。

            int channels = BmpFile->infoHead.bitColor / 8;        // 获得通道
            int modbytes = (BmpFile->infoHead.width * channels) %4;        // 如果存储矩阵的宽度是 4 的倍数，modbytes = 0 ，否则为 1、2 或 3。
            int step = modbytes ? ((BmpFile->infoHead.width * channels) - modbytes + 4) : (BmpFile->infoHead.width * channel);        // 真正的矩阵宽度 （保证是 4 的倍数）

 1. 水平翻转

   图像就是矩阵，水平翻转，只需要将矩阵水平翻转就可以实现了。

        void transport_x(BmpFile* file, int channel){
            int step = GetStep(file);
            int height = file->infoHead.height;
            int i, j, k;
            int temp;
            for(i=0;i<height;i++){
                for(j=0;j<step/2;j++){
                    temp = file->pData[i*step + j];
                    file->pData[i*step + j] = file->pData[i*step + step - j - 1];
                    file->pData[i*step + step - j - 1] = temp;
                }
                for(j=0;j<step/channel;j++){
                    for(k=0;k<channel/2;k++){
                        temp = file->pData[i*step + channel*j + k];
                        file->pData[i*step + channel*j] = file->pData[i*step + channel*j + channel-k-1];
                        file->pData[i*step + channel*j + channel-k-1] = temp;
                    }
                }
            }
        }

 1. 垂直翻转

        void transport_y(BmpFile* file){
            int i, j;
            int temp;
            int step = GetStep(file);
            int height = file->infoHead.height;
            for(i=0;i<height/2;i++){
                for(j=0;j<step;j++){
                    temp = file->pData[i*step + j];
                    file->pData[i*step + j] = file->pData[(height-i-1)*step + j];
                    file->pData[(height-i-1)*step + j] = temp;
                }
            }
        }

 1. 反转（反色、反相）
 反转，用 255 - 当前值。

        void inverse(BmpFile* file){
            int i,j;
            int step = GetStep(file);
            int height = file->infoHead.height;
            for(i=0;i<height;i++){
                for(j=0;j<step;j++){
                    file->pData[i*step + j] = 255 - file->pData[i*step + j];
                }
            }
        }
 
 1. 去色
 图像的灰度值计算，有一个公式：
   `Gray = 0.299 * R + 0.587 * G + 0.114 * B;`
 计算出 Gray，然后使 R/B/G 都为这个值就可以转换成（看似）灰度图片。但这样生成的图片还是 RGB 的图片，因为通道还是 3。
    
        void ChangeColor(BmpFile* file){
        int channels = file->infoHead.bitColor / 8;

            if(channels != 3){
                cout << "Bmp file's channel must be 3" << endl;
                return ;
            }

            int i, j;
            int height = file->infoHead.height;
            int step = GetStep(file);
            unsigned char* newData = new unsigned char[height * step / 3];
            int index=0;
            unsigned char R, G, B;
            double Gray;
            for(i=0;i<height;i++){
                for(j=0;j<step;j+=3){
                    R = file->pData[i*step + j + 2];
                    G = file->pData[i*step + j + 1];
                    B = file->pData[i*step + j];
                    Gray = 0.299 * R + 0.587 * G + 0.114 * B;
                    file->pData[i*step + j + 2] = (unsigned char) Gray;
                    file->pData[i*step + j + 1] = (unsigned char) Gray;
                    file->pData[i*step + j + 0] = (unsigned char) Gray;
                }
            }
        }

 1. 去色  并转化为灰度图片
    改善上一段代码的算法就可以正式转换为灰度图片。
    
        void RemoveColor(BmpFile* file){
            int channels = file->infoHead.bitColor / 8;
            
            if(channels != 3){
                cout << "Bmp file's channel must be 3" << endl;
                return ;
            }

            int i, j;
            int height = file->infoHead.height;
            int step = GetStep(file);
            unsigned char R, G, B;
            double Gray;
            unsigned char* newData = new unsigned char[height * step / 3];
            int index=0;
            for(i=0;i<height;i++){
                for(j=0;j<step;j+=3){
                    R = file->pData[i*step + j + 2];
                    G = file->pData[i*step + j + 1];
                    B = file->pData[i*step + j];
                    Gray = 0.299 * R + 0.587 * G + 0.114 * B;
                    newData[index++] = (unsigned char)Gray;
                }
            }
            file->infoHead.bitColor = 8;
            file->pData = newData;
        }   
