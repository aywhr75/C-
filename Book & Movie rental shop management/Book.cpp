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

#include "Book.h"

using namespace std;

namespace sdds {
	const string& Book::author() const {
		return _author;
	}
	const string& Book::title() const {
		return _title;
	}
	const string& Book::country() const {
		return _country;
	}
	const size_t& Book::year() const {
		return _year;
	}
	double& Book::price() {
		return _price;
	}
	Book::Book(const string& strBook) {
		string len;
		auto first = 0u;
		auto last = 0u;

		stringstream scan(strBook); // scanning whole line of string

		getline(scan, len, ',');
		first = len.find_first_not_of(' ');
		last = len.find_last_not_of(' ');
		_author = len.substr(first, last - first + 1); // scanning without white space before string and end

		getline(scan, len, ',');
		first = len.find_first_not_of(' ');
		last = len.find_last_not_of(' ');
		_title = len.substr(first, last - first + 1); // scanning without white space before string and end

		getline(scan, _country, ',');
		_country.erase(remove(_country.begin(), _country.end(), ' '), _country.end());

		getline(scan, len, ',');
		_price = stod(len);  // change type string to double

		getline(scan, len, ',');
		_year = stoi(len);  // change type string to int

		getline(scan, len);
		first = len.find_first_not_of(' ');
		last = len.find_last_not_of(' ');
		_descrip = len.substr(first, last - first + 1); // scanning without white space before string and end
	}
	ostream & operator << (ostream & os, const Book & book) {
		os << setw(20) << right << book._author << " | ";
		os << setw(22) << right << book._title << " | ";
		os << setw(5) << book._country << " | ";
		os << setw(4) << book._year << " | ";
		os << setw(6) << fixed << setprecision(2) << book._price << " | ";
		os << book._descrip << endl;
		return os;
	}
}