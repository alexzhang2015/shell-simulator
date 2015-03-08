/* 
 * ATM simulator 
 * 2010.08.02 by alex.
 */

#include "atm/transaction.h"
Transaction::Transaction(Session& session)
{
	m_session=session;
}

