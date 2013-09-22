## Menger 定理

 [shonenada](http://shonenada.com) @ 2013/6/17
 
### 基本概念
 1. __内部不交的(internally vertex-disjoint)__: 设 x 和 y 是图 D 中不同两顶点,Ρ是D中(x,y)路集. 若Ρ中任何两条Pi和Pj均有V(Pi)∩V(Pj) = {x,y},则称P是D中__内部不交的(internally vertex-disjoint)__(x,y)路集.
 1. __边不交的(edge disjoint)__: 若Ρ中任何两条Pi和Pj均有 E(Pi)∩E(Pj) 为空集, 则称 P 是 D 中__边不交的(edge disjoint)__(x,y)路集.
 1. __最小(x,y)截边集(minimum cut-edge set)__: 具有最小边数的(x,y)的截边集.
 1. __局部边连通度(local edge-connectivity)__: 用λD(x,y)表示最小(x,y)截边集中的边数,称D的__局部边连通度(local edge-connectivity)__.
 1. __分离集(separating set)__: 若存在 S 是 V(D)\\{x,y} 的子集 使 D - S 中不存在(x,y)路,则称S为D中(x,y)__分离集(separating set)__.
  * __最小分离集__: 具有最小顶点数目的(x,y)分离集称为最小(x,y)分离集. 用 κD(x,y)表示D中最小(x,y)分离集中的顶点数目.
 1. __局部点连通度(local vertex-connectivity)__: 用ζD(x,y)表示D中内部点不交(x,y)路的最大条数,称为D的__局部点连通度(local vertex-connectivity)__.

### 符号
 1. ζD(x,y): D中内部点不交路的最大条数.
 1. ηD(x,y): D中边不交路的最大条数.
 1. λD(x,y): 表示最小(x,y)截边集中的边数.

### 笔记
