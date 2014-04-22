## 配置 VNC-Server 的步骤 | The Steps to Set Up vns-server in Fedora17

Written by [shonenada](http://shonenada.com) on 2013-5-5

### 环境说明

 * 操作系统： [Fedora 17](http://fedoraproject.org/)

### 前言

  * VNC (Virtual Network Computing):

   In computing, Virtual Network Computing (VNC) is a graphical desktop sharing system that uses the Remote Frame Buffer protocol (RFB) to remotely control another computer.   -- Wikipedia.

  * 之前给 学子天地 的服务器（CentOS 5.6)配置过 VNC 服务端，当时比较顺利。但是今天给自己的虚拟机(Fedora 17 + gnome)配置的时候却出现一些之前没遇过的情况，记录下来。

### 步骤(针对 Fedora 17)：

  1. 安装服务器端程序： `sudo yum install tigervnc-server`
  1. 将默认配置文件复制到 service 配置文件目录： `sudo cp /lib/systemd/system/vncserver@.service /etc/systemd/system/vncserver@:1.service`
  1. 修改配置文件：`sudo vi /etc/systemd/system/vncserver@:1.serivce`: 将原来的 <user> 改成用户名

        [Service]
        Type=forking
        # Clean any existing files in /tmp/.X11-unix environment
        ExecStartPre=/bin/sh -c '/usr/bin/vncserver -kill %i > /dev/null 2>&1 || :'
        ExecStart=/sbin/runuser -l myuser -c "/usr/bin/vncserver %i -geometry 1024x768"
        ExecStop=/sbin/runuser -l myuser -c "/usr/bin/vncserver -kill %i"
  1. `sudo systemctl daemon-reload`
  1. `sudo systemctl start vncserver@:1.service`
  1. `sudo iptables -A INPUT -p tcp -m state --state NEW -m tcp --dport 5901 -j ACCEPT`


### 参考
  1. [http://en.wikipedia.org/wiki/Virtual_Network_Computing](http://en.wikipedia.org/wiki/Virtual_Network_Computing)
  1. [http://www.oracle-base.com/articles/linux/configuring-vnc-server-on-linux.php](http://www.oracle-base.com/articles/linux/configuring-vnc-server-on-linux.php)