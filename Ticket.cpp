// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: March 27, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>

#include "Ticket.h"

namespace sdds 
{
   Ticket::Ticket(int NUM) {
      num = NUM;
   }



   void Ticket::resetTime() {
      time.setToNow();
   }



   std::istream& Ticket::read(std::istream& istr) {
         return csvRead(istr);
   }
   std::istream& Ticket::csvRead(std::istream& istr) {
      istr >> num;
      istr.ignore();
         return istr >> time;
   }



   std::ostream& Ticket::write(std::ostream& ostr) const {
         return ostr << "Ticket No: " << num << ", Issued at: " << time ;
   }
   std::ostream& Ticket::csvWrite(std::ostream& ostr) const {
         return ostr << num << "," << time;
   }



   Ticket::operator Time() const {
         return time;
   }



   int Ticket::number() const {
         return num;
   }

}
