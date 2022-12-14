//--------------------------------------------------------------
//Name:		Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 3rd, 2022

//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "Autoshop.h"

namespace sdds {
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);
        return *this;
    }
    void Autoshop::display(std::ostream& out) const
    {
        for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
            (*it)->display(out);
            out << std::endl;
        }
    }
    Autoshop::~Autoshop()
    {
        for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
            delete *it;
            *it = nullptr;
        }
    }
}
