/*
 * ATM simulator 
 * 2010.07.29 by alex.
 */

#include "atm/atm.h"

#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

#include "base/Macro.h"
#include "base/md5.h"
#include "atm/card.h"
#include "third_party/tinyxml/tinyxml.h"
#include "third_party/tinyxml/tinystr.h"

#ifdef OS_WIN
#include <windows.h>
#include <conio.h>
#endif

#ifdef OS_GNU
#include <time.h>
#include <stdio.h>
#include <termios.h>
#endif

#define CARD_ACCOUNT 100
using namespace std;

ATM::ATM()
{
	Card tmp_card;
	for(int i=0;i<CARD_ACCOUNT;i++)
	{
		card.push_back(tmp_card);
	}
}

ATM::~ATM()
{
}

void ATM::print_operator()
{
	//system("cls");
	cout<<"\n\t\t\t\t1. Deposit Money!\n";
	cout<<"\t\t\t\t2. Withdraw Money !\n";
	cout<<"\t\t\t\t3. Account Information!\n";
	cout<<"\t\t\t\t4. Print The Log!\n";
	cout<<"\t\t\t\t5. Exit!\n";
	cout<<"\t\t\t\t";
}

/**
 * Linux getch() interface with termios.
 */
#ifdef OS_GNU
int getch()
{
	struct termios tm, tm_old;
	int fd = STDIN_FILENO, c;
	if (tcgetattr(fd, &tm) < 0)
	{
		return -1;
	}
	tm_old = tm;
	cfmakeraw(&tm);
	if (tcsetattr(fd, TCSANOW, &tm) < 0)
	{
		return -1;
	}
	c = fgetc(stdin);
	if (tcsetattr(fd, TCSANOW, &tm_old) < 0)
	{
		return -1;
	}
	return c;
}
#endif

string ATM::input_password()
{
        int c;
        string password = "";
        cout<<"\t\t\t\tpassword:";
        do   //Loop until 'Enter' is pressed
         {
#ifdef OS_WIN
         c = _getch();
#endif

#ifdef OS_GNU
                 c = getch();
#endif
         switch(c)
            {
            case 0:
               {
               break;
               }
            case '\b':
               {
               if(password.size() != 0)  //If the password string contains data, erase last character
                  {
                  //cout << "\b \b";
                  password.erase(password.size() - 1, 1);
                  }
               break;       
               }   
            default:
               {
               if(isalnum(c) || ispunct(c))
                  {
                  password += c;
                  cout << "*";           
                  }
               break;     
               }      
            };
         }
      while(c != '\r');
          return password;
}

string ATM::input_name()
{
	string name;
	cout<<"\t\t\t\tuser_id:";
	cin>>name;
	return name;
}

int ATM::menu_choice()
{
	cin.clear();   //sync the input buffer!
	cin.sync();
	int menu_choice;
	cin>>menu_choice;
	return menu_choice;
}

void ATM::on_off()
{
	cout<<"\t\t\t\tICBC ATM Running"<<endl; 
}

void ATM::read_account()
{
	/*
	 * Add the XML support !2011.03.31
	 */
	ofstream ofs("user.txt");
	if (ofs.is_open())
	{
		TiXmlDocument *xml_doc = new TiXmlDocument("user.xml");
		// Load XML file check.
		if (xml_doc->LoadFile())
		{
			TiXmlElement *RootElement = xml_doc->RootElement();
			TiXmlElement *ChildElement = RootElement->FirstChildElement();
			TiXmlElement *UserElenmet;
			for (; ChildElement; ChildElement = ChildElement->NextSiblingElement())
			{
				UserElenmet = ChildElement->FirstChildElement();
				ofs <<  ChildElement->FirstAttribute()->Value() << " " ;
				while (UserElenmet)
				{
					ofs << UserElenmet->FirstChild()->Value() << " ";
					UserElenmet = UserElenmet->NextSiblingElement();
				}
				ofs << "\t\n";
			}
		}
		else
		{
			cout << "Can't load user.xml " 
				 << endl;
		}
		delete xml_doc;
	}
	else
	{
		cout << "Can't create user.txt"
			 << endl;
	}
	ofs.close();



	ifstream ifs("user.txt");
	if(ifs.is_open())
	{
		for(int i=0;i<CARD_ACCOUNT;i++)
		{
			card[i].read(ifs);
			if(ifs.fail()!=0)
			{
				card_number=i;
				cout<<card_number;
				break;
			}
		}
	}
	else 
	{
		cout<<"fail opening user.txt\n";
	}
	ifs.close();
}

