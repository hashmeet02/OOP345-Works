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
		T m_dummyObject{};
	public:
		~Queue() {}
		bool push(const T& item) {
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
		T pop(){
			m_dummyObject = m_queue[0];
			m_queue[0] = {};
			for (unsigned int i = 0; i < m_numOfElem-1; i++) {
				m_queue[i] = m_queue[i + 1];
			}
			m_queue[m_numOfElem]={};
			m_numOfElem--;
			return m_dummyObject;
		}
		unsigned int size() const {
			return m_numOfElem;
		}

		std::ostream& display(std::ostream& os = std::cout) const {
			os << "----------------------" << std::endl;
			os << "| Dictionary Content |" << std::endl;
			os << "----------------------" << std::endl;
			for (unsigned int i = 0; i < m_numOfElem; i++) {
				os<<m_queue[i]<< std::endl;
			}
			os << "----------------------" << std::endl;
			return os;
		}

		T operator[](unsigned int index) {
			m_dummyObject={};
			if (index < m_numOfElem) {
				m_dummyObject = m_queue[index];
			}
			return m_dummyObject;
		}
	};
	//template <typename T>
	//bool operator==(const T& lo, const T& ro) {
	//	if T.m_
	//}
	/*template<>
	Queue <Dictionary, 100u>
		Dictionary m_queue[100u]{("Empty Term","Empty Definititon")};
		unsigned int m_numOfElem=100u;
		T m_dummyObject{};*/
	

}

#endif // !SDDS_QUEUE_H
