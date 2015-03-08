/* 
 * ATM simulator 
 * 2010.07.29 by alex.
 */

#ifndef ATM_CARD_H_
#define ATM_CARD_H_

#include <string>
#include <vector>

using namespace std;

class Card{
public:
	Card();
	Card(string name,string pass,string id,long cash);
	void read(ifstream & s);
	string get_password() const;
	string get_card_id() const;
	string get_user_name() const;
	long get_cash() const;
	void change_cash(long cash);
	void change_user_name(string user_name);
private:
	string user_name;
	string password;
	string card_id;
	long cash;
};

#endif /* ATM_CARD_H_ */