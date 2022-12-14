#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include <iostream>
#include "Queue.h"

namespace sdds {
	template<typename T>
	class UniqueQueue : public Queue<T, 100> {
	public:
		bool push(const T& item) {
			bool flag = false;
			bool foundFlag = false;
			for (unsigned int i = 0; i < Queue<T, 100>::size(); i++) {
				if (Queue<T, 100>::operator[](i)==item) {
					foundFlag = true;
				}
			}
			if (!foundFlag) {
				flag = Queue<T, 100>::push(item);
			}
		}
		/*bool push(const T& item) {
			bool flag = false;
			bool foundFlag = false;
			if (Queue::size() < 100) {
				for (unsigned int i = 0; i <Queue<T, 100>.size(); i++) {
					if (item == Queue::operator[].i) {
						foundFlag = true;
					}
				}
				if (!foundFlag) {
					flag=Queue::push(item);
				}
			}
			return flag;
		}*/
	};
}
#endif // !SDDS_UNIQUEQUEUE_H
