// Name: YoungA Lee
// Seneca Student ID: 048417083
// Seneca email: yalee2@seneca.ca
// Date of completion: Fab 17 2020
//
// I confirm that the content of this file is created by me,
//  with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>

#include "SpellChecker.h"

using namespace std;

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		auto pos = 0u; // unsigned int
		string len;
		ifstream textfile(filename); // ready to read a file

		if (!textfile.good()) 
			throw "Bad file name!"; // exceptional check 
		else {
			for (size_t i = 0; i < WORD_SIZE; i++) {
				getline(textfile, len);
				pos = len.find(' '); // find location number of white space

				m_badWords[i] = len.substr(0, pos); 
				m_badWords[i].erase(remove(m_badWords[i].begin(), m_badWords[i].end(), ' '), m_badWords[i].end());// removed white space

				m_goodWords[i] = len.substr(pos, len.length() - 1); 
				m_goodWords[i].erase(remove(m_goodWords[i].begin(), m_goodWords[i].end(), ' '), m_goodWords[i].end()); // remove white space
			}
		}
	}
	void SpellChecker::operator()(std::string& text) const {
		auto pos = 0u;

		for (size_t i = 0; i < WORD_SIZE; i++) {
			while (text.find(m_badWords[i]) != string::npos){ // if text.find is same with m_badWords return npos otherwise keep checking
				pos = text.find(m_badWords[i]);
				text.replace(pos, m_badWords[i].length(), m_goodWords[i]); // replace badwords to goodwords
			}
		}
	}
}