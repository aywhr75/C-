#ifndef SDDS_CONFIRM_H
#define SDDS_CONFIRM_H
#include <iostream>

#include "Reservation.h"
using namespace std;

namespace sdds {
	class ConfirmationSender {
	    const Reservation** reserve{};
		size_t numReserv{};

	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender(ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator += (const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend ostream& operator << (ostream& os, const ConfirmationSender&);
	};
}
#endif
