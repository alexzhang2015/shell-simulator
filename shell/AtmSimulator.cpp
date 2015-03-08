/**
 * Shell Simulator
 * 2010.08.17 by alex
 * AtmSimulator ,connect the ATM module
 */

#include "shell/AtmSimulator.h"

#include <iostream>
#include "atm/user.h"
#include "atm/atm.h"
#include "atm/card.h"

using namespace std;

AtmSimulator::AtmSimulator() : ShellCommand("atm")
{
}

/**
 * 1.������������Ҫ�������ԣ�ģ���Ľ��ӣ�atm��Ŀ��Ϊһ��
 * ��������Ŀ�����shell��һ���������Ľӿ��ǿ���һ��ATM
 * ģ�飬atm����ʹ�÷�װ�Ľӿ�����OO����ʵ�ʴ���ATMһ��������
 * 2.atm��Ŀ��ͨ����̬���ӿⷽʽ���ɣ�Shell��Ŀ����ͨ�Ŀ���̨
 * Ӧ�ó��򡣶���execute,ʹ�õ���atm�е����ͷ�ļ�����������
 * ʱ��ͨ���ҵ�debug�ļ����е�atm.lib�������ɣ�shell.exe��
 * 3.��������Ŀ.shell ,�һ�ѡ�����е�project dependencis,��
 * atm��Ϊshell��Ŀ�Ŀ��������ڱ���shell��Ŀʱ�Զ���atm��Ϊ
 * ��̬���ӿ���Ϊ�������롣
 */
void AtmSimulator::execute(int nparams, char **params)
{

	ATM atm;
	atm.on_off();

	atm.read_account();
	/*init menu_choice */
	int menu_choice=1;
	//while(1)
	//{
		string user_id,password;
		/*ATM get user_name ,password*/
		user_id=atm.input_name();
		password=atm.input_password();

		/*creat a card object */
		Card user_card("",password,user_id,0);
		if(atm.check_account(user_card))
		{
			Session session(&atm,&user_card);
			/*person just do the transaction*/
			User use(user_card,session);
			while(menu_choice!=5)
			{
				atm.print_operator();
				menu_choice=atm.menu_choice();
				use.choice(menu_choice);
			}
			menu_choice=1;
		}
		else
		{
			cout<<"\n\t\t\t\tcard_id or password wrong!"<<endl;
		}
	//}
   
}

const string AtmSimulator::cmd_help()
{
	return "Atm Simulator!";
}
