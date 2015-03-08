/* 
 * ATM simulator 
 * 2010.08.02 by alex.
 */

#ifndef ATM_SESSION_H_
#define ATM_SESSION_H_

#include "atm/card.h"
#include "atm/atm.h"

/**
*Perform a session use case
*/
class Session{
public:
	Session();
	/**
	*point just so strong ,director control the session!
	*/
	Session(ATM * atm,Card * card);
	ATM  *get_atm();
	Card  *get_card();
	
private:
	ATM *m_atm;
	Card *m_card;
};

#endif /* ATM_SESSION_H_ */