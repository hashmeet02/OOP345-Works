//--------------------------------------------------------------------------------------------------------
//Workshop 9 
//Name : Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : November 21st, 2022
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my project milestones.
//--------------------------------------------------------------------------------------------------------

// Workshop 9 - Multi-threading
// TreasureMap.h
// Michael Huang

#ifndef SDDS_TREASUREMAP_H
#define SDDS_TREASUREMAP_H

#include <cstddef>
#include <iostream>
#include <string>
#include <thread>
#include <future>

namespace sdds{

    size_t digForTreasure(const std::string& str, char mark);

    class TreasureMap{
        size_t rows = 0;
        size_t colSize = 0;
        std::string* map = nullptr;
    public:
        TreasureMap(const char* filename);
        ~TreasureMap();

        std::string operator[](int i) const{
            return map[i % rows];
        }

        size_t size() const{
            return rows;
        }

        std::ostream& display(std::ostream& os) const;
        void enscribe(const char* filename); 
        void recall(const char* filename);
        void clear();
        std::string splitter(const size_t index1, const size_t index2) const;

        size_t findTreasure(char mark);
    };

}

#endif