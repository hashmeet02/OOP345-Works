//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : Septemeber 29th, 2022

//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Dictionary.h"

namespace sdds {
	sdds::Dictionary::Dictionary() {}

	std::ostream& Dictionary::display(std::ostream& os) const
	{
		os.width(20);
		os << m_term << ": ";
		os.setf(std::ios::left);
		os << m_definition;
		os.unsetf(std::ios::left);
		return(os);
	}


	std::ostream& operator<<(std::ostream& os, const Dictionary& dictionary)
	{
		dictionary.display(os);
		return os;
	}
	bool operator==(const Dictionary& lo, const Dictionary& ro) {
		return (lo.getTerm() == ro.getTerm());
	}

}

