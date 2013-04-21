## C++ 内置指针 与 智能指针的性能对比
  [shonenada](https://github.com/shonenada) written on 2013/4/16

===================================================

我在 [Similar Query and Index in C++](http://bitbucket.org/shonenada/sqai-in-cpp)项目中使用了智能指针。为了了解使用智能指针的性能消耗，我在这项目里进行了性能测试。

### 使用内置指针

    CDNA* temp = new CDNA(ident, currentSquence);
* 在 maxSize = 500,000 的时候，执行平均总时间：4.095s (4.11s + 4.08s).

* 在 maxSize = 1,000,000 的时候，执行平均总时间：10.67s (10.62s + 10.72s)

### 使用智能指针
    shared_ptr<CDNA> temp(new CDNA(ident, currentSquence));
* 在 maxSize = 500,000 的时候，执行平均总时间：4.235s (4.29s + 4.18s)

* 在 maxSize = 1,000,000 的时候，执行平均总时间：10.95s (11.01s + 10.89s)

### 使用引用（对象拷贝
    CDNA temp(ident, currentSquence);
* 在 maxSize = 500,000 的时候，执行总时间：4.78s
 
* 在 maxSize = 1,000,000 的时候，执行平均总时间：12.29s

### 总结
使用智能指针会消耗一定的性能，并且这种消耗呈类线性。
