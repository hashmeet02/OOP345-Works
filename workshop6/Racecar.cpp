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
#include "Racecar.h"


namespace sdds {
	Racecar::Racecar(std::istream& is) try : Car(streamCopy(is))
	{
		size_t index = m_streamCopy->str().rfind(",");
		m_booster = std::stod(m_streamCopy->str().substr(index + 1));
	}
	catch (...) {
		delete m_streamCopy;
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() + (m_booster * Car::topSpeed());
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	std::istream& Racecar::streamCopy(std::istream& is)
	{
		std::string temp{};
		std::getline(is, temp);
		m_streamCopy = new std::stringstream(temp);
		return *m_streamCopy;
	}
}
