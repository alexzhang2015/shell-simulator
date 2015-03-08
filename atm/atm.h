/*
 * ATM simulator 
 * 2010.07.29 by alex.
 */

#ifndef ATM_ATM_H_
#define ATM_ATM_H_
#pragma once

#include <string>
#include <vector>
#include "atm/card.h"
#include "third_party/sqlite/sqlite3.h"

#define CARD_ACCOUNT 100

using namespace std;

class ATM{
public:
	/**
	 * ATM constructor.
	 */
	ATM();

	/**
	 * ATM destructor.
	 */
	~ATM();

	void print_operator();
	string input_password();
	string input_name();
	int menu_choice();
	void on_off();

	/**
	 * Initialize the account to the memory.
	 */
	void read_account();

	/**
	 * Verify the account.
	 */
	bool check_account(Card &user_card);

	/**
	 * Deposit memory interface.
	 */
	void initiate_deposit(Card &user_card);

	/**
	 * Withdeaw memory interface.
	 */
	void do_withdraw(Card &user_card);

	/**
	 * Inquiry transaction log.
	 */
	void do_inquiry_log(Card &user_card);

	/**
	 * Inquiry User account information.
	 */
	void do_inquiry_account(Card &user_card);

private:
	void sync_user_info();
	string get_time();
	void withdraw_log(Card &user_card,long cash);
	void finish_deposit(Card &user_card,long cash);

	vector<Card> card;
	long card_number;

	/* A sqlite3 database object. */
	sqlite3 *database;

};

#endif /* ATM_ATM_H_ */