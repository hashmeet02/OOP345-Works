//-------------------------------------------------------------------------------------------------------- -
//Workshop 8
//Name : Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 16th, 2022
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//-------------------------------------------------------------------------------------------------------- -

#ifndef SDDS_WRITINGRECORD_H
#define SDDS_WRITINGRECORD_H

#include "GeneratingList.h"
#include "EmpProfile.h"

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
}


#endif // SDDS_WRITINGRECORD_H

