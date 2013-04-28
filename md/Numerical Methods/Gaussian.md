## 高斯列主元消去法 

 Created by [shonenada](http://shonenada.com) on 2013/4/7

 Edited by [shonenada](http://shonenada.com) on 2013/4/8 : 补充 **算法分析** 与 **参考资料** 

 Edited by [shonenada](http://shonenada.com) on 2013/4/12 : 补充 **算法分析**

### 高斯消元法
一般线性方程组求解过程（高斯消元法）：

 设有线性方程组

   Ax = b

 当 def（A）≠ 0 时，方程组的解存在且唯一。

 对增广矩阵（A,b）进行行初等变换，化 A 为上三角矩阵A(n)，同时化 b 为对应的矩阵b(n).

 回代求解未知数组 x.

Xn = bn(n) / Ann(n);

Xk = (bk(k) - ∑[j=k+1~n](Akj(k) · xj) / Akk(k);


### 高斯列主元消去法介绍

在高斯消元的过程中，位于矩阵 A 主对角线上的元素成为 主元素。

主元素在高斯消元求解过程中会作为除数。在计算除法的时候，要避免用小的数做除数，否则误差会变得很大。

为了解决这个问题，每次行变换之前，选择列中绝对值最大的元素（称为“列主元”），通过行初等变换使得绝对值最大的元素变换到该列的主元的位置上。


### 算法介绍
 在介绍算法之前需要了解算法符号。

 1. 输入方程组维数n，矩阵 A，右端顶 b 和控制精度 eps。
 1. 对于 k=1:n-1，
   2. |A(u,k)| = max[k≤i≤n]|A(i,k)|；
      % 选主元
   2. 如果|A(u,k)| < eps 则停止；
      % 控制小主元
   2. 如果 u = k，则跳过此步，否则：
      A(k,k:n+1) ←→ A(u,k:n+1)；
      % 换行
   2. 
      ***  A(k+1:n,k) := A(k+1:n,k)
      ***  A(k+1:n,k+1:n) := A(k+1:n,k+1:n) - A(k+1:n,k) · A(k,k+1:n)
      ***  %按行消元
      ***  b(k+1:n)^(T) := b(k+1:n)^(T) - A(k+1:n,k) · b(k)
 1. 如果 A(n,n) = 0，则停止
   % 无解
 1. b(n) := b(n) / A(n,n)，对于 i = n - 1: -1 : 1，
       b(i) := [b(i) - A(i,i+1:n) · b(i+1:n)^(T)] / A(i,i)
   % 回代求解
 1. 输出解 b(1:n)^(T)


### 算法分析
 * 精确度分析
  * [shonenada](http://shonenada.com)（2013/4/8): 编写了 [高斯列主元消去法](https://bitbucket.org/shonenada/numerical-method/src/0793a29145d327c8dade621747eb7b7a849157e9/src/cpp/gauss/gauss.cpp?at=master#cl-83) 和 [高斯消元法](https://bitbucket.org/shonenada/numerical-method/src/0793a29145d327c8dade621747eb7b7a849157e9/src/cpp/gauss/gauss.cpp?at=master#cl-197)。使用两种解法进行测试，三组测试结果两种算法都一样。这个问题需要研究下。
  * [shonenada](http://shonenada.com) (2013/4/12): 以上测试精度都在 1&（-15）内。在 double 类型能表示的范围内，所以用两种消元法进行测试结果都一致。当精度提高到 1^(-20)时，普通高斯消元法已无法进行计算。
 * 时间复杂度

### 参考资料
 暂无
 