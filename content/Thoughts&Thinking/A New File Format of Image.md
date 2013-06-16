## 一种新的图片类型的 YY

 Created by [shonenada](http://shonenada.com)

### YY 之始
 现在网络上流行的图片格式是 `jpg`, 'png', 'gif'。在印刷产业可能还会有 `tif` 之类的图片格式。这些图片格式都是记录着图片的颜色信息，显然，图片中的“文字”在它看来也不过是一些像素点而已。

 这样的图片格式将文字死死地“刻”在图片中，不能复制，也不便于修改。于是我开始构思一种新的图片格式，以两层信息存储图片。底层是一般意义的计算机图像，而顶层是文本信息，可以通过一定的工具进行直接选中，复制等操作。

### YY 之思
 我的思路很明确，以两层的形式来保存图片，底层是图像，而顶层是文本。因此，必须了解到图像和文本在计算机中的存储形似。

#### 图像存储格式
 1. BMP 的存储格式。请移步 [BMP文件存储格式](../Digital Image Processing/The Storage Format of BMP File) 。
 1. JPG 的存储格式。
 1. PNG 的存储格式。

#### 文本存储格式

 图像信息是以像素点的信息（按顺序存储每个像素点的色彩信息）来保存在计算机中，而文本则以 ASCII 或者其他文本编码存储在计算机中。

### YY 之行

### YY 之新

### YY 之续

### YY 参考
 1. -