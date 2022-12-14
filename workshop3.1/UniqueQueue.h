//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : Septemeber 29th, 2022

//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include <iostream>
#include <cmath>
#include "Queue.h"

namespace sdds {
	template<typename T>
	class UniqueQueue : public Queue<T, 100> {
	public:
		bool push(const T& item) {
			bool flag = false;
			bool foundFlag = false;
			if (Queue<T, 100>::size() < 100) {
				for (unsigned int i = 0; i < Queue<T, 100>::size(); i++) {
					if (Queue<T, 100>::operator[](i) == item) {
						foundFlag = true;
					}
				}
				if (!foundFlag) {
					flag = Queue<T, 100>::push(item);
				}
			}
			return flag;
		}
	};
	template <>
	bool UniqueQueue<double>::push(const double& item) {
		bool flag = false;
		bool foundflag = false;
		if (UniqueQueue<double>::size() < 100) {
			for (unsigned int i = 0; i < UniqueQueue<double>::size() && !foundflag; i++) {
				if ((std::abs(operator[](i)) >= std::abs(item) - 0.005) && (std::abs(operator[](i)) <= std::abs(item) + 0.005)) foundflag = true;
			}
			if (!foundflag) {
				Queue::push(item);
				flag = true;
			}
		}
		return flag;
	};
}
#endif // !SDDS_UNIQUEQUEUE_H
