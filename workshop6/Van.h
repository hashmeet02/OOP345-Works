//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 3rd, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SDDS_VAN_H
#define SDDS_VAN_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Vehicle.h"

namespace sdds {
	class Van : public Vehicle {
		std::string m_maker{};
		std::string m_type{};
		std::string m_condition{};
		std::string m_purpose{};
		double m_topSpeed{};
	public:
		Van() {};
		Van(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		std::string type() const;
		std::string usage() const;

		~Van() {};

		void display(std::ostream& out) const;

		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
	};
}
#endif // !SDDS_VAN_H
