# Python 学习笔记 

`print`: 输出

`raw_input`: 获得输入值

**在Python 中转换类型的函数**

 * int  将字符串转成整形
 * float 将字符串或整数转成浮点数
 * str 将数字转换为字符串
 * hex 将正数转换为十六进制的字符串
 * long 将字符串转换成长整型
 * oct 将整数转化为八进制的字符串
 * ord 将ascII字符转化为ascII值

**Python的math 模块**

 * sin(x)  正弦
 * cos(x)  余弦
 * asin(x)  反正弦
 * acos(x)  反余弦
 * tan(x)  正切
 * atan(x)  反正切
 * hypot(x,y)  求直角三角形的斜边长度
 * fmod(x,y)  求x/y的余数
 * ceil(x)  取不小于x的最小整数
 * floor(x)  取不大于x的最大整数
 * fabs(x)  求绝对值
 * exp(x)  求e的x次幂
 * pow(x,y)  求x的y次幂
 * log10(x)  求x的以10为底的对数
 * sqrt(x)  对x的平方根
 * pi    π值

**基本类型**

 *数字类型*

<table>
 <tr>
  <td>类型</td>
  <td>描述</td>
 </tr>
 <tr>
  <td>整数</td>
  <td>一般意义上的数，包含八进制（以数字0开头）及十六进制（以0x开头）</td>
 </tr>
 <tr>
  <td>长整数</td>
  <td>无限大小的数，在其结尾添加小写字母1或者大写字母L</td>
 </tr>
 <tr>
  <td>浮点数</td>
  <td>小数或者用E或e表示的幂</td>
 </tr>
 <tr>
  <td>复数</td>
  <td>复数的虚部以字母j或者J结尾</td>
 </tr>
</table>
 例如：

    >>> 2.30-1.30
        0.99999999999999978
    >>> 07+05    # 八进制
        12
    >>> print "%o" % (07 + 05)
        14
    >>> prtin "%x" % (0x7 + 0x5)
        c
    >>> m = 9 + 3j
    >>> n = 15 - 2j
    >>> m + n     # 复数
        (24 + 1j)

 *运算符*
<table>
 <tr>
  <td>运算符</td>
  <td>描述</td>
 </tr>
 <tr>
  <td> * </td>
  <td>乘法运算符</td>
 </tr>
 <tr>
  <td>/</td>
  <td>除法运算符</td>
 </tr>
 <tr>
  <td>%</td>
  <td>取余运算符</td>
 </tr>
 <tr>
  <td>+</td>
  <td>加法运算符</td>
 </tr>
 <tr>
  <td>-</td>
  <td>减法运算符</td>
 </tr>
 <tr>
  <td>|</td>
  <td>位或运算符（化成二进制，两个二进制若同一位数上其一有 1 则该位为1 否则为0）</td>
 </tr>
 <tr>
  <td>^</td>
  <td>位异或运算符（化成二进制,对比二进制各位数上的字数一样的该位数上为0否则为1）</td>
 </tr>
 <tr>
  <td>&</td>
  <td>位与运算符（化成二进制,应对的两个位数均为1时,该位为1）</td>
 </tr>
 <tr>
  <td><<</td>
  <td>左移运算符（左移1相当于乘2,左移2相当于乘4）</td>
 </tr>
 <tr>
  <td>>></td>
  <td>右移运算符（右移1相当于除以2,右移2相当于除以4 ）</td>
 </tr>
 <tr>
  <td> ** </td>
  <td>乘方运算符</td>
 </tr>
</table>

 *运算符优先级：*

  1. 乘方运算符
  1. 乘法、除法、取余
  1. 加法、减法
  1. 逻辑运算符

<table>
 <tr>
  <td>转义字符</td>
  <td>含义</td>
 </tr>
 <tr>
  <td>\n</td>
  <td>换行符</td>
 </tr>
 <tr>
  <td>\t</td>
  <td>制表符</td>
 </tr>
 <tr>
  <td>\r</td>
  <td>回车</td>
 </tr>
 <tr>
  <td>\\</td>
  <td>表示 \ </td>
 </tr>
 <tr>
  <td>\'</td>
  <td> 表示一个单引号，而不是字符串结束</td>
 </tr>
 <tr>
  <td>\"</td>
  <td>表示一个双引号,而不是字符串结束</td>
 </tr>
