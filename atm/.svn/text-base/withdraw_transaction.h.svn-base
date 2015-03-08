/* 
 * ATM simulator 
 * 2010.08.03 by alex.
 */

#ifndef ATM_WITHDRAW_TRANSACTION_H_
#define ATM_WITHDRAW_TRANSACTION_H_

#include "atm/transaction.h"
#include "atm/session.h"

class WithdrawTransaction:public Transaction{
public:
	WithdrawTransaction(Session& session):Transaction(session)
	{
		m_session=session;
	}
	void send_to_atm();
private:
	Session m_session;
};

#endif /* ATM_WITHDRAW_TRANSACTION_H_ */