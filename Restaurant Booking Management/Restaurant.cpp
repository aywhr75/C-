// Name: YoungA Lee
// Seneca Student ID: 048417083
// Seneca email: yalee2@seneca.ca
// Date of completion: Fab 08 2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Restaurant.h"

using namespace std;

namespace sdds {
	Restaurant::Restaurant(){}
	Restaurant::~Restaurant() {
		if (reserve != nullptr)
			delete[] reserve;
	}
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		reserve = new Reservation * [cnt];
		for (int i = 0; i < (int)cnt; i++) {
			reserve[i] = reservations[i];
		}
		numReserv = cnt;
	}
	Restaurant::Restaurant(Restaurant& rest) {
		reserve = new Reservation * [rest.numReserv];
		for (int i = 0; i < (int)rest.numReserv; i++) {
			reserve[i] = rest.reserve[i];
		}
		numReserv = rest.numReserv;
	}
	Restaurant::Restaurant(Restaurant&& rest){
		reserve = rest.reserve;
		numReserv = rest.numReserv;
		rest.reserve = nullptr;
		rest.numReserv = 0;
	}
	size_t Restaurant::size()const {
		return numReserv;
	}
	ostream& operator << (ostream& os, const Restaurant& res) {
		os << "--------------------------\n";
		os << "Fancy Restaurant\n";
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