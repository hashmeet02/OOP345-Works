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

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H
#include <iostream>
#include <string>


namespace sdds{
	struct TennisMatch {
		std::string tourney_id{};
		std::string tourney_name{};
		unsigned int match_id{};
		std::string winner{};
		std::string loser{};
	};
	
	class TennisLog {
		TennisMatch* m_matches{};
		unsigned int m_numMatches{};
	public:
		TennisLog();
		TennisLog(char* filename);

		~TennisLog();

		TennisLog(const TennisLog& toCopy);
		TennisLog& operator=(const TennisLog& toAssign);

		TennisLog( TennisLog&& toMove) noexcept;
		TennisLog& operator=( TennisLog&& toMove) noexcept;


		void addMatch(const TennisMatch& tennisMatch);
		TennisLog findMatches(const std::string playerName) const;
		TennisMatch operator[](size_t index) const;
		operator size_t() const;
	};

	
	std::ostream& operator<<(std::ostream& os, TennisMatch tennisMatch);
}
#endif // !SDDS_TENNISLOG_H
