# C/C++ PRO Theme 介绍

---

**一个专门为 C/C++ 程序员设计的 VSCode 主题**

---

## 有什么亮点

C/C++ Pro Theme 可以基于 LSP 解析的语法 token 对源文件里更多的元素进行高亮显示。 

目前 VSCode 主流的 C/C++ LSP 有微软 C/C++插件和 clangd 插件，C/C++ Pro Theme 对两者都有相对完整的支持。

借助于 LSP 强大的语法分析能力，C/C++ Pro Theme 提供以下额外的高亮显示：

- 支持全局变量、静态全局变量的高亮
- 显示变量 const 属性
- 区分显示 == 和 =、&& 和 &等逻辑运算发
- 区分显示普通函数和静态函数
- 区分显示 parameter、local variable 及 property
- 区分实现 enum 值和 macro

更多视觉强化细节等待大家使用后解锁。

## 为什么做这个主题

没事时就想搞点这些小工具。我还做了一个串口助手 [comNG](https://gitee.com/xenkuo/comNG)， 大家也可以试试。

下面给各位看官炫几张截图：

> C/C++ Pro Theme 配合 MS C/C++插件

![](image/README_2023-06-22-21-02-03.png)

> C/C++ Pro Theme 配合 clangd 插件

![](image/README_2023-06-22-21-03-10.png)

**C/C++ Pro Theme** 系统设计图：

![](image/The%20C%202023-04-29%2021.23.52.excalidraw.png)

## 怎么使用

VSCode 插件市场直接搜索 C/C++ Pro Theme 安装即可。

## 大家一起参与

仓库地址： [CCPRO_theme](https://github.com/xenkuo/ccpro_theme)，欢迎 PR。
