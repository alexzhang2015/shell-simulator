/*
 * Shell Simulator 
 * 2010.08.09 by alex
 * ͨ��Bridgeģʽ��������Shell�ܹ���
 * 2010.08.16 by alex
 * ���������н��� Shell,parser() ,��ShellCommand��execute() ,������ڲ�����
 * 2010.08.17 by alex
 * ����ATM����ģ�飬��Linuxƽ̨����ֲ��
 * 2010.08.18 by alex
 * ����filesystemģ�飬history�����¼��AlexFS�ϣ�����factary ģʽ��
 * observerģʽ��
 * 2010.08.19 by alex
 * ����singleton ģʽ�����cat���
 * 2010.08.20 by alex
 * ����sort ģ�飬��Ҫͨ��strategyģʽ�����sort�ӿڡ�
 * 2010.08.21 by alex
 * ���� smart_pointer ģ���ʵ�֡�
 * 2010.08.22 by alex
 * ���� SortScheduler sort�����е�һ����������
 * 2010.09.06 by alex
 * Add ping command in GNU OS.
 * 2010.09.08 by alex
 * Add sqlite database for Atm log system.
 * 2010.09.14 by alex
 * Add ChangeDirCommand .
 * 2010.09.15 by alex
 * Add extern commands /bin for Windows version.
 * 2010.09.16 by alex
 * Add Tab Completion for Linux version.
 */

#include "shell/Shell.h"

int main()
{

	/* shell run loop. */
	Shell sh;
	sh.run();
	return 0;
}
