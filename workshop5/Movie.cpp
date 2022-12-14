//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 13th, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"

namespace sdds {
	const std::string& Movie::title() const
	{
		return m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{
		std::string tempMovie = strMovie;
		m_title = trim(tempMovie.substr(0, tempMovie.find(",")));
		tempMovie.erase(0, tempMovie.find(",") + 1);

		m_year = std::stoi(tempMovie.substr(0, tempMovie.find(",")));
		tempMovie.erase(0, tempMovie.find(",") + 1);

		m_description = trim(tempMovie.substr(0, tempMovie.find("\n")));
		tempMovie.erase(0, tempMovie.find("\n") + 1);

	}

	std::string Movie::ltrim(const std::string& s)
	{
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}
	std::string Movie::rtrim(const std::string& s)
	{
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}
	std::string Movie::trim(const std::string& s)
	{
		return rtrim(ltrim(s));
	}
	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		os.width(40);
		os << movie.m_title << " | ";
		
		os.width(4);
		os << movie.m_year << " | ";
		
		os.setf(std::ios::left);
		os << movie.m_description << std::endl;
		os.unsetf(std::ios::left);
		return os;
	}
}