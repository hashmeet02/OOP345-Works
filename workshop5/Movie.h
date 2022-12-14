//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 13th, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include <iostream>
#include "SpellChecker.h"

namespace sdds {
	class Movie{
		std::string m_title{};
		int m_year{};
		std::string m_description{};
	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}

		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);

		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}
#endif // !SSDS_MOVIE_H
