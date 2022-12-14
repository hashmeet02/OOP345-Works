//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 3rd, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include "Car.h"

namespace sdds {
	Car::Car(std::istream& is)
	{
		std::string tempMaker{};
		std::string tempCondition{};
		
		std::getline(is, tempMaker, ',');
		std::getline(is, tempCondition);
		while (tempCondition[0] == ' ') tempCondition.erase(0, 1);
		if (tempCondition[0] == ',') m_condition = "new";
		else {
			switch (tempCondition[0])
			{
			case 'n':
				m_condition = "new";
				break;
			case 'u':
				m_condition = "used";
				break;
			case 'b':
				m_condition = "broken";
				break;
			default:
				throw "Invalid record!";
				break;
			}
		}
		tempCondition.erase(0, tempCondition.find(",") + 1);
		m_maker = trim(tempMaker);
		tempCondition = trim(tempCondition);
		try {
			m_topSpeed = std::stoi(trim(tempCondition));
		}
		catch(...) {
			throw "Invalid record!";
		}
	}
	std::string Car::condition() const
	{
		return m_condition;
	}
	double Car::topSpeed() const
	{
		return m_topSpeed;
	}
	void Car::display(std::ostream& out) const
	{
		out << "| ";
		out.width(10);
		out << m_maker << " | ";

		out.setf(std::ios::left);
		out.width(6);
		out << condition() << " | ";
		out.unsetf(std::ios::left);

		out.width(6);
		out.setf(std::ios::fixed);
		out.precision(2);
		out << topSpeed() << " |";

	}

	void Car::changeTopSpeed(double newTopSpeed) {
		m_topSpeed = newTopSpeed;
	}

	std::string Car::ltrim(const std::string& s)
	{
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}
	std::string Car::rtrim(const std::string& s)
	{
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}
	std::string Car::trim(const std::string& s)
	{
		return rtrim(ltrim(s));
	}
}

