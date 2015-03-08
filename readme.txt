1.Develop Environment

windows : Visual Studio 2008
$windows.bat

linux : g++
$cd shell-simulator
$scons
$cd Debug
$./alex


Generate Docs
$doxygen

2.项目知识点
代码风格 (注释，命名...)
复用开源代码
设计模式 (Singleton,Factory,Bridge,Observer,Strategy,Template...)的使用
项目平台移植
多继承，虚继承
抽象基类虚析构
有const对象，2个版本的函数实现
智能指针的实现
虚函数对于子类覆盖，本类间也可以重载
面向对象思想
Vector模板的实现
'=' 重载实现 return *this
static 成员，类外初始化
STL模板使用
一些关键词的使用 explicit, inline,namespace,friend
try/catch 异常处理
sort 调度器的实现
实现静态链接库 (libATM.a)
模拟文件系统 (AlexFs)
代码构建工具 scons
文档生成工具 Doxygen
windows集成开发工具 Visual Studio 2008

3.Main Page
http://code.google.com/p/shell-simulator/

4.about bin/ directory
Just use the GnuWIn32 project.
The GnuWin32 project provides native ports in the form of runnable computer programs, patches, and source code for various GNU and open source tools and software, much of it modified to run on the 32-bit Windows platform. The ports included in the GnuWin32 packages are:
GNU utilities such as bc, bison, chess, Coreutils, diffutils, ed, Flex, gawk, gettext, grep, Groff, gzip, iconv, less, m4, patch, readline, rx, sharutils, sed, tar, texinfo, units, wget, which
Archive management and compression tools, such as: arc, arj, bzip2, gzip, lha, zip, zlib.
Non-GNU utilities such as: cygutils, file, ntfsprogs, openssl, pcre.
Graphics tools.
PDCurses
Tools for processing text.
Mathematical Software and Statistics Software.

To use these commands ,just run windows.bat!
In this way , to realize external command support ,then we can not only design command embedded in shell,
we can design some commands projects independent from shell project.

5.Addition
atm command's user information

user-name password
000001    123456
000002    111111
000003    234567
000004    345678
000005    456789
000006    567891

6.Tab Completion
Linux version ,support tab completion.
Use the GNU readline library.

sudo apt-get install libreadline6-dev
or
Use the readline6.1 source code
./configure 
make
make install

In Windows ,just use cygwin 
./configure
make
get the libhistory.a , libreadline.a
also can realize tab completion .
