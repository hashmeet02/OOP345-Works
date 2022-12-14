//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 5th, 2022

//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "ConfirmationSender.h"

namespace sdds{

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& toCopy) {
		m_csReservations = nullptr;
		*this = toCopy;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& toAssign) {
		if (this != &toAssign) {
			delete[] m_csReservations;
			m_numOfReservations = toAssign.size();
			if (toAssign.m_csReservations != nullptr) {
				m_csReservations = new const Reservation * [size()];
				for (size_t i = 0; i < size(); i++) {
					m_csReservations[i] = toAssign.m_csReservations[i];
				}
			}
			else {
				m_csReservations = nullptr;
			}
		}

		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& toMove) noexcept{
		*this = std::move(toMove);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& toMove) noexcept {
		if (this != &toMove) {
			delete[] m_csReservations;
			m_numOfReservations = toMove.size();
			toMove.m_numOfReservations = 0;
			if (toMove.m_csReservations != nullptr) {
				m_csReservations = toMove.m_csReservations;
				toMove.m_csReservations = nullptr;
			}
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		m_numOfReservations = 0;
		delete[] m_csReservations;
		m_csReservations = nullptr;
	}

	size_t ConfirmationSender::size() const
	{
		return m_numOfReservations;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool found = false;
		if (m_csReservations) {
			for (size_t i = 0; i < m_numOfReservations; i++) {
				if (m_csReservations[i] == &res) {
					found = true;
				}
			}
		}
		if (!found) {
			const sdds::Reservation** temp{};
			temp = new const sdds::Reservation * [m_numOfReservations + 1];
			for (size_t i = 0; i < m_numOfReservations; i++) {
				temp[i] = m_csReservations[i];
			}
			temp[m_numOfReservations] = &res;
			delete[] m_csReservations;
			m_csReservations = temp;
			m_numOfReservations++;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool found = false;
		size_t j = 0;
		size_t i;
		if (res) {
			for (i = 0; i < size() && !found; i++) {
				if (m_csReservations[i] == &res) {
					found = true;
				}
			}
			if (found) {
				const Reservation** temp{};
				m_csReservations[i - 1] = nullptr;
				temp = new const Reservation * [size() - 1];
				for (size_t k = 0; k < size(); k++) {
					if (m_csReservations[k] != nullptr) {
						temp[j] = m_csReservations[k];
						j++;
					}
				}
				delete[]  m_csReservations;
				m_numOfReservations--;
				m_csReservations = temp;
				temp = nullptr;
			}
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, ConfirmationSender& cs)
	{
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (!cs.size()) {
			os << "There are no confirmations to send!" << std::endl;
		}
		else {
			for (size_t i = 0; i < cs.size(); i++) {
				if (cs.m_csReservations[i] != nullptr) {
					os << *cs.m_csReservations[i];
				}
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
