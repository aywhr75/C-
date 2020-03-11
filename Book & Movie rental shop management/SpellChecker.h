#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include<iostream>

using namespace std;

namespace sdds {
	#define WORD_SIZE 5

	class SpellChecker {
		string m_badWords[WORD_SIZE];
		string m_goodWords[WORD_SIZE];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}
#endif // SDDS_SPELLCHECKER_H

