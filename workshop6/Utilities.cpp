//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 3rd, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* ptr = nullptr;
		std::string tag{};
		bool flag = true;
		std::getline(in, tag, ',');
		for (int i = 0; tag.length() && flag; i++) {
			if (!isspace(tag[i])) {
				flag = false;
				if (tag[i] == 'c' || tag[i] == 'C') {
					ptr = new Car(in);
				}
				else if (tag[i] == 'v' || tag[i] == 'V') {
					ptr = new Van(in);
				}
				else if (tag[i] == 'r' || tag[i] == 'R') {
					ptr = new Racecar(in);
				}
				else if (tag[i] == 'l' || tag[i] == 'L') {
					ptr = new Luxuryvan(in);
				}
				else {
					std::string errMsg = "Unrecognized record type: [";
					errMsg+= tag[i];
					errMsg += "]";
					in.ignore(500,'\n');
					throw std::string(errMsg);
					
				}
			}
		}
		return ptr;
	}
}