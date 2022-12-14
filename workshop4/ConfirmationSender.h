//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 5th, 2022

//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const Reservation** m_csReservations{};
		size_t m_numOfReservations{};
	public:

		ConfirmationSender() {};

		ConfirmationSender(const ConfirmationSender& toCopy);
		ConfirmationSender& operator=(const ConfirmationSender& toAssign);
		ConfirmationSender(ConfirmationSender&& toMove)noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& toMove)noexcept;
		~ConfirmationSender();

		size_t size() const;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, ConfirmationSender& cs);
	};
}
#endif // !SDDS_CONFIRMATIONSENDER_H

