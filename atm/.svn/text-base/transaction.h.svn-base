/* 
 * ATM simulator 
 * 2010.08.02 by alex.
 */

#ifndef ATM_TRANSACTION_H_
#define ATM_TRANSACTION_H_

#include "atm/session.h"

class Transaction{
public:
	Transaction(Session& session);
	virtual ~Transaction()
	{
	}
	virtual void send_to_atm()
	{
	}
private:
	Session m_session;
};

#endif /* ATM_TRANSACTION_H_ */