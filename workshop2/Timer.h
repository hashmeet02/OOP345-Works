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

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>

namespace sdds {
	class Timer {
		std::chrono::time_point<std::chrono::steady_clock> m_start, m_end;
		std::chrono::duration<float> m_dur;
	public:
		void start();
		long long int stop();
	};
}
#endif // !SDDS_TIMER_H
