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
#include "Luxuryvan.h"

namespace sdds {
	Luxuryvan::Luxuryvan(std::istream& in) try: Van(streamCopy(in)) 
	{
		size_t index = m_streamCopy->str().rfind(",");
		std::string tempConsumption = m_streamCopy->str().substr(index + 1);
		while (tempConsumption[0] == ' ') tempConsumption.erase(0, 1);
		switch (tempConsumption[0])
		{
		case 'g':
			throw "Invalid record!";
			break;
		case 'e':
			m_consumption = "electric";
			break;
		default:
			throw "Invalid record!";
			break;
		}
	}
	catch (...) {
		delete m_streamCopy;
	}

	void Luxuryvan::display(std::ostream& out) const
	{
		Van::display(out);
		if (consumption() == "electric") {
			out << " electric van  *";
		}
	}

	std::string Luxuryvan::consumption() const
	{
		return m_consumption;
	}

	std::istream& Luxuryvan::streamCopy(std::istream& is)
	{
		std::string temp{};
		std::getline(is, temp);
		m_streamCopy = new std::stringstream(temp);

		return *m_streamCopy;
	}
}