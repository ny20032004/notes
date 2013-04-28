## 基于 Python 的远程桌面
  Created by [shonenada](http://shonenada.com) on 2013-4-27

### 实现思路
 1. 实现远程桌面的显示
   * 服务器端：
     * 使用 Python 对进行截屏，然后传输到客户端浏览器。
     * 使用 Python 对截屏所使用的库：[Python Imaging Library (PIL)](http://www.pythonware.com/library/pil/handbook/index.htm)
   * 客户端：
     * 读取并显示从服务器端传输过来的图片数据。
 1. 实现鼠标控制
   * 客户端：
     * 使用 Javascript 记录用户在浏览器上的鼠标移动痕迹以及鼠标事件并发送到服务器。
   * 服务器端
     * 从客户端获取鼠标操作数据，进行解析，取得动作（move/click/rightclick）以及鼠标坐标位置(x and y)
     * 调用系统 API 控制鼠标。控制鼠标所使用的库：[PyUserInput/pymouse](https://github.com/SavinaRoja/PyUserInput/tree/master/pymouse)
 1.实现键盘控制
   * 客户端：
     * 使用 Javascript 监听用户键盘操作，并将输入传到服务器端。
   * 服务器端：
     * 从客户端获取键盘操作，进行解析并调用系统 API 控制键盘。控制键盘所使用的库：[PyUserInput/pykeyboard](https://github.com/SavinaRoja/PyUserInput/tree/master/pykeyboard)

### 实现细节
 1. [gevent](http://www.gevent.org/) 优化

        """Patch sokect and os with gevent"""
        from gevent import monkey
        monkey.patch_socket()
        monkey.patch_os()

### 目前的不足【TODO】
 1. 服务器端截屏后保存到硬盘，再读取发送到客户端。
 1. 不支持右键
 1. 不支持拖动
 1. 服务器端是自己写的一个简单 socket 服务器，需要进行优化，或使用其他 web 框架。
