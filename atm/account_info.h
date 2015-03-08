/*
 * ATM simulator 
 * 2010.08.03 by alex.
 */

#ifndef ATM_ACCOUNT_INFO_H_
#define ATM_ACCOUNT_INFO_H_
#pragma once

#include "transaction.h"
#include "session.h"

class AccountInfo:public Transaction{
public:
	AccountInfo(Session& session):Transaction(session)
	{
		m_session=session;
	}
	void send_to_atm();
private:
	Session m_session;
};

#endif /* ATM_ACCOUNT_INFO_H_ */