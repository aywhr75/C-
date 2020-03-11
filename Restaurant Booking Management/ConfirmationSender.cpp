#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {
	ConfirmationSender::ConfirmationSender() {}
	ConfirmationSender::~ConfirmationSender() {
		if (reserve != nullptr)
			delete[] reserve;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender& rest) {
		reserve = new const Reservation * [rest.numReserv];
		for (size_t i = 0; i < rest.numReserv; i++) {
			reserve[i] = rest.reserve[i];
		}
		numReserv = rest.numReserv;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& rest) {
		reserve = rest.reserve;
		numReserv = rest.numReserv;
		rest.reserve = nullptr;
		rest.numReserv = 0;
	}
	ConfirmationSender& ConfirmationSender::operator += (const Reservation& res) {
		int resArray{-1};
		for (size_t i = 0; i < numReserv; i++) {
			if (reserve[i] == &res) {
				resArray = i;
				break;
			}
		}
			if (resArray == -1) {
				numReserv++;
				const Reservation** volum = new const Reservation * [numReserv];
				for (int i = 0; i < (int)numReserv-1; i++) {
					volum[i] = reserve[i];
				}
				volum[numReserv - 1] = &res;
				reserve = volum;
			}
			return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		int resArray{-1};
		for (int i = 0; i < (int)numReserv; i++) {
			if (reserve[i] == &res) {
				resArray = i;
				break;
			}
		}
		if (resArray != -1) {
			numReserv--;
			if (numReserv > 0) {
				const Reservation** volum = new const Reservation * [numReserv];
				for (int i = 0; i < (int)numReserv; i++) {
					if (i != resArray)
						volum[i] = reserve[i];
					else
						volum[i] = reserve[i + 1];
				}
				reserve = volum;
			}			
		}
		return *this;
	}
	ostream& operator << (ostream& os, const ConfirmationSender& res) {
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";
		if (res.numReserv == 0)
			os << "The object is empty!\n";
		else {
			for (size_t i = 0; i < res.numReserv; i++) {
				os << *res.reserve[i];
			}
		}
		os << "--------------------------\n";
		return os;
	}
}