</table>
 **只有使用 print 输出字符串时,才会解释字符串中的转义字符**

 *常用字符串操作 (模块 string )*
<table>
 <tr>
  <td>字符串操作</td>
  <td>描述</td>
 </tr> 
 <tr>
  <td>string.capitalize()</td>
  <td>将字符串的第一个字母大写</td>
 </tr> 
 <tr>
  <td>string.count()</td>
  <td>获得字符串中某一子字符串的数目</td>
 </tr> 
 <tr>
  <td><tr>
  <td>string.find()</td>
  <td>获得字符串中某一子字符串的起始位置 0为第一位 -1表示未找到</td>
 </tr> 
 <tr>
  <td>string.isalnum()</td>
  <td>检测字符串是否仅包含0-9 A-Z a-z</td>
 </tr> 
 <tr>
  <td>string.isalpha()</td>
  <td>检测字符串是否仅包含A-Z a-z</td>
 </tr> 
 <tr>
  <td>string.isdigit()</td>
  <td>检测字符串是否仅包含数字</td>
 </tr> 
 <tr>
  <td>string.islower()</td>
  <td>检测字符串是否均为小写字符</td>
 </tr> 
 <tr>
  <td>string.isspace()</td>
  <td>检测字符串中所有字符是否均为空白字符</td>
 </tr> 
 <tr>
  <td>string.istitle()</td>
  <td>检测字符串中的单词是否为首字母大写</td>
 </tr> 
 <tr>
  <td>string.isupper()</td>
  <td>检测字符串是否均为大写字母</td>
 </tr> 
 <tr>
  <td>string.join()</td>
  <td>连接字符串 将字符串插入到括号内每两个字符之间</td>
 </tr> 
 <tr>
  <td>string.lower()</td>
  <td>将字符串全部转换为小写</td>
 </tr> 
 <tr>
  <td>string.split()</td>
  <td>分割字符串</td>
 </tr> 
 <tr>
  <td>string.swapcase()</td>
  <td>将字符串中大写字母转换为小写,小写字母转换为大写</td>
 </tr> 
 <tr>
  <td>string.title()</td>
  <td>将字符串中的单词 首字母大写</td>
 </tr> 
 <tr>
  <td>string.upper()</td>
  <td>将字符串中全部字母转换为大写</td>
 </tr> 
 <tr>
  <td>len(string)</td>
  <td>获取字符串长度</td>
 </tr> 
 <tr>
  <td>string * num</td>
  <td>表示将字符串重复输出3次</td>
 </tr> 
</table>

 *格式化字符串*
  <table>
 <tr>
  <td>%c</td>
  <td>单个字符</td>
 </tr>
 <tr>
  <td>%d</td>
  <td>十进制整数</td>
 </tr>
 <tr>
  <td>%o</td>
  <td>八进制整数</td>
 </tr>
 <tr>
  <td>%s</td>
  <td>字符串</td>
 </tr>
 <tr>
  <td>%x</td>
  <td>十六进制整数,其中字母小写</td>
 </tr>
 <tr>
  <td>%X</td>
  <td>十六进制整数,其中字母大写</td>
 </tr>
</table>

 *将字符串 s 转换为整数：*

`string.atoi(s[,base])`

 *获得绝对路径：*

    import os
    os.listdir(r'absoulte-path')   # r(或R) 表示不转义

* 列表以 [] 括起来，有顺序，可以修改列表里的数据
* 元组以 () 括起来，有顺序，不能修改元祖内的数据
* 字典以 {} 括起来，无顺序，可以修改字典里的数据

