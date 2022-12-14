//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 5th, 2022

//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>
#include <cstring>
#include <iostream>

namespace sdds {
	class Reservation {
		char* m_reservationId{};
		std::string m_name{};
		std::string m_email{};
		unsigned int m_numOfPeople{};
		int m_day{};
		int m_time{};
	public:
		Reservation() {};
		Reservation(const std::string& res);
		~Reservation();
		Reservation(const Reservation& toCopy);
		Reservation& operator=(const Reservation& toAssign);
		Reservation(Reservation&& toMove) noexcept;
		Reservation& operator=(Reservation&& toMove) noexcept;

		char* getId() const;
		operator bool() const;
		void update(int day, int time);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
	std::string ltrim(const std::string& s);
	std::string rtrim(const std::string& s);
	std::string trim(const std::string& s);
	bool operator==(const Reservation& lhs, const Reservation& rhs);
	
}
#endif // !SDDS_RESERVATION_H

