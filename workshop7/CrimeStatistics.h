//-------------------------------------------------------------------------------------------------------- -
//REFLECTION
//Name : Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 9th, 2022
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//-------------------------------------------------------------------------------------------------------- -

#ifndef SDDS_CRIMSTATISTICS_H
#define SDDS_CRIMSTATISTICS_H

#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include<list>

namespace sdds {
	struct Crime {
		std::string m_province{};
		std::string m_distict{};
		std::string m_crime{};
		unsigned int m_numOfCases{};
		unsigned int m_year{};
		unsigned int m_resolved{};
	};

	class CrimeStatistics {
		std::vector<Crime>m_crimes{};
	public:
		CrimeStatistics(const char* fileName);
		void display(std::ostream& out) const;
		void sort(const char* field);
		void cleanList();
		bool inCollection(const char* queryCrime) const;
		std::list<Crime> getListForProvince(const char* queryProvince) const;
	};
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}

#endif // !SDDS_CRIMSTATISTICS_H
