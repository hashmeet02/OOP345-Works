//-------------------------------------------------------------------------------------------------------- -
//Workshop 8
//Name : Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 16th, 2022
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//-------------------------------------------------------------------------------------------------------- -

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id) {
					EmployeeWage empWage(emp[i].name, sal[j].salary);
					empWage.rangeValidator();
					if (!activeEmp.checkLuhn(emp[i].id))
						throw std::string("*** Wrong Salaries with SIN No's");
					EmployeeWage* empWagePtr = &empWage;
					activeEmp += empWagePtr;
				}
			}
		}
		
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id) {
					std::unique_ptr<EmployeeWage> empWage(new EmployeeWage(emp[i].name, sal[j].salary));
					empWage->rangeValidator();
					if (!activeEmp.checkLuhn(emp[i].id))
						throw std::string("*** Wrong Salaries with SIN No's");
					activeEmp += *empWage;
				}
			}
		}
		return activeEmp;
	}
}