<table>
 <tr>
  <td>列表操作</td>
  <td>描述</td>
 </tr>
 <tr>
  <td>list.append()</td>
  <td>追加成员</td>
 </tr>
 <tr>
  <td>list.count(x)</td>
  <td>计算列表中的参数x出现的次数</td>
 </tr>
 <tr>
  <td>list.extend(L)</td>
  <td>向列表中追加另一个列表L</td>
 </tr>
 <tr>
  <td>list.index(x)</td>
  <td>获得参数x在列表中的位置</td>
 </tr>
 <tr>
  <td>list.insert()</td>
  <td>向列表中插入数据</td>
 </tr>
 <tr>
  <td>list.pop()</td>
  <td>删除列表中的成员,括号中为位置</td>
 </tr>
 <tr>
  <td>list.remove()</td>
  <td>删除列表中的成员,括号中为成员</td>
 </tr>
 <tr>
  <td>list.reverse()</td>
  <td>将列表中的成员顺序颠倒</td>
 </tr>
 <tr>
  <td>list.sort()</td>
  <td>将列表中成员排序</td>
 </tr>
</table>


<table>
 <tr>
  <td>字典操作</td>
  <td>描述</td>
 </tr>
 <tr>
  <td>dic.clear()</td>
  <td>清空字典</td>
 </tr>
 <tr>
  <td>dic.copy()</td>
  <td>复制字典</td>
 </tr>
 <tr>
  <td>dic.get(k)</td>
  <td>获得键k的值</td>
 </tr>
 <tr>
  <td>dic.has_key(k)</td>
  <td>是否包含键k</td>
 </tr>
 <tr>
  <td>dic.items()</td>
  <td>获得由键和值组成的列表</td>
 </tr>
 <tr>
  <td>dic.keys()</td>
  <td>获得键的列表</td>
 </tr>
 <tr>
  <td>dic.pop(k)</td>
  <td>删除键k</td>
 </tr>
 <tr>
  <td>dic.update({‘键’：值})</td>
  <td>更新成员</td>
 </tr>
 <tr>
  <td>dic.values()</td>
  <td>获得值的列表</td>
 </tr>
</table>


 **常用文件操作：**

 打开文件：

  `open(file_name, mode, buffer_size)    # 文件名，模式(r,w,b)，缓存区大小 `

 <table>
 <tr>
  <td>操作</td>
  <td>描述</td>
 </tr>
 <tr>
  <td>file.read()</td>
  <td>将整个文件读入字符串中</td>
 </tr>
 <tr>
  <td>file.readline()</td>
  <td>读入文件的一行字符串中</td>
 </tr>
 <tr>
  <td>file.readlines()</td>
  <td>将整个文件按行读入列表中</td>
 </tr>
 <tr>
  <td>file.write()</td>
  <td>向文件中写入字符串</td>
 </tr>
 <tr>
  <td>file.writelines()</td>
  <td>向文件中写入一个列表</td>
 </tr>
 <tr>
  <td>file.close()</td>
  <td>关闭打开的文件</td>
 </tr>
</table>


 **循环：**

      for num in [...]:
          continue
          break
      else:
          # 未被 break 时执行的代码

`range([start,] stop [,step])`

 **函数声明：**

     def <function_name> (param=default_value[,...]):
         <function_statement>
         return <return_value>

 **调用函数时，只能一次对参数赋值，不能用(, , x) 之类的赋值。使用下面的例子可以解决：**

     def example(x=None, y=None, z=None):
         if x is None:
             x = 1
         if y is None:
             y = 2
         if z is None:
             z = 3
         return (x + y + z)

 *另外，调用函数的时候，可以直接对参数赋值而不考虑参数的顺序：*

     def fun(x, y):
         return x - y
     
     >>> fun(1, 2)
     -1
     >>> fun(y=1, x=2)
     1
 
 只输入函数名，不加括号，则返回函数在内存中的地址

 若想将函数所有参数都放到一个元组里，可以使用

  `def fun(**params)`

 在 Python 中，使用可变对象（如列表）来表达改变参数值的目的。

 Python 作用域分为：

  1. 内置作用域
  1. 局部作用域
  1. 全局作用域

 `global x     # 定义全局作用域`

用 lambda 声明匿名函数（没有函数名的函数）：

     fun = lambda x : x * x - 1
     >>> fun(3)
     8

*lambda 适用于小函数，可以调用函数，不能使用 print*

**导入模块**

    >>> import module
    >>> import module as new_name
    >>> from module import func

**修改模块查找路径**

    >>> import os
    >>> import sys
    >>> os.getcwd()  # 当前工作目录
    >>> sys.path     # Python 的查找路径。列表形式。

