//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 13th, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

namespace sdds {
	const std::string& Book::author() const
	{
		return m_author;
	}
	const std::string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}
	const std::string& Book::description() const
	{
		return m_description;
	}
	Book::Book(const std::string& strBook)
	{
		std::string tempBook = strBook;
		m_author = trim(tempBook.substr(0, tempBook.find(",")));
		tempBook.erase(0, tempBook.find(",") + 1);

		m_title = trim(tempBook.substr(0, tempBook.find(",")));
		tempBook.erase(0, tempBook.find(",") + 1);

		m_country = trim(tempBook.substr(0, tempBook.find(",")));
		tempBook.erase(0, tempBook.find(",") + 1);

		m_price = std::stod(tempBook.substr(0, tempBook.find(",")));
		tempBook.erase(0, tempBook.find(",") + 1);

		m_year = std::stoi(tempBook.substr(0, tempBook.find(",")));
		tempBook.erase(0, tempBook.find(",") + 1);

		m_description = trim(tempBook.substr(0, tempBook.find(".")));
		tempBook.erase(0, tempBook.find(",") + 1);
	}
	std::string Book::ltrim(const std::string& s)
	{
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}
	std::string Book::rtrim(const std::string& s)
	{
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}
	std::string Book::trim(const std::string& s)
	{
		return rtrim(ltrim(s));
	}
	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os.width(20);
		os << book.author()<<" | ";

		os.width(22);
		os << book.title()<<" | ";

		os.width(5);
		os << book.country() << " | ";

		os.width(4);
		os << book.year() << " | ";

		os.width(6);
		os.setf(std::ios::fixed);
		os.precision(2);
		os << book.m_price << " | ";

		os.setf(std::ios::left);
		os << book.description() << "." << std::endl;
		os.unsetf(std::ios::left);

		return os;
	}
}