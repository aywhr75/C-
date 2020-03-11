#ifndef SDDS_RESERVE_H
#define SDDS_RESERVE_H

#include<iostream>

using namespace std;

namespace sdds {
	class Reservation {
		char reservId[8]{};
		string name{}; 
		string email{};
		size_t peopel{};
		int day{};
		int hour{};

	public:
		Reservation() {};
		Reservation(const string& res);
		friend ostream& operator<<(ostream& os, const Reservation& reserv);
	};
}
#endif // !


