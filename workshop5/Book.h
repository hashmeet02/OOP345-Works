//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 13th, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
#include <iostream>
#include "SpellChecker.h"

namespace sdds {
	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_description{};
	public:
		Book() {};
		const std::string& author() const;
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		const std::string& description() const;

		
		Book(const std::string& strBook);
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
		}


		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};

}
#endif // !SDDS_BOOK_H
