// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: March 27, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <string>

#include "utils.h"
#include "Patient.h"

namespace sdds 
{
    Patient::Patient(int NUM, bool check):object(NUM) {
        flag = check;
    }
    Patient::~Patient() {
        delete[] m_name;
    }



    void Patient::fileIO(bool check) {
        flag = check;
    }
    void Patient::setArrivalTime() {
        object.resetTime();
    }


    bool Patient::operator ==(char x) const {
            return x == type();
    }
    bool Patient::operator ==(const Patient& any) const {
            return type() == any.type();
    }
    bool Patient::fileIO() const {
            return flag;
    }



    std::istream& Patient::read(std::istream& istr) {
        int lenght;

        std::cout << "Name: ";
        std::string name;
        std::getline(istr, name);

        lenght = name.length();

        delete[] m_name;
        m_name = new char[lenght + 1];
        strcpy(m_name, name.c_str());

        m_name[lenght] = '\0';

        std::cout << "OHIP:";
        o_num = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ");
        
            return istr;
    }
    std::istream& Patient::csvRead(std::istream& istr) {
        int lenght;

        std::string name;
        std::getline(istr, name, ',');

        lenght = name.length();

        delete[] m_name;

        m_name = new char[lenght + 1];
        strcpy(m_name, name.c_str());

        m_name[lenght] = '\0';
        
        istr >> o_num;
        istr.ignore();

            return object.csvRead(istr);
    }



    std::ostream& Patient::write(std::ostream& ostr) const
    {
        int i;

        ostr << object << '\n';

        for(i = 0; i < 25 && m_name[i]; i++)
        {
            ostr << m_name[i];
        }

        ostr << ", OHIP: ";
        ostr << o_num;

            return ostr;
    }
    std::ostream& Patient::csvWrite(std::ostream& ostr) const {
        ostr << type() << ',';
        ostr <<m_name << ',';
        ostr << o_num << ',';

            return object.csvWrite(ostr);
    }



    int Patient::number() const {
            return object.number();
    }



    Patient::operator Time() const {
            return Time(object);
    }
}