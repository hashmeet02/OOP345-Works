//-------------------------------------------------------------------------------------------------------- -
//Workshop 8
//Name : Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 16th, 2022
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//-------------------------------------------------------------------------------------------------------- -

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool checkLuhn(std::string testSin)
		{
			size_t length = testSin.length();
			size_t number = 0;
			size_t sum = 0;
			for (size_t i = 0; i < length; i++)
			{
				number = testSin[i] - '0';
				if (i % 2 != 0)
				{
					number *= 2;
					if (number > 9)	number -= 9;
				}
				sum += number;
			}
			return sum % 10 == 0;
		}

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(T& object) {
			list.push_back(object);
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(T* object) {
			list.push_back(*object);
		}
		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
