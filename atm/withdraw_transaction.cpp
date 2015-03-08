/* 
 * ATM simulator 
 * 2010.08.03 by alex.
 */

#include "atm/withdraw_transaction.h"

void WithdrawTransaction::send_to_atm()
{
	(*m_session.get_atm()).do_withdraw((*m_session.get_card()));
}
