/* 
 * ATM simulator 
 * 2010.07.29 by alex.
 */

#include "atm/user.h"

#include <fstream>
#include <iostream>
#include <string>

#include "atm/card.h"
#include "atm/transaction.h"
#include "atm/deposit_transaction.h"
#include "atm/withdraw_transaction.h"
#include "atm/inquiry_transaction.h"
#include "atm/account_info.h"

#define ACCOUNT 100

User::User()
{
}

User::User(Card &card,Session &session)
{
	user_card=card;
	this->session=session;
	transaction=NULL;
}

void User::choice(int choice_menu)
{
	switch(choice_menu)
	{
	case 1:
		deposit_money();
		break;
	case 2:
		withdraw_money();
		break;
	case 3:
		account_info();
		break;
	case 4:
		read_log();
		break;
	case 5:

		break;
	default:
		cin.clear();
		cin.sync();
		cout<<"\t\t\t\twrong choice!\n"; 
	}
}

void User::deposit_money()
{
	DepositTransaction deposit_tran(this->session);
	transaction=&deposit_tran;
	transaction->send_to_atm();
}

void User::withdraw_money()
{
	WithdrawTransaction withdraw_tran(this->session);
	transaction=&withdraw_tran;
	transaction->send_to_atm();
}

void User::account_info()
{
	AccountInfo account_info_tran(this->session);
	transaction=&account_info_tran;
	transaction->send_to_atm();
}

void User::read_log()
{
	InquiryTransaction deposit_tran(this->session);
	transaction=&deposit_tran;
	transaction->send_to_atm();

}
