// Name: YoungA Lee
// Seneca Student ID: 048417083
// Seneca email: yalee2@seneca.ca
// Date of completion: Fab 06 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<iomanip>

#include "Reservation.h"

using namespace std;

namespace sdds {
	Reservation::Reservation(const string& res) {
		string str = res;
		size_t pos{}, lastpos{ size_t(-1) };
		string tempstr[6]{ {} };
		size_t count{};

		pos = str.find(' ');
		while (pos != (size_t)(-1)) {
			str.erase(pos, 1);
			pos = str.find(' ');
		}
		for (size_t i = 0; i < str.length(); i++) {
			if (str[i] == ',' || str[i] == ':') {
				pos = str.find(str[i]);
				tempstr[count++] = str.substr(lastpos + 1, pos - lastpos - 1);
				lastpos = pos;
				str[i] = '*';
			}
		}
		tempstr[count] = str.substr(pos + 1);

		strcpy(reservId, tempstr[0].c_str());
		name = tempstr[1];
		email = tempstr[2];
		peopel = stoi(tempstr[3]);
		day = stoi(tempstr[4]);
		hour = stoi(tempstr[5]);
	}
	ostream& operator << (ostream& os, const Reservation& reserv) {
		string _email = " <" + reserv.email + '>';
		os << "Reservation " << reserv.reservId << ": "
		   << setw(10) << right << reserv.name << ' '
		   << left << setw(20) << _email << right << "     ";
		if(reserv.hour >= 6 && reserv.hour <= 9)
			os << "Breakfast";
		else if (reserv.hour >= 11 && reserv.hour <= 15)
			os << "Lunch";
		else if (reserv.hour >= 17 && reserv.hour <= 21)
			os << "Dinner";
		else
			os << "Drinks";
		os << " on day " << reserv.day << " @ " << reserv.hour 
		   << ":00 for " << reserv.peopel << " people." << endl;

		return os;
	}


}