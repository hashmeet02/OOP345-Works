//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 3rd, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <string>
#include <iostream>
#include <sstream>
#include "Car.h"

namespace sdds {
	class Racecar : public Car {
		double m_booster{};
		std::stringstream* m_streamCopy;

	public:
		Racecar(std::istream& is);

		double topSpeed() const;
		void display(std::ostream& out) const;

		~Racecar() {
			delete m_streamCopy;
		};
		std::istream& streamCopy(std::istream& is);
	};
}
#endif // !SDDS_RACECAR_H
