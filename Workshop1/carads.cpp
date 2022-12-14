// -----------------------------------------------------------
// Name:		Hashmeet Singh Saini
// Seneca ID :	hsaini28
// Student No.:	153070214
// Date :		Septemeber 12th, 2022
// 
// I have done all the coding by myselfand only copied the code
// that my professor provided to complete my project milestones.
// ------------------------------------------------------------
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "carads.h"

double g_taxrate;
double g_discount;

namespace sdds {
	void listArgs(int argc, char* argv[]) {
		std::cout << "Command Line:" << std::endl << "--------------------------" << std::endl;
		for (int i = 0; i < argc; i++) {
			std::cout <<"  "<<i + 1 << ": " << argv[i] << std::endl;
		}
		std::cout << "--------------------------" << std::endl << std::endl;
	}

	Cars::Cars()
	{
		m_brand = nullptr;
	}

	Cars::Cars(char* brand, char* model, int year, double price, char status, char discount) {
		
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);

		strcpy(m_model, model);
		m_status = status;
		m_year = year;
		m_price = price;

		if (discount == 'Y') {
			m_discounted = true;
		}
		else m_discounted = false;
	}

	Cars::~Cars() {
		delete[] m_brand;
		m_brand = nullptr;
	}

	Cars::Cars(const Cars& toCopy)
	{
		*this = toCopy;
	}

	Cars& Cars::operator=(const Cars& toAssign)
	{
		delete[] m_brand;
		int length = strlen(toAssign.m_brand);
		m_brand = new char[length + 1];

		strcpy(m_brand, toAssign.m_brand);
		strcpy(m_model, toAssign.m_model);
		m_year=toAssign.m_year;
		m_price=toAssign.m_price;
		m_status=toAssign.m_status;
		m_discounted=toAssign.m_discounted;
		return *this;
	}

	void Cars::read(std::istream& is)
	{
		char tempBrand[100]{};
		char discounted{};
		if (is.good()) {
			is.get(this->m_status);
			is.ignore();
			is.getline(tempBrand,100, ',');
			int length = strlen(tempBrand);
			m_brand = new char[length + 1];
			strcpy(m_brand, tempBrand);
			is.getline(this->m_model, 15, ',');
			is >> this->m_year;
			is.ignore();
			is >> this->m_price;
			is.ignore();
			is.get(discounted);
			is.ignore();
			if (discounted == 'Y') {
				m_discounted = 1;
			}
			else m_discounted = 0;
		}
	}

	void Cars::display(bool reset) const
	{
		static int counter=0;
		if (reset) {
			counter = 0;
		}
		counter++;
		std::cout.setf(std::ios::left);
		std::cout.width(2);
		std::cout << counter << ". ";

		std::cout.width(MAX_BRAND_LEN);
		std::cout << m_brand<<"| ";

		std::cout.width(MAX_MODEL_LEN);
		std::cout << m_model << "| ";

		std::cout.width(4);
		std::cout << m_year << " |";

		std::cout.width(12);
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout.unsetf(std::ios::left);
		std::cout << m_price + (m_price * g_taxrate)<<"|";

		if (m_discounted) {
			std::cout.width(12);
			std::cout << (m_price + (m_price * g_taxrate))- ((m_price + (m_price * g_taxrate))*g_discount)<< std::endl;
		}
		else {
			std::cout << std::endl;
		}
	}
	char Cars::getStatus() const
	{
		return m_status;
	}
	Cars::operator bool() const
	{
		return (getStatus()  == 'N');
	}

	std::istream& operator>>(std::istream& is, Cars& car)
	{
		char tStatus;
		char tBrand[100];
		char tModel[100];
		int tYear;
		double tPrice;
		char tDiscount;

		is >> tStatus;
		is.ignore();
		is.get(tBrand, 100, ',');
		is.ignore();
		is.get(tModel, 100, ',');
		is.ignore();
		is >> tYear;
		is.ignore();
		is >> tPrice;
		is.ignore();
		is >> tDiscount;
		is.ignore();
		sdds::Cars tempCar(tBrand, tModel, tYear, tPrice, tStatus, tDiscount);
		car = tempCar;
		return is;
	}

	void operator>>(const Cars& car1, Cars& car2)
	{
		car2 = car1;
	}
}