**手动编译**

    >>> import py_compile
    >>> py_compile.compile("/path/to/python/file")

**手动优化编译**

    >>> python -o file/to/output
    >>> python -oo file/to/output

**Python 脚本中的 __name__ 属性：**

   * 当脚本被当作模块导入时，`__name__` 属性值为该模块名
   * 当脚本独立运行时，`__name__` 属性值为 `__main__`

`dir()` ： 可以获得导入模块中的所有定义的名字、函数。

**Python 路径区分大小写！**

**模块包**

 * 包相当于一个目录，在目录里新建一个名为 `__init__.py` 的文件，可以为空，表示这个目录为一个包。
 * `__init__.py` 的主要用途是设置 `__all__` 以及包含包初始所需要的代码。
 * 相同目录直接使用 `import`
 * 不同目录使用: `from A.B import a`

** Python 中的正则表达式 **

<table>
 <tr>
  <td>元字符</td>
  <td>含义</td>
 </tr>
 <tr>
  <td>.</td>
  <td>除换行外任何单个字符</td>
 </tr>
 <tr>
  <td>*</td>
  <td>位于*之前的任意个字符</td>
 </tr>
 <tr>
  <td>+</td>
  <td>位于+之前的一个或多个字符(不能0个)</td>
 </tr>
 <tr>
  <td>|</td>
  <td>位于|前后的字符</td>
 </tr>
 <tr>
  <td>^</td>
  <td>匹配行首</td>
 </tr>
 <tr>
  <td>$</td>
  <td>匹配行尾</td>
 </tr>
 <tr>
  <td>?</td>
  <td>位于?之前的零个或者一个字符.</td>
 </tr>
 <tr>
  <td>\</td>
  <td>表示位于\之后的转义字符</td>
 </tr>
 <tr>
  <td>[]</td>
  <td>匹配位于[]之中的</td>
 </tr>
 <tr>
  <td>()</td>
  <td>将位于()内的内容当作一个整体</td>
 </tr>
 <tr>
  <td>{}</td>
  <td>重复操作次数</td>
 </tr>
</table>

 * 函数用于在字符串中匹配正则表达式 匹配成功返回MatchObject对象实例 
`re.match(pattern, string [,flags])`
 * 函数用于在字符串中查找正则表达式,如果找到,则返回MatchObject对象实例.
`re.search(pattern ,string[,flags])`
 * 函数用于在字符串中查找所有符合正则表达式的字符串,并返回这些字符串的列表.
`re.findall(pattern ,string[,flags])`

pattern： 匹配模式

string： 要进行匹配的字符串

flags：可选参数，进行匹配的标志

flags:

 1. re.I：忽略大小写。
 1. re.L：根据本地设置而更换\w \W \b \B \s \S 的匹配内容
 1. re.M 多行匹配模式
 1. re.S 使用 "." 元字符匹配换行符
 1. re.U 匹配 Unicode 字符。
 1. re.X 忽略 pattern 中的空格，并且可以使用 "#" 注释。

`re.sub(pattern, replacement, string [,maxcount])` 用于替换字符串中符合正则表达式的内容，它返回替换后的字符串。
`re.subn(pattern, replacement, string [,maxcount])` 与 re.sub() 函数相同，只不过返回的是一个元组
`re.split(pattern, string [,maxsplit=0])` 用于分割字符串
`re.compile(pattern [,flags])` 将正则表达式编译生成正则表达式对象实例后，可以使用正则表达式对象实例提供的属性和方法对字符串进行处理。生成一个 RegexObject 对象实例。

<table>
 <tr>
  <td>转义字符</td>
  <td>含义</td>
 </tr>
 <tr>
  <td>\\b (\b为退格)</td>
  <td>匹配单词头或者单词尾</td>
 </tr>
 <tr>
  <td>\\B</td>
  <td>与\b含义相反</td>
 </tr>
 <tr>
  <td>\d</td>
  <td>匹配任何数字</td>
 </tr>
 <tr>
  <td>\D</td>
  <td>匹配任何非数字</td>
 </tr>
 <tr>
  <td>\s</td>
  <td>匹配任何空白字符</td>
 </tr>
 <tr>
  <td>\S</td>
  <td>匹配任何非空白字符</td>
 </tr>
 <tr>
  <td>\w</td>
  <td>匹配任何字母,.数字,以及下划线</td>
 </tr>
 <tr>
  <td>\W</td>
  <td>匹配任何非数字,字母,下划线.</td>
 </tr>
