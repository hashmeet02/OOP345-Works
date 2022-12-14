//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 5th, 2022

//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Reservation.h"
#include <string>


namespace sdds {
	Reservation::~Reservation()
	{
		delete[] m_reservationId;
		m_reservationId = nullptr;
	}

	Reservation::Reservation(const Reservation& toCopy)
	{
		m_reservationId = nullptr;
		*this = toCopy;
	}

	Reservation& Reservation::operator=(const Reservation& toAssign)
	{
		if (this != &toAssign) {
			delete[] m_reservationId;
			m_name = toAssign.m_name;
			m_email = toAssign.m_email;
			m_numOfPeople = toAssign.m_numOfPeople;
			m_day = toAssign.m_day;
			m_time = toAssign.m_time;
			if (toAssign.m_reservationId != nullptr) {
				m_reservationId = new char[strlen(toAssign.m_reservationId) + 1];
				strcpy(m_reservationId, toAssign.m_reservationId);
			}
			else {
				m_reservationId = nullptr;
			}
		}
		return *this;
	}

	Reservation::Reservation(Reservation&& toMove) noexcept
	{
		*this = std::move(toMove);
	}

	Reservation& Reservation::operator=(Reservation&& toMove) noexcept
	{
		if (this != &toMove) {
			delete[] m_reservationId;
			m_name = toMove.m_name;
			m_email = toMove.m_email;
			m_numOfPeople = toMove.m_numOfPeople;
			m_day = toMove.m_day;
			m_time = toMove.m_time;
			if (toMove.m_reservationId != nullptr) {
				m_reservationId = toMove.m_reservationId;
				toMove.m_reservationId = nullptr;
				m_name = "";
				m_email = "";
				m_numOfPeople = 0;
				m_day = 0;
				m_time = 0;
			}
		}
		return *this;
	}

	Reservation::operator bool() const {
		return m_reservationId != nullptr;
	}

	void Reservation::update(int day, int time)
	{
		m_day = day;
		m_time = time;
	}

	Reservation::Reservation(const std::string& res)
	{
		std::string tempRes = res;
		std::string tempId = tempRes.substr(0, tempRes.find(":"));
		tempId = trim(tempId);
		m_reservationId = new char[tempId.length() + 1];
		strcpy(m_reservationId, tempId.c_str());
		tempRes.erase(0, tempRes.find(":") + 1);

		m_name = trim(tempRes.substr(0, tempRes.find(",")));
		tempRes.erase(0, tempRes.find(",") + 1);

		m_email = trim(tempRes.substr(0, tempRes.find(",")));
		tempRes.erase(0, tempRes.find(",") + 1);

		m_numOfPeople = std::stoi(tempRes.substr(0, tempRes.find(",")));
		tempRes.erase(0, tempRes.find(",") + 1);

		m_day = std::stoi(tempRes.substr(0, tempRes.find(",")));
		tempRes.erase(0, tempRes.find(",") + 1);

		m_time = std::stoi(tempRes);
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		if (res) {
			std::string meal{};
			if (res.m_time >= 6 && res.m_time <= 9)
				meal = "Breakfast ";
			else if (res.m_time >= 11 && res.m_time <= 15)
				meal = "Lunch ";
			else if (res.m_time >= 17 && res.m_time <= 21)
				meal = "Dinner ";
			else
				meal = "Drinks ";

			os.setf(std::ios::left);
			os << "Reservation ";
			os.unsetf(std::ios::left);
			os.width(10);
			os << res.m_reservationId << ": ";

			os.width(20);
			os << res.m_name << "  ";

			os.setf(std::ios::left);
			os.width(20);
			os << "<" + res.m_email + ">";;
			os << "    " << meal << "on day " << res.m_day << " @ " << res.m_time << ":00 for " << res.m_numOfPeople;
			if (res.m_numOfPeople > 1) {
				os << " people.";
			}
			else os << " person.";
			os << std::endl;
		}
		return os;
	}

	std::string ltrim(const std::string& toBeTrimmed)
	{
		size_t start = toBeTrimmed.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : toBeTrimmed.substr(start);
	}

	std::string rtrim(const std::string& toBeTrimmed)
	{
		size_t end = toBeTrimmed.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : toBeTrimmed.substr(0,end+1);
	}

	std::string trim(const std::string& toBeTrimmed) {
		return rtrim(ltrim(toBeTrimmed));
	}

	char* Reservation::getId() const {
		return m_reservationId;
	}

	bool operator==(const Reservation& lhs, const Reservation& rhs) {
		return !(strcmp(lhs.getId(), rhs.getId()));
	}

}
