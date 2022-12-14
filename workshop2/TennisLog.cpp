// -----------------------------------------------------------
// Name:		Hashmeet Singh Saini
// Seneca ID :	hsaini28
// Student No.:	153070214
// Date :		Septemeber 21th, 2022
// 
// I have done all the coding by myselfand only copied the code
// that my professor provided to complete my project milestones.
// ------------------------------------------------------------
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include "TennisLog.h"

namespace sdds {
	std::ostream& operator<<(std::ostream& os, TennisMatch tennisMatch)
	{
		if (!tennisMatch.match_id) {
			os << "Empty Match";
		}
		else {
			os.fill('.');
			os.width(23);
			os << "Tourney ID : ";
			os.width(30);
			os.setf(std::ios::left);
			os << tennisMatch.tourney_id << std::endl;
			os.unsetf(std::ios::left);

			os.width(23);
			os << "Match ID : ";
			os.width(30);
			os.setf(std::ios::left);
			os << tennisMatch.match_id << std::endl;
			os.unsetf(std::ios::left);

			os.width(23);
			os << "Tourney : ";
			os.width(30);
			os.setf(std::ios::left);
			os << tennisMatch.tourney_name << std::endl;
			os.unsetf(std::ios::left);

			os.width(23);
			os << "Winner : ";
			os.width(30);
			os.setf(std::ios::left);
			os << tennisMatch.winner << std::endl;
			os.unsetf(std::ios::left);

			os.width(23);
			os << "Loser : ";
			os.width(30);
			os.setf(std::ios::left);
			os << tennisMatch.loser << std::endl;
			os.unsetf(std::ios::left);

		}
		return os;
	}
	TennisLog::TennisLog()
	{
		m_matches = nullptr;
		m_numMatches = 0;
	}
	TennisLog::TennisLog(char* filename)
	{
		m_numMatches =0;
		std::string record;
		std::ifstream file(filename);
		while (std::getline(file, record)){
			m_numMatches++;
		}
		file.clear();
		file.seekg(0);
		m_numMatches--;
		m_matches = new TennisMatch[m_numMatches];

		std::getline(file, record);
		for (unsigned int i = 0; i < m_numMatches; i++) {
			TennisMatch temp{};
			std::getline(file, temp.tourney_id, ',');
			std::getline(file, temp.tourney_name, ',');
			file >> temp.match_id;
			file.ignore();
			std::getline(file, temp.winner, ',');
			std::getline(file, temp.loser, '\n');
			m_matches[i] = temp;
		}
		file.close();
	}
	TennisLog::~TennisLog()
	{
		delete[] m_matches;
		m_matches = nullptr;
	}
	TennisLog::TennisLog(const TennisLog& toCopy){
		*this = toCopy;
	}
	TennisLog& TennisLog::operator=(const TennisLog& toAssign)
	{
		if (this != &toAssign) {
			delete[] m_matches;
			m_matches = nullptr;
			m_numMatches = toAssign.m_numMatches;
			if (toAssign.m_matches!=nullptr) {
				m_matches = new TennisMatch[m_numMatches];
				for (unsigned int i = 0; i < m_numMatches; i++) {
					m_matches[i] = toAssign.m_matches[i];
				}
			}
		}
		return *this;
	}
	TennisLog::TennisLog( TennisLog&& toMove) noexcept{
		*this = std::move(toMove);
	}
	TennisLog& TennisLog::operator=(TennisLog&& toMove) noexcept
	{
		if (this != &toMove) {
			delete[] m_matches;
			m_numMatches = toMove.m_numMatches;
			m_matches = toMove.m_matches;
			toMove.m_matches = nullptr;
			toMove.m_numMatches = 0;
		}
		return *this;
	}
	void TennisLog::addMatch(const TennisMatch& tennisMatch)
	{
		TennisMatch* temp{};
		temp = new TennisMatch[this->m_numMatches + 1];
		for (unsigned int i = 0; i < m_numMatches; i++) {
			temp[i] = m_matches[i];
		}
		temp[m_numMatches] = tennisMatch;
		delete[] m_matches;
		m_matches = nullptr;
		m_matches = temp;
		m_numMatches += 1;
	}
	TennisLog TennisLog::findMatches(const std::string playerName) const
	{
		TennisLog temp;
		for (unsigned int i = 0; i < m_numMatches; i++) {
			if ((!playerName.compare(m_matches[i].winner)) || (!playerName.compare(m_matches[i].loser))) {
				temp.addMatch(m_matches[i]);
			}
		}
		return temp;
	}
	TennisMatch TennisLog::operator[](size_t index) const
	{
		TennisMatch match;
		if (m_matches != nullptr) {
			match = m_matches[index];
		}
		return match;
	}
	TennisLog::operator size_t() const
	{
		return m_numMatches;
	}
}