</table>

**使用组**

 * 组允许将正则表达式分解成几个不同的组成部分.在完成匹配或者搜索后,可以使用组编号访问不同部分匹配的内容.
 * 组的扩展语法
  2. (?Lmsux) 设置匹配标志,可以是i.L.m.s.u.x 以及他们的组合.其含义与编译标志相同.
  2. (?:...)  表示此非一个组
  2. (?P=name) 表示在此之前的名为name的组
  2. (?#...) 表示注释
  2. (?=...) 用于正则表达式之后,表示如果”=”后的内容在字符串中出现则匹配,但不返回”=”后的内容.
  2. (?!...) 用于正则表达式之后,表示如果”!”后的内容在字符串中不出现则匹配,但不返回”!”后的内容.
  2. (?<=...) 用于正则表达式之前,与(?=...)含义相同.
  2. (?<!...)) 用于正则表达式之前,与(?!...)含义相同.

## 有关面向对象的思想 

 * 面向对象强调对象的“抽象”、“封装”、“继承”、“多态”。
 * 面向对象程序设计方法的基本思想是将任何事物都当作对象，是其所属对象类的一个实例。
 * 每一个对象都有其相对应的对象类。属于同一对象类的对象具有相同的属性以及操作方法等。
 * 对象以对象类的形式将其内部的数据或者方法封装。对象与对象之间只是互相传递数据，而不能访问其他对象的内部。
 * 对象的内部相对于其他对象来说是不可见的。不同的对象类之间可以通过集成的形式来拥有其他对象的属性和方法等，而形成父子关系。
 * 面向对象程序设计的方法的基本过程：
  2. 确定对象以其属性和方法等。
  2. 分析对象之间的联系确定其通信机制。
  2. 将具有共同特征的对象抽象为对象类。
  2. 设计、实现类，并确定类相互间的继承关系。
  2. 创建对象实例，实现对形象之间的相互联系。

在Python中可以使用类建立一个对象模型，以及对象所拥有的属性和方法等。该模型能够较好地反应实物的本质，以及其相互之间的关系，其本质是更接近于人类认知事物所采用的计算模型。

**类与对象**

 * 类是面向对象程序设计的基础。类具有抽象性、封装性、继承性和多态性。
 * 类的抽象性是指类是对具有共同方法和属性的一类对象的描述。
 * 类的封装型是指类将属性和方法封装，对于外部是不可见的。只有通过类提供的接口才能与属于类的实例对象进行信息交换。
 * 类的继承性是指类可以由己有的类派生。派生出来的类拥有父类的方法和属性等。
 * 类的多态性是指类可以根据不同的参数类型调用不同的方法。同一个方法可以处理不同类型的参数。实际上Python的内部已经很好地实现了多态。在Python中使用类不需要考虑太多不同类型数据之间的处理。
 * 每个类都有具有自己的属性和方法。类的属性实际上就是类内部的变量。而类的方法则是在类内部定义的函数。
 * 对象是具体的事物，是实例化后的类。每个对象的属性值可能不一样，但所有由同一类实例化得类的对象都拥有共同的属性和方法。
 * 在程序中由类实例化生成的对象，然后使用对象的方法进行操作，完成任务。一个类的可以实例化生成多个对象。

** 类的定义 **

 * 类的定义与函数的定义类似，但使用`class`关键字。同样需要注意缩进。
 * 类的定义一般放在脚本的头部。在PY中也可以在if语句的分支中或者函数定义中定义类。

        >>> class class_name:
        >>>     statements

 * 类还可以通过继承的形式获得。

        >>> class sub_name(parent_name):
        >>>     statements

 * 父类，也就是要继承的类。
 * 类定义后就产生了一个名字空间，与函数类似。在类内部使用的属性，相当于函数中的变量名，还可以在类的外部继续使用。类的内部与函数的内部一样，相当于一个局部作用域。不同类的内部也可以使用相同的属性名。

