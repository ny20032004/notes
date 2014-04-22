游戏与数学
###########

:date: 2014-03-17
:tags: Learning

前段日子看了看 Pygame 的使用方法，其中看到一个之前从来没想过的东西，觉得很神奇，记录下来。

物体与坐标
-----------
熟悉 html、css，或者 Java GUI 甚至 Flash、Photoshop 的童鞋应该对定位并不陌生。在计算机中，常常使用坐标来对物体进行定位的。
例如，以 Flash 为例，Scene 左上角的像素点就是坐标的原点，而最顶部的像素构成的线是 x 轴，正方向向右；最左边像素构成的线是 y 轴，正方向向下。

另外需要注意的是，哪一个像素点才是物体的参考点，一般来说是对象正方形区域，左上角的点作为参考点。

通过将物体以一个（参考点坐标，长，宽）这样的形式来对物体进行定位，可以使得我们很方便的改变物体的位置。

.. code-block:: python

    while True:
        screen.blit(dennis, (position_x, position_y))
        pygame.display.update()
        time.sleep(0.05)
        position_x += 5
        position_y += 5

通过这种方法我们还可以构建一个数学函数来模拟物体的运动，例如一个自由落体运动：

.. code-block:: python

    def free_falling(g, t):
        return 1.0/2 * g * pow(t, 2)

    TIME_SEP = 0.05
    g = 9.8
    t = 0
    while True:
        y = free_falling(g, t)
        time.sleep(TIME_SEP)
        t += TIME_SEP
        screen.blit(ball, (100, y))
        pygame.display.update()

童鞋们应该很容易就发现，物体的运动轨迹其实等于我所构建的数学函数的图像。
结合数学上的解析几何知识，我们甚至可以构建很多复杂的物体运动。
当然，要构建复杂的运动，首先要设计出复杂的数学函数来表达物体的运动轨迹，再通过时间作为参数来使得物体运动起来。
因此，使用坐标来描述物体运动，比较适合于规则的物体运动。


坐标 VS 向量
------------
上面提到，使用坐标的方法来使物体运动起来，需要构建数学函数来模拟，那么是不是复杂的物体运动就难以模拟出来呢，很明显，答案是否定的。

游戏里描述一个物体的运动，或许用“速度”会比用“向量”更好理解。
速度 = 物体运动的方向 + 这个方向上的速率。

从物理学角度说，物体的运动实际上是因为这个物体有速度。
我们可以通过向量（Vector）来表示物体的速度，将向量化成游戏坐标系中对应的点即可使物体运动起来。

举个简单的例子，比如我需要将对象从 (10, 10) 移动到 (100, 50) 的位置，
如果使用坐标计算的方法将会是这样：

.. code-block:: python

    x, y = 10, 10
    while True:
        screen.blit(obj, (x, y))
        x += 9
        y += 4
        pygame.display.update()
        time.sleep(0.1)

而使用向量的方法：

.. code-block:: python
    def vector_diff(v1, v2):
        return (v2[0] - v1[0], v2[1] - v1[1])

    def vector_add(v1, v2):
        return (v1[0] + v2[0], v1[1] + v2[1])

    def vector_normalize(v):
        param = sqrt(sum(pow(v[0], 2), pow(v[1], 2)))
        return (v[0] / param, v[1] / param)

    source = (10, 10)
    target = (100, 50)
    while True:
        diff_vector = vector_diff(source, target)
        direct_vector = vector_normalize(diff_vector)
        source = vector_add(source, direct_vector)
        screen.blit(obj, source)
        pygame.display.update()
        time.sleep(0.1)

这种方法更加直接明了，但是缺点也是明显的：

1. 需要使用向量库支持（其实也不复杂，自己手写也可以）
2. 规则的运动可能不适合，这也是坐标法擅长的。


后记
-----

很久之前就有想过了解 游戏 与 物理学 之间的关系，这算是一个起点吧，而且算是一个精彩的起点。

很久之前尝试使用 Flash 模拟 自由落体，结果真的很糟糕。那时候还只知道坐标法，为了某一个运动路线，一直在设计数学函数，各种分段，各种 if else if else。最后自己都弄晕了。

而当我看到 向量 这个方法的时候，我突然很激动，也许这就是游戏（开发）的魅力吧~

物理学、数学，依旧是计算机的基础，特别是高级应用，游戏，图像等等，虽然这两方面都很不给力，不过为了更好发展，努力吧~
