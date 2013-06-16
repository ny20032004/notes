## Doolittle

Created by [shonenada](http://shonenada.com) on 2013/4/11
 
### 解法思路

对于 Ax = b，的方程组，寻找单位下三角矩阵 L 和 上三角矩阵 U 使得 A = LU。则 LUx = b .

分步求解：

 1. LUx = b.
 1. L (Ux) = b. 
 1. Ly = b; y = Ux.

### 算法思路
 1. 分解 A
  * a[r,i] = ∑(k=1->r) { l[r,k] * u[k,i] }
  * a[i,r] = ∑(k=1->r) { l[i,k] * u[k,r] }
  * **所以**
  * r = 1 时, u[1,i] = a[1,i]  , l[i,1] = a[i,1] / u[1,l]
  * **已求出 U 的第 1 至 r-1 行，L 的第 1 至 r-1 列：**
  * u[r,i] = a[r,i] = ∑(k=1->r-1) { l[r,k] * u[k,i] }
  * l[i,r] = ( a[i,r] - ∑(k=1->r-1) { l[i,k] * u[k,r] } ) / u[r,r]
 1. 计算 Ly = b 得出 y
 1. 计算 Uy = x 得出 x

### 参考资料
 暂无
 