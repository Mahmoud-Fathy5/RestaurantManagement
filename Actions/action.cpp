#include "action.h"

ostream& operator <<(ostream& O, Action* pAction) {
	pAction->print(O);
	return O;
}
