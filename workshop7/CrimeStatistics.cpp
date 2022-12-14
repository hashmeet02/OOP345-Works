//-------------------------------------------------------------------------------------------------------- -
//REFLECTION
//Name : Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 9th, 2022
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//-------------------------------------------------------------------------------------------------------- -

#include <algorithm>
#include<iostream>
#include <iomanip>
#include <functional>
#include <numeric>
#include <cstring>
#include "CrimeStatistics.h"

namespace sdds {
	CrimeStatistics::CrimeStatistics(const char* fileName)
	{
		std::ifstream file(fileName);
		if (!file)
			throw std::string("Unable to open [") + fileName + "] file.";

		std::string record;
		while (!file.eof())
		{
			Crime tempCrime{};
			std::getline(file, record);

			tempCrime.m_province = record.substr(0, record.find(" "));
			record.erase(0, record.find(" ") + 1);
			while (record[0] == ' ') record.erase(0, 1);

			tempCrime.m_distict = record.substr(0, record.find(" "));
			record.erase(0, record.find(" ") + 1);
			while (record[0] == ' ') record.erase(0, 1);

			tempCrime.m_crime = record.substr(0, record.find(" "));
			record.erase(0, record.find(" ") + 1);
			while (record[0] == ' ') record.erase(0, 1);

			tempCrime.m_year = std::stoi(record.substr(0, record.find(" ")));
			record.erase(0, record.find(" ") + 1);
			while (record[0] == ' ') record.erase(0, 1);

			tempCrime.m_numOfCases = std::stoi(record.substr(0, record.find(" ")));
			record.erase(0, record.find(" ") + 1);
			while (record[0] == ' ') record.erase(0, 1);

			tempCrime.m_resolved = std::stoi(record.substr(0, record.find("\n")));
			record.erase(0, record.find("\n") + 1);

			m_crimes.push_back(tempCrime);
		}

		file.close();
	}

	void CrimeStatistics::sort(const char* field)
	{
		if (strcmp(field,"Province")==0) {
			std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& crime1, const Crime& crime2) {
				return crime2.m_province > crime1.m_province;
				});
		}
		else if (strcmp(field, "Crime")==0) {
			std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& crime1, const Crime& crime2) {
				return crime2.m_crime > crime1.m_crime;
				});
		}
		else if (strcmp(field, "Cases")==0) {
			std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& crime1, const Crime& crime2) {
				return crime2.m_numOfCases > crime1.m_numOfCases;
				});
		}
		else if (strcmp(field, "Resolved")==0) {
			std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& crime1, const Crime& crime2) {
				return crime2.m_resolved > crime1.m_resolved;
				});
		}
	}

	void CrimeStatistics::cleanList()
	{
		std::transform(m_crimes.begin(), m_crimes.end(), m_crimes.begin(), [](Crime& theCrime) {
			if (theCrime.m_crime == "[None]") {
				theCrime.m_crime = "";
			}
			return theCrime;
			});
	}

	std::list<Crime> CrimeStatistics::getListForProvince(const char* queryProvince) const
	{
		size_t sizeOfList = std::count_if(m_crimes.begin(), m_crimes.end(), [queryProvince](const Crime& theCrime) {
			return theCrime.m_province == queryProvince;
			});
		std::list<Crime>crimeList(sizeOfList);
		std::copy_if(m_crimes.begin(), m_crimes.end(), crimeList.begin(), [queryProvince](const Crime& theCrime) {
			return theCrime.m_province == queryProvince;
			});
		return crimeList;
	}

	bool CrimeStatistics::inCollection(const char* queryCrime) const
	{
		bool flag{};
		flag = std::any_of(m_crimes.begin(), m_crimes.end(), [queryCrime](const Crime& theCrime) {
			return(theCrime.m_crime == queryCrime);
			});
		return flag;
	}

	void CrimeStatistics::display(std::ostream& out) const {
		std::for_each(m_crimes.begin(), m_crimes.end(), [&out](const Crime& theCrime) {
			out << theCrime<<std::endl;
			});
		int totalCases = std::accumulate(m_crimes.begin(), m_crimes.end(), (int)0, [](const int& result, const Crime& theCrime) {
			return result + theCrime.m_numOfCases;
			});
		int totalResolved = std::accumulate(m_crimes.begin(), m_crimes.end(), (int)0, [](const int& result, const Crime& theCrime) {
			return result + theCrime.m_resolved;
		});
		out << "----------------------------------------------------------------------------------------" << std::endl;
		out << "| "<<std::right<<std::setw(79)<<"Total Crimes:  " << totalCases <<" |"<< std::endl;
		out << "| " << std::right << std::setw(79) << "Total Resolved Cases:  " << totalResolved << " |" << std::endl;
	}

	std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
	{
		out << "| " << std::left << std::setw(21) << std::setfill(' ') << theCrime.m_province
			<< " | " << std::left << std::setw(15) << theCrime.m_distict
			<< " | " << std::left << std::setw(20) << theCrime.m_crime
			<< " | " << std::right << std::setw(6) << theCrime.m_year
			<< " | " << std::right << std::setw(4) << theCrime.m_numOfCases
			<< " | " << std::right<< std::setw(3)<< theCrime.m_resolved << " |";

		return out;
	}
}