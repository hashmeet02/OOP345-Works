//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : October 13th, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "SpellChecker.h"

namespace sdds {
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		std::string strWords;
		size_t cnt = 0;
		do
		{
			std::getline(file, strWords);

			if (file)
			{
				m_badWords[cnt] = trim(strWords.substr(0, strWords.find(" ")));
				strWords.erase(0, strWords.find(" ") + 1);

				m_goodWords[cnt] = trim(strWords.substr(0, strWords.find("\n")));
				strWords.erase(0, strWords.find("\n") + 1);
				++cnt;
			}
		} while (file);
		file.close();
	}

	void SpellChecker::operator()(std::string& text)
	{
		for (int i = 0; i < 6; i++) {
			size_t pos = text.find(m_badWords[i]);
			while (pos != std::string::npos)
			{
				// Replace this occurrence of Sub String
				text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
				m_counter[i]++;
				// Get the next occurrence from the current position
				pos = text.find(m_badWords[i], pos + m_goodWords[i].size());
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (int i=0; i < 6; i++) {
			out.width(15);
			out << m_badWords[i] << ": " << m_counter[i] << " replacements" << std::endl;
		}
	}

	std::string SpellChecker::ltrim(const std::string& s)
	{
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}
	std::string SpellChecker::rtrim(const std::string& s)
	{
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}
	std::string SpellChecker::trim(const std::string& s)
	{
		return rtrim(ltrim(s));
	}
}