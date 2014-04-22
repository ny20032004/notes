## 配置服务器的步骤 | The Steps to Set Up My Server

Written by [shonenada](http://shonenada.com) on 2013-4-28

### 环境说明

 * 操作系统： [Fedora 17](http://fedoraproject.org/)

### 操作系统基本配置

 1. 安装 ssh：
  * ssh 在 Linux 中默认安装好。如果没有安装，`# yum install OpenSSH` 安装
  * 开启 ssh 服务：`# systemctl start sshd.service`
  * 开机自动开启 ssh 服务：`# systemctl enable sshd.service`
 1. 开启 22 端口：
  * 开放 22 端口：`# iptable -I -INPUT -p tcp --dport 22 -j ACCEPT`
  * 开机启动 22 端口：`# vi /etc/sysconfig/iptables` 添加：

            -A INPUT -m state --state NEW -m udp -p tcp --dport 22 -j ACCEPT
            -A INPUT -m state --state NEW -m tcp -p tcp --dport 22 -j ACCEPT
 1. authorized_keys：
  2. 
     * Linux 下生成 公钥/密钥 对：`ssh-keygen -t rsa` 生成 公钥: `~/.ssh/id_rsa.pub`，密钥：`~/.ssh/id_rsa`。
     * Windows 下生成 公钥/密钥 对：使用 [puttygen](http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html) 工具。 __注意：不能直接保存公钥，需要在窗口中复制，否则公钥是无效的。__
  2. 
     * Linux：`cp ~/.ssh/id_rsa.pub ~/.ssh/authorized_keys` .
     * Windows：上传公钥到 `~/.ssh/authorized_keys`。
  2. `chmod 700 ~/.ssh` `chmod 600 ~/.ssh/authorized_keys`  
 1. sudoer:
  2. `# vi /etc/sudoers` 去掉 `# %wheel..` 前的 "# ": 

            ## Allows people in group wheel to run all commands
            %wheel  ALL=(ALL)   ALL
  2. `# usermod <username> -G wheel`
 

### 版本控制系统
 * Git 安装：`$ sudo yum install git`

### Web 环境

  * **Nginx**
   1. 安装 `$ sudo yum install nginx`
   1. 启动 nginx 服务 `$ sudo systemctl start nginx.service`
   1. 开机自动启动 nginx 服务 `$ sudo systemctl enable nginx.service`
   1. 配置 Virtual Host:
    2. `$ sudo vi /etc/nginx/nginx.conf` 在 `http{} `最后一行添加： `include /etc/nginx/sites-enabled/*`
    2. `$ sudo mkdir /etc/nginx/sites-enabled`
       `$ sudo mkdir /etc/nginx/sites-availabled`
       `$ sudo vi /etc/nginx/sites-availabled/shonenada.com.conf`

            server{

                listen 80;
                server_name shonenada.com;
                root /var/www/shonenada.com;
                index index.html index.htm;
                access_log /var/log/nginx/shonenada.com.access.log;
                error_log = /var/log/nginx/shonenada.com.error.log;
                error_page 404 /404.html;
                error_page 500 502 503 504 /50x.html;

                charset utf-8;

                location ~ /\.ht {
                    deny all;
                }

                location = /50x.html {
                    root /usr/share/nginx/www;
                }

            }
    2. 软链接:
     `$ sudo ln -s /etc/nginx/sites-availabled/shonenada.com.conf /etc/nginx/sites-enabled/shonenada.com.conf`
    2. 重启 nginx 服务：    `$ sudo systemctl reload nginx.service`    `$ sudo systemctl restart nginx.service`

  * **easy_install**
   1. 下载 egg： [setuptools](https://pypi.python.org/packages/2.7/s/setuptools/setuptools-0.6c11-py2.7.egg#md5=fe1f997bc722265116870bc7919059ea)
   1. 执行安装： `$ sudo sh setuptools-0.6c9-py2.4.egg --prefix=~`
  * **pip**
   1. 执行：`$ sudo easy_install pip`
  * **Virtual Env**
   1. 安装：`$ sudo pip install virtualenv`
   1. 创建虚拟环境：`$ virtualenv ~/venv`
   1. 开启虚拟环境：`$ source ~/venv/bin/activate`
   1. 退出虚拟环境：`$ deactivate`


#### 创建 Python Web 应用

 1. 创建应用目录 `$ mkdir ~/srv/` 
 1. 克隆版本库 `$ git clone git:repository`
 1. 进入 Virtual env：`$ source ~/venv/bin/activate`
 1. 安装应用依赖库 `pip install -r ~/srv/requirements.txt`
 1. 安装 Gunicorn：`$ sudo pip install gunicorn`
 1. 配置 Gunicorn：`$ gunicorn --daemon --workers 3 --bind 127.0.0.1:8000 wsgi:application`
 1. 配置 Nginx：`$ sudo vi /etc/nginx/sites-avaliabled/site.shonenada.com.conf`：

        server{
            listen 80;
            server_name site.shonenada.com;

            location / {
                proxy_pass http://127.0.0.1:8000;
                proxy_redirect off;
                proxy_set_header Host $host;
                proxy_set_header X-Real-IP $remote_addr;
                proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
            }
        }
 1. 软链接： `$ sudo ln -s /etc/nginx/sites-availabled/site.shonenada.com.conf /etc/nginx/sites-enabled/site.shonenada.com/conf`
 1. Reload and Restart: `$ sudo systemctl reload nginx.service` `$ sudo systemctl restart nginx.service`

### 参考
 1. [Fedora docs: Starting an OpenSSH Server](http://docs.fedoraproject.org/en-US/Fedora/17/html/System_Administrators_Guide/s2-ssh-configuration-sshd.html)
 1. [How To Install LEMP On Fedora 17](http://www.unixmen.com/how-tio-install-lemp-on-fedora-17/)
 1. [pypi/setuptools](https://pypi.python.org/pypi/setuptools)
 1. [nginx wiki](http://wiki.nginx.org/)
 1. [Full example of nginx](http://wiki.nginx.org/FullExample)
 1. [Pitfalls of Common Configuration](http://wiki.nginx.org/Pitfalls)
 1. [Gunicorn](http://docs.gunicorn.org/en/latest/index.html)
 1. [Deploy Gunicorn using Virtualenv](http://docs.gunicorn.org/en/latest/deploy.html#using-virtualenv)
 1. [By Ravi Saive Under: CentOS, Databases, Fedora, Linux Distros, MySQL, Nginx, PHP, RedHat, Web Servers](http://www.tecmint.com/install-lemp-linux-nginx-mysql-php-on-rhel-centos-5-6-fedora-12-17/)
 1. [Setting up a virtual host in Nginx](http://gerardmcgarry.com/blog/setting-a-virtual-host-nginx)
 1. [How To Setup a NGINX Virtual Host Using a Custom Domain](http://www.farinspace.com/nginx-virtual-host/)