bool ATM::check_account(Card &user_card)
{
	/**
	 * The user password is MD5 type,so calc the user_password's MD5.
	 * Then compare the md5_user_password to the locale MD5 password.
	 */
	string user_password = user_card.get_password();
	/*MD5Digest md5_password;
	MD5Sum(user_password.c_str(), user_password.size(), &md5_password);
	string md5_user_password = MD5DigestToBase16(md5_password);*/
	string md5_user_password = MD5String(user_password);

	for(unsigned i=0;i<card.size();i++)
	{
		if(card[i].get_card_id()==user_card.get_card_id())
		{
			if(md5_user_password == card[i].get_password())
			{
				user_card.change_cash(card[i].get_cash());
				user_card.change_user_name(card[i].get_user_name());
				return true;
			}
		}
	}
	return false;
}

void ATM::initiate_deposit(Card& user_card)
{
	cout<<"\t\t\t\tinput money to deposit :";
	long cash;
	cin>>cash;
	int count=2;              //input count,3 times!
	//cout<<cin.fail();
	while((cash<=0) || cin.fail() )
	{
		cin.clear();
		cin.sync();
		cout<<"\n\t\t\t\tinput wrong! try again:";
		cin>>cash;
		if(--count==0)
			break;
	}
	if(count==0)
	{
		cin.clear();
		cin.sync();
		return ;
	}
	cout<<user_card.get_cash()<<endl;

	user_card.change_cash(user_card.get_cash()+cash);

	for(unsigned i=0;i<card.size();i++)
	{
		if(card[i].get_card_id()==user_card.get_card_id())
		{
			card[i].change_cash(user_card.get_cash());
		}
	}

	cout<<user_card.get_cash()<<endl;

	sync_user_info();

	finish_deposit(user_card,cash);
}

void ATM::finish_deposit(Card& user_card,long cash)
{
	
	cout<<"\t\t\t\tfinish deposit :"<<cash<<endl;

	/**
	 * Use store_log.txt handle the ATM log.
	 */
	//ofstream ofs("store_log.txt",ios::app);
	//if(ofs.is_open())
	//{
	//	
	//	ofs<<this->get_time()<<" "
	//		<<user_card.get_card_id()<<" "
	//		<<user_card.get_user_name()
	//		<<" store money:"
	//		<<cash<<"\t\n";
	//}
	//else
	//{
	//	cout<<"can't open store_log.txt\n"<<endl;
	//}
	//ofs.close();

	/**
	 * Use the Sqlite3 handle the log information.
	 */
	if (sqlite3_open("shell.db", &database) == SQLITE_OK)
	{
		sqlite3_stmt *statement;

		const char *log_type = " deposit money:";

		if (sqlite3_prepare_v2(database, "CREATE TABLE log (date TEXT,                 \
			                                                card_id TEXT  ,            \
															user_name TEXT,            \
															log_type TEXT,             \
															cash INTEGER);", -1, &statement, 0) == SQLITE_OK)
		{
			sqlite3_step(statement);
			sqlite3_finalize(statement);
		}

		char *query = sqlite3_mprintf("INSERT INTO log VALUES('%q', '%q', '%q', '%q', %d)",                         \
			                                                                   this->get_time().c_str(),            \
																			   user_card.get_card_id().c_str(),     \
																			   user_card.get_user_name().c_str(),   \
																			   log_type,                            \
																			   cash );
		if (sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK)
		{
			sqlite3_step(statement);
			sqlite3_finalize(statement);
		}
																			  
		else
		{
			cout << "deposit log fail!\n";
		}
		sqlite3_free(query);
		sqlite3_close(database); 
	}
	
	else
	{
		cout << "can't open shell.db\n"
			 << endl;
	}
	
}

