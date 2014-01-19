---
layout: post
title: "Semantic Versioning"
date: 2014-01-18 13:59
comments: true
categories: 
---

Introduction
============
_Semantic Versioning_ 即语义化版本识别，是一套用来规范定义软件版本的规则。官网： [http://semver.org](http://semver.org)

Usage
=====
SemVer 的基本格式是 __主版本号.次版本号.修订号(-先行版本号或元数据信息)__ 。

1. 主版本号：当 Public API 做了向下不兼容的修改的时候，递增。
2. 次版本号：当 Public API 做了向下兼容的修改的时候，递增。
3. 修订号：修复了 Bug，但没有对 Public API 做修改的时候，递增。

Details
=======
以下是 SemVer 的细致规则：

1. 要使用 SemVer，首先你得有 __公共接口 (Public API)__ 。
2. SemVer 采用 X.Y.Z 的格式，其中 X、Y、Z 都是非负整数。
3. 发布了版本号后，禁止对软件进行修改。
4. X = 0 时候表示软件处于开发阶段，这个时 Public API 应视为不稳定的。
5. 1.0.0 用来定义 Public API ，之后的版本都基于这个版本的 API 修改。
6. 修订号 Z 递增的条件是做了向下兼容的修改，并且这个修改只是修改了之前的错误。
7. 次版本号 Y 递增条件是对 Public API 做了向下兼容修改。修改可能是弃用 API、API 有大量的修改等。每次修改次版本号，修订号必须规零。
8. 主版本号 X 递增条件是对 Public API 做了不向下兼容的修改，可以包含 次级别和修订级别 的修改。修改主版本号的时候，次版本号和修订号都必须归零。
9. 先行版本号标记在修订号后，用短横连接。先行版本号必须使用 ASCII 码。
