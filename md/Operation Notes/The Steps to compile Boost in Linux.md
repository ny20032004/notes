## 在 Linux 下编译 Boost 的步骤 | The Steps to compile Boost in linux

Written by [shonenada](http://shonenada.com) on 2013-5-5

### 环境说明

 * 操作系统： [Fedora 17](http://fedoraproject.org/)
 * Boost 版本：Boost-1.53.0

### 步骤

 1. 下载 boost 的源码: [http://sourceforge.net/projects/boost/](http://sourceforge.net/projects/boost/)
 1. 解压缩到 /usr/loca/boost_x_xx_xx
 1. `sudo /usr/local/boost_x_xx_xx/bootstrap.sh`
 1. `sudo /usr/local/boost_x_xx_xx/bjam --layout=versioned --build-type=complete --toolset=gcc install` 按完回车之后你就可以去喝杯咖啡，看会书。大概 2 个小时之后回来。
 1. 添加环境变量：`sudo vim /etc/profile`

        在最后加:
        export BOOST_INCLUDE=/usr/local/include/boost-1_53
        export BOOST_LIB=/usr/local/lib
 1. 添加环境变量 `sudo touch /etc/profile.d/boost.sh` `sudo vim /etc/profile.d/boost.sh`

        添加：
        #!/bin/sh
        export BOOST_INCLUDE=/usr/local/include/boost-1_53
        export BOOST_LIB=/usr/local/lib


### 在 CMake(2.8) 中添加 Boost 库
 1. 在 CMakeLists.txt 中添加：
       set(BOOST_INCLUDE_DIR /usr/local/include/boost-1_53)
       set(BOOST_LIBRARY_DIR /usr/local/lib)
       find_package(Boost)
       include_directories(${BOOST_INCLUDE_DIR})
       link_directories(${BOOST_LIBRARY_DIR})
       target_link_libraries(ProjectName ${BOOST_LIBRARIES})

### 参考