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

2.��Ŀ֪ʶ��
������ (ע�ͣ�����...)
���ÿ�Դ����
���ģʽ (Singleton,Factory,Bridge,Observer,Strategy,Template...)��ʹ��
��Ŀƽ̨��ֲ
��̳У���̳�
�������������
��const����2���汾�ĺ���ʵ��
����ָ���ʵ��
�麯���������า�ǣ������Ҳ��������
�������˼��
Vectorģ���ʵ��
'=' ����ʵ�� return *this
static ��Ա�������ʼ��
STLģ��ʹ��
һЩ�ؼ��ʵ�ʹ�� explicit, inline,namespace,friend
try/catch �쳣����
sort ��������ʵ��
ʵ�־�̬���ӿ� (libATM.a)
ģ���ļ�ϵͳ (AlexFs)
���빹������ scons
�ĵ����ɹ��� Doxygen
windows���ɿ������� Visual Studio 2008

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
