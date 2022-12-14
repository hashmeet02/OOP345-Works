//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : Septemeber 29th, 2022

//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include <iostream>
#include <string>
#include "Dictionary.h"

namespace sdds {
	template <typename T, unsigned int CAPACITY>
	class Queue {
		T m_queue[CAPACITY]{};
		unsigned int m_numOfElem{};
		static T m_dummyObject;
	public:
		virtual ~Queue() {}
		virtual bool push(const T& item) {
			bool flag = true;
			if (CAPACITY > m_numOfElem) {
				m_queue[m_numOfElem] = item;
				m_numOfElem++;
			}
			else {
				flag = false;
			}
			return flag;
		}
		T pop() {
			T object = m_queue[0];
			for (unsigned int i = 0; i < size() - 1; i++) {
				m_queue[i] = m_queue[i + 1];
			}
			m_queue[size()] = {};
			m_numOfElem--;
			return object;
		}
		unsigned int size() const {
			return m_numOfElem;
		}

		std::ostream& display(std::ostream& os = std::cout) const {
			os << "----------------------" << std::endl;
			os << "| Dictionary Content |" << std::endl;
			os << "----------------------" << std::endl;
			for (unsigned int i = 0; i < size(); i++) {
				os << m_queue[i] << std::endl;
			}
			os << "----------------------" << std::endl;
			return os;
		}

		T operator[](unsigned int index) const{
			T object{};
			if (index < size()) {
				object = m_queue[index];
			}
			else object = m_dummyObject;
			return object;
		}
	};
	template <typename T, unsigned int CAPACITY>
	T Queue<T, CAPACITY>::m_dummyObject = {};
	
	template <>
	Dictionary Queue<Dictionary, 100u>::m_dummyObject{"Empty Term", "Empty Substitute"};
}

#endif // !SDDS_QUEUE_H
