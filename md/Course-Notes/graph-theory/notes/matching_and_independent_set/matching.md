匹配
----

 [shonenada](http://www.shonenada.com) on 2013/6/22

### 概念与定义
 1. __匹配(matching)__: 设D是无环非空图, M是中任何两条边在D中均不相邻, 则称M为D的__匹配(matching)__.
 1. __M饱和点(saturated vertex)__: D中与M中边关联的顶点策划更能为__M饱和点(saturated vertex)__.
 1. __M非饱和点(unsaturated vertex)__: D中,不是M饱和点的顶点.
 1. __M饱和X__: X是V(D)的子集, 若X中没个点都是M饱和点, 则称M饱和X.
 1. __完备匹配(prefect matching)__: 若M饱和V(D)则称M为D的__完备匹配(perfect matching)__.
 1. __最大匹配(maximim matching)__: 若对D的任何匹配M' 均有|M'|≤|M|,则称M为D的__最大匹配(maximum matching)__.
 1. __点覆盖(vertex convering)__: 设G是无环非空图, S是V(G)的非空子集. 若E(G)中每条边都与S中某电关联, 则称S为G的__点覆盖(vertex covering)__.
  1. __最小点覆盖(minimum vertex covering)__: 如果G中任何异于S的点覆盖S' 均有|S'| ≥ |S|, 则称S为__最小点覆盖(minimum vertex covering)__.
  1. __极小点覆盖(minimal vertex covering)__: 对任何x∈S,S\\{x}, 都不是点覆盖.
 1. __点覆盖数(vertex convering number)__: G中最小点覆盖中的顶点数称为__点覆盖数(vertex covering number)__.记为β(G).
 1. __匹配数(matching number)__: G中最大匹配中的边数,称为__匹配数(matching number)__.

### 笔记
 1. 匹配是E(D)的子集, 并且匹配中的没有共同的端点.
 1. 完备匹配都是最大匹配,但最大匹配不都是完备匹配.