void ATM::sync_user_info()
{
	/*
	ofstream ofs("user.txt");
	if (ofs.is_open())
	{
		for (int i = 0; i < card_number; i++)
		{
			ofs << card[i].get_user_name() << " "
				<< card[i].get_password() << " "
				<< card[i].get_card_id() << " "
				<< card[i].get_cash() << "\t\n";
		}
	}
	else
	{
		cout << "can't open user.txt\n" 
			 << endl;
	}
	ofs.close();
	*/

	/*
	 * Add the XML support !2011.03.31
	 */
	TiXmlDocument *xml_doc = new TiXmlDocument();
	TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
	xml_doc->LinkEndChild(decl);

	TiXmlElement * Users = new TiXmlElement( "Users" );
	Users->SetAttribute("num", 6);
	xml_doc->LinkEndChild(Users);

	
	for (int i = 0; i < card_number; i++)
	{
		TiXmlElement * User = new TiXmlElement("User");
		Users->LinkEndChild(User);
		User->SetAttribute("user_name", card[i].get_user_name().c_str());

		TiXmlElement * password = new TiXmlElement("password");
		password->LinkEndChild(new TiXmlText(card[i].get_password().c_str()));
		User->LinkEndChild(password);

		TiXmlElement * card_id = new TiXmlElement("card_id");
		card_id->LinkEndChild(new TiXmlText(card[i].get_card_id().c_str()));
		User->LinkEndChild(card_id);
		
		TiXmlElement * cash = new TiXmlElement("cash");
		char buf[12];
#ifdef OS_WIN
		sprintf_s(buf, 12, "%d", card[i].get_cash());
#endif
#ifdef OS_GNU
		sprintf(buf, 12, "%d", card[i].get_cash());
#endif
		cash->LinkEndChild(new TiXmlText(buf));
		User->LinkEndChild(cash);
	}

	xml_doc->SaveFile("user.xml");
	delete xml_doc;

}

void ATM::do_withdraw(Card &user_card)
{
	cout << "\t\t\t\tinput money to withdraw :";
	long cash;
	cin >> cash;
	int count = 2;              //input count,3 times!
	//cout<<cin.fail();
	while ( (cash <= 0) || cin.fail() )
	{
		cin.clear();
		cin.sync();
		cout <<"\n\t\t\t\tinput wrong! try again:";
		cin >> cash;
		if( --count == 0)
			break;
	}
	if (count == 0)
	{
		cin.clear();
		cin.sync();
		return ;
	}

	cout << user_card.get_cash()
		 << endl;

	if (user_card.get_cash() - cash <= 0)
	{
		cout << "\t\t\t\tInsufficient funds !"
			 << endl;
	}
	else
	{
		user_card.change_cash(user_card.get_cash() - cash);

		cout << user_card.get_cash()
			 << endl;

		for (unsigned i = 0; i < card.size(); i++)
		{
			if (card[i].get_card_id() == user_card.get_card_id())
			{
				card[i].change_cash(user_card.get_cash());
			}
		}
		sync_user_info();
		cout << "\t\t\t\tfinish withdraw :"
			 << cash
			 << endl;

		withdraw_log(user_card,cash);

	}
	
}

void ATM::withdraw_log(Card& user_card, long cash)
{

	/**
	 * Use the get_log.txt handle the withdraw log.
	 */
	//ofstream ofs("get_log.txt",ios::app);

	//if(ofs.is_open())
	//{
	//	ofs<<this->get_time()<<" "
	//		<<user_card.get_card_id()<<" "<<
	//		user_card.get_user_name()<<" get money:"
	//		<<cash<<"\t\n";
	//}
	//else
	//{
	//	cout<<"can't open get_log.txt\n"<<endl;
	//}
	//ofs.close();

	/**
	 * Use the shell.db handle the withdraw log.
	 */
	if (sqlite3_open("shell.db", &database) == SQLITE_OK)
	{
		sqlite3_stmt *statement;

		const char *log_type = " withdraw money:";

		if (sqlite3_prepare_v2(database, "CREATE TABLE log (date TEXT,                 \
			                                                card_id TEXT   ,           \
															user_name TEXT,            \
															log_type TEXT,             \
															cash INTEGER);", -1, &statement, 0) == SQLITE_OK)
		{
			sqlite3_step(statement);
			sqlite3_finalize(statement);
		}

		char *query = sqlite3_mprintf("INSERT INTO log VALUES('%q', '%q', '%q', '%q', %d)",                         \
			                                                                   this->get_time().c_str(),            \
																			   user_card.get_card_id().c_str(),     \
																			   user_card.get_user_name().c_str(),   \
																			   log_type,                            \
																			   cash );

		if (sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK)
		{
			sqlite3_step(statement);
			sqlite3_finalize(statement);
		}
				
		else
		{
			cout << "withdraw log fail\n";
		}
		sqlite3_free(query);
		sqlite3_close(database); 
	}
	
	else
	{
		cout << "can't open shell.db\n"
			 << endl;
	}

}

