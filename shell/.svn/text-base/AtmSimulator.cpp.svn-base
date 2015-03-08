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
 * 1.设计这个命令主要用来测试，模块间的交接，atm项目作为一个
 * 独立的项目，完成shell中一个命令，抽象的接口是看成一个ATM
 * 模块，atm命令使用封装的接口做到OO，像实际处理ATM一样操作。
 * 2.atm项目，通过静态链接库方式生成，Shell项目，普通的控制台
 * 应用程序。对于execute,使用的是atm中的相关头文件，具体链接
 * 时则，通过找到debug文件夹中的atm.lib链接生成，shell.exe。
 * 3.对于主项目.shell ,右击选择其中的project dependencis,将
 * atm作为shell项目的库依赖，在编译shell项目时自动把atm作为
 * 静态链接库作为依赖编译。
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
