/*
 * ATM simulator 
 * 2010.08.02 by alex.
 */

#include "atm/deposit_transaction.h"

void DepositTransaction::send_to_atm()
{
	(*m_session.get_atm()).initiate_deposit((*m_session.get_card()));
}
