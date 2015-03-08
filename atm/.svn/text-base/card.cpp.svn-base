/* 
 * ATM simulator 
 * 2010.07.29 by alex.
 */

#include "atm/card.h"

#include <fstream>

Card::Card()
{
}

Card::Card(string name,string pass,string id,long cash)
{
	/*construction the card*/
	user_name=name;
	password=pass;
	card_id=id;
	cash=cash;
}

void Card::read(std::ifstream &s)
{
	s>>user_name;
	s>>password;
	s>>card_id;
	s>>cash;
}

string Card::get_password()  const
{
	return password;
}

string Card::get_card_id() const
{
	return card_id;
}

string Card::get_user_name() const
{
	return user_name;
}

long Card::get_cash() const
{
	return cash;
}

void Card::change_cash(long cash)
{
	this->cash=cash;
}

void Card::change_user_name(string user_name)
{
	this->user_name=user_name;
}