void ATM::do_inquiry_log(Card &user_card)  
{
	//string tmp;
	//ifstream ifs1("store_log.txt");
	//if(ifs1.is_open())
	//{
	//	while(!ifs1.eof())
	//	{
	//		getline(ifs1,tmp);
	//		/*
	//		*list the information by match the card_id!
	//		*/
	//		if(tmp.find(user_card.get_card_id())!=string::npos)
	//		{
	//			cout<<tmp<<endl;
	//		}
	//	}
	//}
	//ifs1.close();

	//ifstream ifs2("get_log.txt");
	//if(ifs2.is_open())
	//{
	//	while(!ifs2.eof())
	//	{
	//		getline(ifs2,tmp);
	//		/*
	//		*list the information by match the card_id!
	//		*/
	//		if(tmp.find(user_card.get_card_id())!=string::npos)
	//		{
	//			cout<<tmp<<endl;
	//		}
	//	}
	//}
	//ifs2.close();

	if (sqlite3_open("shell.db", &database) == SQLITE_OK)
	{
		sqlite3_stmt *statement;

		char *query = sqlite3_mprintf("SELECT date, card_id, user_name, log_type, cash    \
									  FROM log                                            \
									  WHERE card_id = '%q';", user_card.get_card_id().c_str());
		if (sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK)
		{
			int cols = sqlite3_column_count(statement);
			int result = 0;
			while (true)
			{
				result = sqlite3_step(statement);
				if (result == SQLITE_ROW)
				{
					for(int col = 0; col < cols; col++)
					{
						std::cout << sqlite3_column_text(statement, col) << " ";
					}
					std::cout << endl;
				}
				else
				{
					break;
				}
			}
		 
			sqlite3_finalize(statement);
		}
				
		else
		{
			cout << "inqury_log fail\n";
		}
		sqlite3_free(query);
		sqlite3_close(database); 
	}


	else
	{
		cout << "can't open shell.db\n"
			 << endl;
	}
}

void ATM::do_inquiry_account(Card &user_card)
{
	cout << "\t\t\t\tUserName:"
		 << user_card.get_user_name() << '\n'
		 << "\t\t\t\tCardID:"
		 << user_card.get_card_id() << '\n'
		 << "\t\t\t\tAccountBalance:"
		 << user_card.get_cash()
		 << endl;

}

string  ATM::get_time()
{
#ifdef OS_WIN
	/*
	<<month+1<<"/"<<day<<"/"<<year+1900<<"  "
		<<hour<<":"<<min<<":"<<sec<<" "<<
			" "
			*/
	string user_time;

	//time_t t;
	//time(&t);
	//struct tm *OStime;
	//OStime=localtime(&t);
	//int hour=OStime->tm_hour;
	//int min=OStime->tm_min;
	//int sec=OStime->tm_sec;
	//int month=OStime->tm_mon;
	//int day = OStime->tm_mday;
	//int year=OStime->tm_year;
	//char buf[26];
	__time64_t ltime;
    _time64( &ltime );
	//errno_t err;
	user_time=_ctime64( &ltime );
	//user_time=_ctime64(&ltime);
	//return user_time;
	return user_time.substr(0,user_time.size()-1);
#endif

#ifdef OS_GNU
	string user_time;
	time_t time_val;
	(void) time(&time_val);
	user_time = ctime(&time_val);
	return user_time.substr(0,user_time.size()-1);
#endif
}

