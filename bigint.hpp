/** 
Jerry Zheng
 this is the header file for big int
bigint.hpp
**/

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include<iostream>
const int CAPACITY=400;

class bigint{
public:
  bigint(); // default constructor
  bigint(int); // initialize bigint to int 
  bigint(const char[]); // initialize bigint to a const char[]
  void debugPrint(std::ostream&)const; // debugprint method
  friend std::ostream& operator<<(std::ostream& ,const bigint&);// takes a stream and writes bigint to the stream 
  friend std::istream& operator>>(std::istream& , bigint&);  // read in digits 
  bool operator==(const  bigint&); // overload == operator to compare two bigints
  bigint operator+(const bigint&)const;  // adds two bigints together 
  int operator[](int)const; // return the digit in the bigint
  int& operator[](const int place); // return address of the digit
  bigint times_digit(int)const;// multiply a bigint with a digit
  bigint times_10(int)const;//multiply a bigint by 10^n 
  bigint operator*(bigint);// multiplies two bigints together
private:
  int big[CAPACITY]; // bigint array 

};


#endif
