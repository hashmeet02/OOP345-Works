//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 5th, 2022

//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SSDS_RESTAURANT_H
#define SSDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class Restaurant {
		Reservation** m_reservations{};
		size_t m_numOfReservations{};
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);

		Restaurant(const Restaurant& toCopy);
		Restaurant& operator=(const Restaurant& toAssign);
		Restaurant(Restaurant&& toMove) noexcept;
		Restaurant& operator=(Restaurant&& toMove) noexcept;
		~Restaurant();

		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}
#endif // !SSDS_RESTAURANT_H

