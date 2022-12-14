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

#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include <iostream>
#include <string>

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	const int MAX_BRAND_LEN = 10;
	const int MAX_MODEL_LEN = 15;

	void listArgs(int argc, char* argv[]);
	class Cars {
		char* m_brand{};
		char m_model[MAX_MODEL_LEN]{};
		int m_year{};
		double m_price{};
		char m_status{};
		bool m_discounted{};
	public:
		//Default Constructor
		Cars();

		//Argument Constructor
		Cars(char* brand, char* model, int year, double price, char status, char discount);

		//rule of three
		~Cars();
		Cars(const Cars& toCopy);
		Cars& operator=(const Cars& toAssign);

		//modiefiers
		void read(std::istream& is);

		//queries
		void display(bool reset) const;
		char getStatus() const;
		operator bool()const;
	};
	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2);
}


#endif // !SDDS_CARADS_H
