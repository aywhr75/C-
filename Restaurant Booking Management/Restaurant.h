#ifndef SDDS_RESARURANT_H
#define SDDS_RESARURANT_H
#include <iostream>

#include "Reservation.h"

using namespace std;

namespace sdds {
	class Restaurant {
		Reservation** reserve{};
		size_t numReserv{};

	public:
		Restaurant();
		~Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(Restaurant&);
		Restaurant(Restaurant&&);
		size_t size()const;
		friend ostream& operator << (ostream& os, const Restaurant&);
	};
}
#endif // !SDDS_RESARURANT_H
