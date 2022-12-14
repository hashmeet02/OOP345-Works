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
		os<<m_definition;
		os.unsetf(std::ios::left);
		return(os);
	}


	std::ostream& operator<<(std::ostream& os, const Dictionary& dictionary)
	{
		dictionary.display(os);
		return os;
	}

}

