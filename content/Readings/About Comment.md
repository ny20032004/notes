关于注释
--------

 最近在看《代码整洁之道》，改变了关于“注释”的看法：

 一直觉得写程序，注释需要很多很多，那一行行的灰色的英文甚至比那些带着各种颜色的单词更让我觉得兴奋。
 结合最近一些开发经验，对注释的看法有一个彻头彻尾的改变：没有注释的代码才是好代码。

 1. 注释存在的原因是你对你所写的代码不自信的一种心理弥补。你试图通过注释向维护者阐明这段代码在做什么要做什么。这种做法还不如重构代码，将代码写得清晰。只要程序思路够清晰，只要每个函数都只做一件事，只要KISS，维护者就能够看明白程序在做什么。
 1. 多了注释，就多了维护的成本。注释的地位常常介于实现代码与僵尸代码之间。很多时候对实现代码进行了修改却忘记修改注释，提供错误的注释比不提供注释更要迷惑维护者！这种情况非常容易发生，因为程序永远会有 bug …
 1. 需要特别提一下的是，维护者往往是几天几周几个月之后的自己。
 1. 但文档是必须的！不管程序是否有非开发者的用户都需要一份详细的使用操作文档。文档和注释不是一回事。