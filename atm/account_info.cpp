/*
 * ATM simulator 
 * 2010.08.03 by alex.
 */

#include "atm/account_info.h"

void AccountInfo::send_to_atm()
{
	(*m_session.get_atm()).do_inquiry_account((*m_session.get_card()));
}
