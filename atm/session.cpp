/* 
 * ATM simulator 
 * 2010.08.02 by alex.
 */

#include "atm/session.h"

#include "atm/card.h"

Session::Session()
{
}

Session::Session(ATM *atm, Card *card)
{
	m_atm=atm;
	m_card=card;
}

ATM *Session::get_atm()
{
		return this->m_atm;
}

Card *Session::get_card()
{
	return this->m_card;
}