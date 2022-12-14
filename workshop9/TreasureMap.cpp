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
// TreasureMap.cpp
// Michael Huang

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <memory>
#include "TreasureMap.h"

namespace sdds{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.
            std::ofstream f(filename, std::ios::out | std::ios::binary | std::ios::trunc);
            if (f) {
                f.write(reinterpret_cast<char*>(&rows), sizeof (rows));
                f.write(reinterpret_cast<char*>(&colSize), sizeof (colSize));
                for (size_t i = 0; i < rows; i++) {
                    //f.write(reinterpret_cast<char*>(&map[i][0]), sizeof (colSize));
                    
                    f.write(&map[i][0], colSize);
                }
            }
            else {
                throw std::string("cant open file");
            }
            // END TODO
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.
        std::ifstream f(filename, std::ios::in | std::ios::binary);
        if (f) {
            size_t i = 0;
            f.read(reinterpret_cast<char*>(&rows), sizeof(rows));
            f.read(reinterpret_cast<char*>(&colSize), sizeof(colSize));
            map = new std::string[rows];
            while (f && i<rows) {
                //f.read(reinterpret_cast<char*>(&map[i][0]), sizeof (colSize));
                
                map[i].resize(colSize);
                f.read(&map[i][0], colSize);
                i++;
            }
        }
        else {
            throw std::string("cant open file");
        }
        // END TODO
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    std::string TreasureMap::splitter(const size_t index1, const size_t index2) const
    {
        std::string result;
        for (size_t i = index1; i < index2; i++) {
            result = result + map[i];
        }
        return result;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        //for (size_t i = 0; i < rows; ++i){
        //    count += digForTreasure(map[i], mark);
        //}
        size_t first = 0;
        size_t q1 = first+ rows/4;
        size_t half = first+ rows/2;
        size_t q3 = half+rows/4;
        size_t last = first+rows;

        std::string q1Str = splitter(first, q1);
        std::string q2Str = splitter(q1, half);
        std::string q3Str = splitter(half, q3);
        std::string q4Str = splitter(q3, last);
        //
        using namespace std::placeholders;
        auto task = std::bind(digForTreasure,_1,mark );

        std::packaged_task<size_t(std::string)>pt1(task);
        std::packaged_task<size_t(std::string)>pt2(task);
        std::packaged_task<size_t(std::string)>pt3(task);
        std::packaged_task<size_t(std::string)>pt4(task);
        auto f1 = pt1.get_future();
        auto f2 = pt2.get_future();
        auto f3 = pt3.get_future();
        auto f4 = pt4.get_future();

        pt1(q1Str);
        pt2(q2Str);
        pt3(q3Str);
        pt4(q4Str);
        count = f1.get() + f2.get() + f3.get() + f4.get();

        return count;
    }
}