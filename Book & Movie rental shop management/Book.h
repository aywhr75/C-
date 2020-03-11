#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>

using namespace std;
namespace sdds {
	class Book {
		string _author{};
		string _title{};
		string _country{};
		size_t _year{};
		double _price{};
		string _descrip{};

	public:
		Book() { _year = 0; _price = 0.0; };
		const string& author() const;
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		Book(const string& strBook);
		friend ostream& operator << (ostream& os, const Book&);
		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(_descrip);
		}
	};
}
#endif // !SDDS_BOOK_H

#pragma once