**类的使用**

 类在定义后必须先实例化才能使用。类的实例化与函数调用类似，只要使用类名加圆括号的形式就可以实例化一个类。类实例化以后会生成一个对象。一个类可以实例化多个对象，对象与对象之间并不互相影响。类实例化以后可以使用其属性和方法等。

**类的属性和方法**
 
 每一个类都具有自己的属性和方法。属性和方法是面向对象程序设计所独有的概念。属性是类所封装的数据，而方法则是类对数据进行的操作。

**类的属性**

 * 类的属性实际上是类内部的变量。
 * 类的属性分为 `公有属性` 和 `私有属性`。
 * 数据保护是面向对象程序设计所特有的，在面向过程的程序设计中并没有数据保护的概念。
 * 在Python中，类的内部声明一个私有成员不需要使用private关键字。而是用类中的属性的命名形式来表示类属性是公有还是私有的。
 * 类中的私有属性是不能在类的外部进行操作的，这边起到了对属性的保护作用。
 * Python中类的属性是以两条下划线开始的话，则该属性为类的私有属性，不能在类的外部被使用或访问。
 * 类的方法实际上就是类内部使用def关键字定义的函数。定义类的方法与定义一个函数基本相同，在类的方法中同样也要使用缩进。
 * 在类的内部使用def关键字可以为类定义一个方法。与函数定义不同的是，类的方法必须包含参数"self"，且"self"必须为第一个参数。
 * 与类的属性相同，类的方法也可以是类私有的，类的私有方法不能在类的外部调用。和类的私有属性命名相同，类的私有方法名也要以两条下划线开始。类的私有方法只能在类的内部调用，而不能在类的外部调用。另外，在类的内部调用起私有方法。要使用"self.私有方法名"的形式。

 **类的专用方法(Specail Methods)**

 * 在PY中有一类以两条下弧线开始并且以两条下划线结束的类的方法，称之为类的转悠方法。专有方法是针对类的特殊操作。(private)


<table>
 <tr>
  <td>方法名</td>
  <td>描述</td>
 </tr>
 <tr>
  <td>_init_</td>
  <td>构造函数，生成对象时调用</td>
 </tr>
 <tr>
  <td>_del_</td>
  <td>析构函数，释放对象时调用</td>
 </tr>
 <tr>
  <td>_add_</td>
  <td>加运算</td>
 </tr>
 <tr>
  <td>_mul_</td>
  <td>乘运算</td>
 </tr>
 <tr>
  <td>_cmp_</td>
  <td>比较运算</td>
 </tr>
 <tr>
  <td>_repr_</td>
  <td>打印、转换</td>
 </tr>
 <tr>
  <td>_setitem_</td>
  <td>按照索引赋值</td>
 </tr>
 <tr>
  <td>_getitem_</td>
  <td>按照索引获取值</td>
 </tr>
 <tr>
  <td>_len_</td>
  <td>获得长度</td>
 </tr>
 <tr>
  <td>_call_</td>
  <td>函数调用</td>
 </tr>
</table>


**类的继承**

 * 一个新类可以通过继承来获得已有类的方法以及属性。
 * 新类可以继承父类的共有属性和共有方法，但是不能继承分类的私有属性和私有方法。


**多重继承**

 多重继承是指创建的类同时拥有几个类的属性和方法。多重继承与单重继承不同的是在类名后边的圆括号中包含多个父类名，父类名之间用逗号分开。

       class class_name(parent1, parent2):
           pass

 多重继承需要注意圆括号中的父类名字的顺序。如果父类中有相同方法名，而在类中使用是未定义父类名，则使用前面的父类的方法。

***重载 ！***

重载允许通过继承而创建的类重新定义父类的方法。不仅可以重载方法，而且还可以重载运算符，以使用自创建的类。

 **方法重载**

 * 通过继承而创建的类，其父类的方法不一定能满足类的需要。新类实际上只是该部分功能，为了避免明明函数的麻烦而可以使用方法重载来解决。
 * 方法的重载实际上就是在类中使用`def`关键字重载父类的方法。如果重载父类中的方法，但又需要在类中先使用父类的该方法，可以使用父类名加`.`加方法名的形式调用。

