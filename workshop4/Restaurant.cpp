//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 5th, 2022

//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "Restaurant.h"

namespace sdds {
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		m_numOfReservations = cnt;
		m_reservations = new Reservation*[cnt];
		for (size_t i = 0; i < cnt; i++) {
			m_reservations[i] = new Reservation(*reservations[i]);
		}
	}

	Restaurant::Restaurant(const Restaurant& toCopy)
	{
		m_reservations = nullptr;
		*this = toCopy;
	}
	Restaurant& Restaurant::operator=(const Restaurant& toAssign)
	{
		if (this != &toAssign) {
			for (size_t i = 0; i < size(); i++) {
				delete m_reservations[i];
			}
			delete[] m_reservations;
			m_numOfReservations = toAssign.size();
			if (toAssign.m_reservations != nullptr) {
				m_reservations = new Reservation * [m_numOfReservations];
				for (size_t i = 0; i < m_numOfReservations; i++) {
					m_reservations[i] = new Reservation;
					*m_reservations[i] = *toAssign.m_reservations[i];
				}
			}
			else {
				m_reservations = nullptr;
			}
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& toMove) noexcept
	{
		*this = std::move(toMove);
	}
	Restaurant& Restaurant::operator=(Restaurant&& toMove) noexcept
	{
		if (this != &toMove) {
			for (size_t i = 0; i < size(); i++) {
				delete m_reservations[i];
			}
			delete[] m_reservations;
			m_numOfReservations = toMove.size();
			toMove.m_numOfReservations = 0;
			if (toMove.m_reservations != nullptr) {
				m_reservations = toMove.m_reservations;
				toMove.m_reservations = nullptr;
			}
		}
		return *this;
	}
	Restaurant::~Restaurant()
	{
		for (size_t i = 0; i < size(); i++) {
			delete m_reservations[i];
			m_reservations[i] = nullptr;
		}
		delete[] m_reservations;
		m_reservations = nullptr;
	}
	size_t Restaurant::size() const
	{
		return m_numOfReservations;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		static size_t uses = 0;
		uses++;
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant ("<<uses<<")" << std::endl;
		os << "--------------------------" << std::endl;
		if (!res.size()) {
			os << "This restaurant is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < res.m_numOfReservations; i++) {
				if (res.m_reservations[i] != nullptr) {
					os << *res.m_reservations[i];
				}
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}