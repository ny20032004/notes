## 记录：版本库迁移之 CVS 到 SVN

 Created by [shonenada](https://github.com/shonenada) on 2013-4-28

### 工具
 1. [Python](http://www.python.org)
 1. [Subversion](http://subversion.tigris.org/)
 1. [cvs2svn](http://cvs2svn.stage.tigris.org/)

### 记录
 1. 安装好 Python、Subversion。
 1. 解压缩 cvs2svn .
 1. 命令行下进入 cvs2svn 目录并执行 `python cvs2svn --dump-only --use-cvs --encoding=gbk /path/to/old/cvs/repo --dumpfile /path/to/svn/dump/file`
 1. 执行 `svnadmin create /path/to/new/svn/repo`
 1. 执行 `svnadmin load /path/to/new/svn/repo < /path/to/svn/dump/file`
 1. 直接使用 `svnserve -d -r /path/to/new/svn/repo` 启动版本库或安装 [VisualSVN Server](http://www.visualsvn.com/downloads/) 创建版本库

### 参考资料
* [svnbook](http://www.subversion.org.cn/svnbook/nightly/svn.ref.svnadmin.c.load.html)
* [四步轻松启动svnserve服务](http://developer.51cto.com/art/201006/203476.htm)
* [http://blog.sina.com.cn/s/blog_630bf12f0100nl7o.html](http://blog.sina.com.cn/s/blog_630bf12f0100nl7o.html)
* [svnadmin dump备份工具](http://blog.sina.com.cn/s/blog_60b173cd0100g8zx.html)
