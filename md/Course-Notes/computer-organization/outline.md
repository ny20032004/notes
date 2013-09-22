计算机系统概述
-------------

* 计算机系统: 电子, 数字, 通用的计算机系统:
    * 电子: 使用电子线路, 而不是使用机械或继电器等来实现的计算机应将的_关键逻辑功能_.
    * 数字: 使用电子线路是数字式电路而不是模拟电路, 运算和处理的数据是二进制的_离散数据_而不是连续的电压或电流量.
    * 通用: 计算机本身的功能是多样, 而不是专用语某种特定功能, 具有完成各种运算或事务处理的能力.

* 计算机系统由__硬件系统__和__软件系统__组成:
    * 硬件系统: 一种高度复杂的由多种电子线路, 精密机械装置等构成的, 能够自动和快速地完成数据计算的装置或工具.
    * 软件系统: 程序和相关的数据. 包括完成计算机资源管理, 方便用户使用的系统软件和完成用户对数据的预期处理功能的用户软件.
    
* 计算机系统的层次结构: 
    1. 第0层, 数字逻辑层: 硬件系统层, 着重实现计算机硬件最重要的无知材料是电子线路, 能够直接处理离散的数字信号.
    1. 第1层, 微体系结构层(micro architecture): 硬件系统层, 计算机裸机, 部件之间如何实现相互连接并协同工作. 计算机硬件系统通常由运算器部件(数据通路), 控制器部件, 存储部件, 输入设备, 输出设备这五部分组成.
    1. 第2层, 指令系统(instruction set): 软件系统层, 介于硬件和软件之间. 是计算机硬件系统设计、实现最基本和最重要的依据，与计算机硬件实现的复杂程度、设计程序的难易程度、程序占用硬件资源的多少、程序运行效率等都有直接关系。机器语言(二进制代码语言), 也就是计算机的指令, 一台计算机的全部指令构成该计算机的指令系统. 
    1. 第3层, 操作系统层(operating system): 主要负责计算机系统中的资源管理与分配, 以及向使用者和程序设计人员提供简单, 方便, 高效的服务. 操作系统进一步扩展了原来的指令系统, 提供了新的可用命令, 从而构成一台比纯硬件系统功能更加强大的计算机系统.
    1. 第4层, 汇编语言层(assembly language): 软件系统层. 与机器语言相比, 汇编有两个优点, 
        1. 容易理解, 容易记忆
        1. 使用变量 避免直接操作数据分配.

* 计算机主要的技术与性能指标: 
    1. 计算机字长: 多少个二进制位来表示一个数据或一条指令.
    1. CPU速度.
    1. 存储容量.
    1. 内存储器的存储周期和外存储器的数据传送速率.