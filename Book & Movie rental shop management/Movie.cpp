// Name: YoungA Lee
// Seneca Student ID: 048417083
// Seneca email: yalee2@seneca.ca
// Date of completion: Fab 17 2020
//
// I confirm that the content of this file is created by me,
//  with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<iomanip>

#include "Movie.h"

using namespace std;

namespace sdds {
	const string& Movie::title() const {
		return _title;
	}
	const size_t& Movie::year() const {
		return _year;
	}
	const string& Movie::description() const {
		return _description;
	}
	Movie::Movie(const std::string& strMovie) {
		string len;
		auto first = 0u;
		auto last = 0u;

		stringstream scan(strMovie); // scanning string stream from file

		getline(scan, len, ',');
		first = len.find_first_not_of(' ');
		last = len.find_last_not_of(' ');
		_title = len.substr(first, last - first+1); // scanning without white space before string and end

		getline(scan, len, ',');
		_year = stoi(len);  // change type string to int

		getline(scan, len);
		first = len.find_first_not_of(' ');
		_description = len.substr(first);
	}
	ostream& operator << (ostream& os, const Movie& movie) {
		os << setw(40) << right << movie._title << " | ";
		os << setw(4) << movie._year << " | ";
		os << movie._description << endl;

		return os;
	}
}
