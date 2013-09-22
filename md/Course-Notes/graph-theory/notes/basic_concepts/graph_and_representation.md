## 图与图的图形表示

 [shonenada](http://shonenada.com) @ 2013/6/16

 图的基本概念 与 图的定义与术语

### 基础定义

 * __数学结构__: 设 V 是非空集，V 上的一个二元关系 e 是V上的元素对，即 e ∈ V × V. 集 V 和定义在 V 上的二元关系集 R 的有序二元组(V,R)称为__数学结构__。
 * __图(Graph)__: 是指一个数学结构(V,E,ψ),其中 V 是非空集, E 是定义在 V 上的(可以重复)的二元关系集,而 ψ 是 E 到 V × V 的函数, ψ(E)可以是重集.
 * __图的图形表示(diagrammatic representation)__: V中每个元素用平面上的点来表示,ψD(E)中的每个元素(x,y)用一条从x到y的有向直线(或曲线)来表示. 这样的图形称为该图的__图形表示(diagrammatic representation)__.

### 与点/顶点相关的定语与术语

 * __顶点(vertex)__/__点(pointer)__: V 中的元素称为__顶点(vertex)__或称为__点(point)__.
 * __顶点集(vertex set)__: V 称为图的__顶点集(vertex set)__.
 * __阶(order)__: 图的顶点数.

### 与边相关的定义与术语:

 * __边集(edge set)__: E 称为图的__边集(edge set)__.
 * __边(edge)__: E 中的元素称为__边(edge)__.

 * __从 x 到 y 的有向边(directed edge from x to y)__: a∈ E(D), 存在x,y∈ V(D),和有序对(x,y) ∈ V × V使ψD(a) = (x,y). 则 a 称为 __从 x 到 y 的有向边(directed edge from x to y)__.
  * __起点(origin)__: x 称为 a 的起点(origin).
  * __终点(terminus)__: y 称为 a 的重点(terminus).
  * __端点(end-vertices)__: 起点和终点统称为边的端点.

 * __连接x和y的边(edge connection x and y)__: a∈ E(D), 存在x,y∈ V(D),和无序对{x,y} ∈ V × V使ψD(a) = {x,y}. 则 a 称为__连接x和y的边(edge connecting x and y)__.
  * 由于{x,y} = {y,x} 所以边简记为_ψG(e) = xy_或_ψG(e) = yx_.

 * __环(loop)__: 两端点相同的边称为__环(loop)__.
 * __平行边(parallel edge)__/__重边(multi edges)__: 有公共起点并有公共终点的两条边.
 * __对称边(symmetric edges)__: 两端点相同但方向相反的两条有向边.

### 与图相关的定义与术语

 * __简单图(simple graph)__: 无环并且无平行边的图.
 * __有向图(digraph)__: 在图的定义下,若ψ(E)中元素全是有序对,则(V,E,ψ)称为__有向图(digraph)__, 记为 D = (V(D), E(D), ψD).
 * __无向图(undirected graph)__: 在图的定义下, 若ψ(E)中的元素全是无序对,则(V,E,ψ)称为__无向图(undirected graph)__,记为 G = (V(G), E(G), ψG).
 * __对称有向图(symmetric digraph)__: 无序对{x,y}可以视为两个有序对(x,y)和(y,x).由此可以将无向图中每条边视为拥有相同端点、方向相反的有向图,即可以将无向图看成特殊的有向图.
 * __基础图(underlying graph)__: 去掉有向图边上的方向,得到无向图称为__基础图(underlying graph)__.
 * __定向图(oriented graph)__: 为无向图的每条边指定一个方向,得到有向图称为该无向图的__定向图(oriented graph)__.
 * __平凡图(trivial graph)__: 阶为 1 的简单图.
 * __空图(empty graph)__: 边数为零的图. __需要主要的是:υ≠0, 一般情况下,υ≥1__.
 * __有限图(finite graph)__:υ和ε都是有限的图称为__有限图(finite graph)__. 

### 其他术语

 * 边与它的两端点称为__关联的(incident)__.
 * 与同一条边关联的两端点或者与同一个顶点关联的两条边称为__相邻的(adjacent)__. 
 * __关联函数(incidence function)__: ψ称为点与边之间的__关联函数(incidence function)__.


### 符号
 * 无向图: G = (V(G),E(G),ψG).
 * 有向图: D = (V(G),E(G),ψG).
 * 顶点数量: υ,即υ=|V|.
 * 边的数量: ε,即υ=|E|.
 * 向上取整: 设 r 为正实数, 不小于r的最小整数(向上取整)表示为「r].
 * 向下取整: 设 r 为正实数, 不大于r的最大整数(向下取整)表示为 [r」.
