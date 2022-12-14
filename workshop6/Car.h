//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 3rd, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Vehicle.h"

namespace sdds {
	class Car: public Vehicle {
		std::string m_maker{};
		std::string m_condition{};
		double m_topSpeed{};
	public:
		Car() {};
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		void changeTopSpeed(double newTopSpeed);

		~Car() {};

		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
	};
}
#endif // !SDDS_CAR_H
