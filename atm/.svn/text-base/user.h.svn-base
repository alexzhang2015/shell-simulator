/* 
 * ATM simulator 
 * 2010.07.29 by alex.
 */

#ifndef ATM_USER_H_
#define ATM_USER_H_

#include <string>
#include <vector>
#include "atm/card.h"
#include "atm/transaction.h"
#include "atm/session.h"

using namespace std;
class User{
public:
	User ();
	User (Card &card,Session &session);
	void withdraw_money();
	void account_info();
	void read_log();
	void deposit_money();
	void choice(int choice_menu);
private:
	Card user_card;
	Transaction *transaction;
	Session session;
};

#endif /* ATM_USER_H_ */