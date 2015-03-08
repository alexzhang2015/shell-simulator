/*
 * ATM simulator 
 * 2010.08.02 by alex.
 */

#ifndef ATM_DEPOSIT_TRANSACTION_H_
#define ATM_DEPOSIT_TRANSACTION_H_

#include "atm/transaction.h"
#include "atm/session.h"

class DepositTransaction:public Transaction{
public:
	DepositTransaction(Session& session):Transaction(session)
	{
		m_session=session;
	}
	void send_to_atm();
private:
	Session m_session;
};

#endif /* ATM_DEPOSIT_TRANSACTION_H_ */