**运算符重载**

Python中运算符都有相对应的函数，在类中运算符都有相对应的专有方法。因此运算符的重载实际上是对运算符对应的专有方法的重载。

<table>
 <tr>
  <td>运算符</td>
  <td>专有方法</td>
</tr>
<tr>
 <td>+</td>
 <td>_add_</td>
</tr>
<tr>
 <td>-</td>
 <td>_sub_</td>
</tr>
<tr>
 <td>*</td>
 <td>_mul_</td>
</tr>
<tr>
 <td>/</td>
 <td>_div_</td>
</tr>
<tr>
 <td>%</td>
 <td>_mod_</td>
</tr>
<tr>
 <td>**</td>
 <td>_pow_</td>
</tr>
</table>

**模块中的类**

 类与函数一样，也可以写到模块中。在其他的脚本中可以通过导入模块名使用定义的类。模块中类的使用方式与模块中函数类似。实际上可以将模块中的类当作函数一样使用。

**异常与调试**

 使用`try`语句处理异常。和 Python 中其他语句一样，`try`语句也要使用缩进结果。`try`语句也有一个可选的else语句块。

    try:
        pass
    except<exception1>:
        pass
    except<exception2>:
        pass
    else:
        pass

 try语句还有另外一种特殊的形式:

    try:
        pass
    finally:
        pass

 不管try语句中是否发生异常,都将执行finally 语句块。

<table>
 <tr>
  <td> 常用异常名 </td>
  <td>描述</td>
 </tr>
 <tr>
  <td>AttributeError</td>
  <td>调用不存在的方法引发的异常</td>
 </tr>
 <tr>
  <td>EOFerror</td>
  <td>遇到文件末尾引发的异常</td>
 </tr>
 <tr>
  <td>ImpoertError</td>
  <td>导入模块出错引发的异常</td>
 </tr>
 <tr>
  <td>IndexError</td>
  <td>列表越界引发的异常</td>
 </tr>
 <tr>
  <td>IOError</td>
  <td>I/O操作引发的异常,如打开文件出错等.</td>
 </tr>
 <tr>
  <td>KeyError</td>
  <td>使用字典中不存在的关键字引发的异常</td>
 </tr>
 <tr>
  <td>NameError</td>
  <td>使用不存在的变量名引发的异常</td>
 </tr>
 <tr>
  <td>TabError</td>
  <td>语句块缩进不正确引发的异常.</td>
 </tr>
 <tr>
  <td>ValueError</td>
  <td>搜索列表中不存在的值引发的异常</td>
 </tr>
 <tr>
  <td>ZeroDivision</td>
  <td>除数为零.</td>
 </tr>
</table>

**多重异常处理**

 在Python中可以在try语句中嵌套另外一个try语句。由于Python将try语句放在堆栈中，一旦引发异常，Python将匹配最近的except语句。如果except忽略该异常，则异常将被外围try语句捕获。

**引发异常**

除了内置的异常意外，在Python中还可以通过使用raise语句手工引发异常。在类中也可以使用raise 引发异常，并向异常传递数据。使用raise可以定义新的错误类型，以适应脚本的需要。例如对用户输入数据的长度有要求，则可以使用raise引发异常，以确保数据输入符合要求。

 *使用raise引发异常*

    raise exception
    raise exception, data
    raise class_name
    assert  simplified_raise_statement
    assert  condition_test, exception_data

 * 在Python中使用`assert`语句同样可以引发异常。但与`raise`语句不同，`assert`语句是在条件测试为假时，才引发异常.
 * `assert` 一般用于开发时对程序条件的验证.只有当内置`__debug__`为`True`时，`assert`语句才有效.当 Python 脚本以-O选项编译成字节码文件时，`assert`语句将被移除.

**自定义异常类**

在 Python 中可以通过继承 `Exception` 类来创建自己的异常类。异常类和其他的类并没有区别，一般仅在异常类中定义几个属性信息。

