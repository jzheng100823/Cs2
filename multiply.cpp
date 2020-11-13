#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"
int main(){
  std::fstream in("data1-2.txt");
  if(!in){
    std::cerr<<"Could not open data1-2.txt,exiting"<<std::endl;
    exit(1);
  }
  bigint b1,b2,result;
  in>>b1;
  in>>b2;

  //print until the end of the file
  while(!in.eof()){
    std::cout<< "bigint 1 "<<b1<<std::endl; //prints bigint 1
    std::cout<< "bigint 2 "<<b2<<std::endl;// prints bigint 2
    result= b1*b2; //multiplies 2 bigints together 
    std::cout<<"result =  "<<result<<std::endl;//prints the result
    in>>b1;
    in>>b2;
  }
  in.close();
    return 0l;
}
