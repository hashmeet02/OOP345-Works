//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 3rd, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Van.h"

namespace sdds {
	class Luxuryvan : public Van {
		std::string m_consumption;
		std::stringstream* m_streamCopy;
	public:
		Luxuryvan(std::istream& in);
		void display(std::ostream& out) const;
		std::string consumption() const;
		~Luxuryvan() {
			delete m_streamCopy;
		};
		std::istream& streamCopy(std::istream& is);
	};
}
#endif // !SDDS_LUXURYVAN_H
