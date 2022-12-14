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
#include <chrono>
#include "Timer.h"

namespace sdds {

	void Timer::start()
	{
		m_start = std::chrono::steady_clock::now();
	}

	long long int Timer::stop()
	{
		m_end=std::chrono::steady_clock::now();
		m_dur = m_end - m_start;
		auto nanoDur = std::chrono::duration_cast<std::chrono::nanoseconds>(m_dur);
		return (long long int)nanoDur.count();
	}
}