**使用pdb调试**

  在 Python 中脚本的语法错误可以被 Python 解释器发现，但是脚本出现的错误，或者其他的一些变量使用错误却不容易被发现。如果脚本运行后没有获得预想的结果，则需要对脚本进行调试。pdb模块是Python自带的调试模块。使用该模块可以为脚本设置断点、单步执行、查看变量值等。pdb模块可以以命令行参数的形式启动，也可以通过 `import` 将其导入使用。

*运行语句*

    run(statement [,global[, localst]])
    statement: 要调试的语句块，以字符串的形式。
    globals 可选参数,设置statement 运行的全局环境变量.
    locals 可选参数 设置statement运行的局部环境变量

**运行表达式**

在`Python`中可以使用 `pdb` 模块的`runeval`函数来调试表达式。

    runevel(expression[,globals[,locals]])
    expression：要调试的表达式，以字符串的形式。
    globals：可选参数，设置statement运行的全局环境变量。
    locals：可选参数，设置statement运行的局部环境变量。

**运行函数**

在 Python 中可以使用 pdb 模块的`runcall`函数来调试函数。
    runcall(function[, argument,...])
    function  函数名
    argument  函数的参数

**设置硬断点**

 在Python中可以使用pdb模块的set_trace函数在脚本中设置硬断点.set_trace 函数一般在".py"脚本中使用。

    set_trace()
    (Pdb) list  列出脚本内容
    (Pdb) continue   继续执行

<table>
 <tr>
  <td>完整命令</td>
  <td>简写命令</td>
  <td>描述</td>
 </tr>
 <tr>
  <td>args</td>
  <td>a</td>
  <td>打印当前函数的参数</td>
 </tr>
 <tr>
  <td>break</td>
  <td>b</td>
  <td>设置断点</td>
 </tr>
 <tr>
  <td>clear</td>
  <td>cl</td>
  <td>清除断点</td>
 </tr>
 <tr>
  <td>condition</td>
  <td></td>
  <td>设置条件断点</td>
 </tr>
 <tr>
  <td>continue</td>
  <td>c或者cont</td>
  <td>继续运行,直到遇到断点或者脚本结束</td>
 </tr>
 <tr>
  <td>disable</td>
  <td>无</td>
  <td>禁用断点</td>
 </tr>
 <tr>
  <td>enable</td>
  <td>无</td>
  <td>启用断点</td>
 </tr>
 <tr>
  <td>help</td>
  <td>h</td>
  <td>查看pdb帮助</td>
 </tr>
 <tr>
  <td>ignore</td>
  <td>无</td>
  <td>忽略断点</td>
 </tr>
 <tr>
  <td>jump</td>
  <td>j</td>
  <td>跳转到指定行数运行</td>
 </tr>
 <tr>
  <td>list</td>
  <td>l</td>
  <td>列出脚本清单</td>
 </tr>
 <tr>
  <td>next</td>
  <td>n</td>
  <td>执行下条语句,遇到函数不进入其内部</td>
 </tr>
 <tr>
  <td>p</td>
  <td>p</td>
  <td>打印变量值,也可以用print</td>
 </tr>
 <tr>
  <td>quit</td>
  <td>q</td>
  <td>退出pdb</td>
 </tr>
 <tr>
  <td>return</td>
  <td>r</td>
  <td>一直运行到函数返回</td>
 </tr>
 <tr>
  <td>tbreak</td>
  <td>无</td>
  <td>设置临时断点,断点只中断一次</td>
 </tr>
 <tr>
  <td>step</td>
  <td>s</td>
  <td>执行下一条语句,遇到函数进入其内部</td>
 </tr>
 <tr>
  <td>where</td>
  <td>w</td>
  <td>查看所在的位置</td>
 </tr>
 <tr>
  <td>!</td>
  <td>无</td>
  <td>在pdb中执行语句</td>
 </tr>
</table>

**Python扩展和嵌入**

 * 通过扩展Python 用C/C++来完成对效率要求高的部分.Python功能强大,完全可以将其嵌入到C/C++中.
 * Python提供了支持C/C++接口,可以方便地使用C/C++来扩展Python.用C/C++编写的Python扩张主要用于完成底层的系统操作,以及提高执行速度.
 * Python提供了接口API.通过使用API函数可以编写Python扩展.
