# OrderSystem_Embedded
QT5编写的嵌入式程序，点菜系统。
## 环境
使用QT5编写界面，数据库采用sqlite3；

嵌入式开发版为iTop-4412精英版

Linux开发环境为VMware安装的Ubuntu16.04LTS镜像。

## 说明

```
使用Ubuntu的交叉编译器分别编译出QT环境，sqlite3数据库，以及应用源码。在烧录进开发版中测试。开发版的QT环境需要字库支持才能正确显示程序中的中文。

数据库中的数据都为虚拟数据。无实在意义。
```