#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>

#include<iostream>

using namespace std;

namespace sdds {
	class Movie {
		string _title{};
		size_t _year;
		string _description{};

	public:
		Movie() { _year = 0; }
		const string& title() const;
		const size_t& year() const;
		const string& description() const;
		Movie(const string& strMovie);
		friend ostream& operator << (ostream& os, const Movie& movie);
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(_title);
			spellChecker(_description);
		}
	};
}
#endif
