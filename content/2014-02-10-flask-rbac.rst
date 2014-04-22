flask-rbac
##########

:date: 2014-02-10 00:19
:tags: Python

前几个月开始写 MOOC 的时候，发现网上没有 RBAC 的 Flask 插件。于是自己 DIY 一个。

用了一天做了一个雏形，也融到 MOOC 里用着。

两周前突然想要发布到 pypi 上，于是完善了文档，完善了各种 files。最后也 publish 到 pypi 上了。

当天下载量就有 300+ 觉得可满足了~

之后说说我认为还要改进的部分。

(1) Model 设计不太友好
- Flask-RBAC 希望能权限信息支持以持久化处理及直接以 module 两种形式存储。但是目前两者是统一着的，因此部分接口设计使用起来并不太友好。

(2) 不支持纯 SQL 语言
- 使用数据库来存储权限信息的时候，提供的接口是对 SQLAlchemy 兼容，而对纯 SQL 例如 MySQLdb 等库并不兼容。

(3) 不够“动态”
- 目前只支持 Role 可持久化。而 ACL 依旧保存在 Python modules 中。

项目仍处于开发状态，有兴趣的童鞋欢迎加入：

github repository: https://github.com/shonenada/flask-rbac

Document: https://flask-rbac.readthedocs.org/en/latest/
