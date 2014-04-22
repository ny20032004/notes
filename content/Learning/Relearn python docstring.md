---
layout: post
title: "[Relearn Python] DocString"
date: 2013-05-12 02:28
comments: true
categories: 
---
By [shonenada](http://www.shonenada.com) on 2013-5-12

What is 
------
Docstring is a description statement in a function, a method, a module or a class. It becomes the special attribute `__doc__`.

Any functions, modules, classes and packages should normally have docstring.

One-line docstring
----------------
Please note this:

1. One-line docstring is surrounded by triple quotes, even thought they can write in a line.
1. There is no blanks line before or after docstring.
1. Thers is no blanks after the openning quote and no blanks before the closing quote.
1. Docstring should be a phrase prescribes the function or method's effect as a command, but no a description.
1. Docstring should not reiterating the parameters of function/method.

Multi-line docstring
<!-- more -->
-----------------
Multi-line docstring consist of a summary line, a blank line, and more elaborate description. Looks like:

    def complex(real=0.0, imag=0.0):
    """Form a complex number.
		
        Keyword arguments:
        real -- the real part (default 0.0)
        imag -- the imaginary part (default 0.0)

        """
        if imag == 0.0 and real == 0.0: return complex_zero
        ...

The summary line may be used by automatic indexing tools, and it is important to fit in one line and seperte from the rest of docstring.

* The docstring of a script should document the usage of this script.Such as the function of script, command syntax, environment requirements, and files.
* The docstring for a module generally list the classes, exceptions and functions that are exported by the module. These summaries give less details than the summary line.

* The docstring for a package( The docstring of the package's `__init.py` module) should list the modules and subpackages exported by the package.

* The docstring for a fucntion or method should summarize its behavior. Also list the arguments, return type, side effects, exception raised and restrictions.

* The docstring for a class should summarize its behavior and list the public methods ahd instance variables. It the class is intended to be subclass, and has an additional interface for subclasses, this interface should be listed separetely in the docstring.

* 

References
---------
1. [PEP257](http://www.python.org/dev/peps/pep-0257/)