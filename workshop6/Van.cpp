//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 3rd, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "Van.h"

namespace sdds {
	Van::Van(std::istream& is)
	{
		std::string tempMaker{};
		std::string tempType{};
		std::string tempPurpose{};
		std::string tempCondition{};
		std::string tempTopSpeed{};

		std::getline(is, tempMaker, ',');
		std::getline(is, tempType, ',');
		std::getline(is, tempPurpose, ',');
		std::getline(is, tempCondition, ',');
		m_maker = trim(tempMaker);

		tempType = trim(tempType);
		switch (tempType[0])
		{
		case 'p':
			m_type = "pickup";
			break;
		case 'm':
			m_type = "mini-bus";
			break;
		case 'c':
			m_type = "camper";
			break;
		default:
			throw "Invalid record!";
			break;
		}

		tempPurpose = trim(tempPurpose);
		switch (tempPurpose[0])
		{
		case 'd':
			m_purpose = "delivery";
			break;
		case 'p':
			m_purpose = "passenger";
			break;
		case 'c':
			m_purpose = "camping";
			break;
		default:
			throw "Invalid record!";
			break;
		}

		tempCondition = trim(tempCondition);
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
		case ',':
			m_condition = "new";
			break;
		default:
			throw "Invalid record!";
			break;
		}
		std::getline(is, tempTopSpeed);
		m_topSpeed = std::stoi(trim(tempTopSpeed));
	}

	std::string Van::condition() const
	{
		return m_condition;
	}
	double Van::topSpeed() const
	{
		return m_topSpeed;
	}

	std::string Van::type() const
	{
		return m_type;
	}

	std::string Van::usage() const
	{
		return m_purpose;
	}

	void Van::display(std::ostream& out) const
	{
		out << "| ";
		out.width(8);
		out << m_maker << " | ";

		out.setf(std::ios::left);
		out.width(12);
		out << type() << " | ";

		out.width(12);
		out << usage() << " | ";

		out.width(6);
		out << condition() << " | ";

		out.unsetf(std::ios::left);

		out.width(6);
		out.setf(std::ios::fixed);
		out.precision(2);
		out << m_topSpeed << " |";

	}
	std::string Van::ltrim(const std::string& s)
	{
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}
	std::string Van::rtrim(const std::string& s)
	{
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}
	std::string Van::trim(const std::string& s)
	{
		return rtrim(ltrim(s));
	}
}


