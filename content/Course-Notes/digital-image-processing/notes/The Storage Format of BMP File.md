## BMP文件存储格式

### 文件头
 * 文件头：2  Bytes （'B' 和 'M' 两个字符）

### 信息头
　信息头：52 Bytes：

    typedef struct tagBITMAPINFOHEADER { /* bmih */
    DWORD biSize;
    LONG biWidth;    // 说明图象的宽度，以象素为单位
    LONG biHeight;
    /**
    说明图象的高度，以象素为单位。注：这个值除了用于描述图像的高度之外，
    它还有另一个用处，就是指明该图像是倒向的位图，还是正向的位图。
    如果该值是一个正数，说明图像是倒向的，如果该值是一个负数，则说明图像是正向的。
    大多数的BMP文件都是倒向的位图，也就是时，高度值是一个正数。
    （注：当高度值是一个负数时（正向图像），图像将不能被压缩
    （也就是说biCompression成员将不能是BI_RLE8或BI_RLE4）
    */
    WORD biPlanes;    // 为目标设备说明位面数，其值将总是被设为1
    WORD biBitCount;    // 说明比特数/象素，其值为1、4、8、16、24、或32
    DWORD biCompression;
    /**
    说明图象数据压缩的类型。其值可以是下述值之一：
    BI_RGB：没有压缩；
    BI_RLE8：每个象素8比特的RLE压缩编码，压缩格式由2字节组成（重复象素计数和颜色索引）；
    BI_RLE4：每个象素4比特的RLE压缩编码，压缩格式由2字节组成
    BI_BITFIELDS：每个象素的比特由指定的掩码决定。
    */
    DWORD biSizeImage;    // 说明图象的大小，以字节为单位。当用BI_RGB格式时，可设置为0
    LONG biXPelsPerMeter;    // 说明水平分辨率，用象素/米表示
    LONG biYPelsPerMeter;    // 说明垂直分辨率，用象素/米表示
    DWORD biClrUsed;     // 说明位图实际使用的彩色表中的颜色索引数（设为0的话，则说明使用所有调色板项）
    DWORD biClrImportant;     // 说明对图象显示有重要影响的颜色索引的数目，如果是0，表示都重要。
    } BITMAPINFOHEADER;

### 数据区
* 默认存储顺序：
 * 对于灰度图片：从图像左下角像素点向右下角开始存储，一直向上。每个像素点占 1 个字节（8 bits），0 ~ 255 表示灰度值（0 为黑，255为白，中间是不同的灰度）。
 * 对于 RGB 图片：按照灰度图片的存储方式。但每个像素点占 3 个字节（分别顺序存储 B、G、R）。
* 存储宽度问题：
　　BMP 图片在保存的时候会计算图片的宽度是否为4的倍数，如果是则正常保存，否则会使得存储的空间为 4 的倍数。（但信息头中的 width 不改变所以图片的宽度不变，只是存储的结构改变。） 可以构建 3*4 和 4*4 的 BMP 图片进行比较。

### 参考资料
 * [BMP - 维基百科（英文版）](http://en.wikipedia.org/wiki/BMP_file_format)

 * [BMP - 维基百科（中文版）](https://zh.wikipedia.org/wiki/BMP#.E4.BD.8D.E5.9B.BE.E6.96.87.E4.BB.B6.E5.A4.B4)

 * [BMP - 百度百科](http://baike.baidu.com/view/189487.htm)
