/*
 * ATM simulator 
 * 2010.08.03 by alex.
 */

#include "atm/inquiry_transaction.h"

void InquiryTransaction::send_to_atm()
{
	(*m_session.get_atm()).do_inquiry_log((*m_session.get_card()));
}
