/* ATM simulator 
**2010.07.29 by alex.
*/
#include <iostream>
#include <vector>
#include <fstream>
#include "user.h"
#include "atm.h"
#include "card.h"
using namespace std;
int main()
{
	ATM atm;
	atm.on_off();
	atm.read_account();
	/*init menu_choice */
	int menu_choice=1;
	while(1)
	{
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
	}
	return 0;
}