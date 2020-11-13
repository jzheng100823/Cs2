/** 
Jerry Zheng 
bigint.cpp file
function definition page 
**/

#include "bigint.hpp"

//sets array to 0
bigint::bigint(){

  for(int i=0; i<CAPACITY; ++i){
    big[i]=0;
  }
}

//sets bigint to int value
bigint::bigint(int i){

  for(int j=0; j<CAPACITY; ++j){
    big[j]=i%10;
    i= i/10;
  }
}

//initializez bigint to a const char[]
bigint::bigint(const char a[]){

 int i=0;
  for(int x=0;x<CAPACITY;++x){
    big[x]=0;
  }
  while( a[i]!='\0'){
    ++i;
  }
  --i;
  for(int j=0; i>-1; --i ){
   big[j]=a[i]-'0';
   ++j;
  }
}

//print out every element in the array
void bigint::debugPrint(std::ostream& out)const {

  for(int i=CAPACITY-1; i>=0; --i){
    out<<"|"<<big[i]<<"|";
  }
  out<<std::endl;
}



//overload  operator <<
std::ostream & operator<<(std::ostream & out,const  bigint& b1){

  bool leadzero=true;
  int tracker=0;

  for(int i=CAPACITY-1;i>=0;--i){
    if(b1.big[i]!=0){
	  leadzero=false;
      }
  
    if(!leadzero){
      if(tracker>=80){
	tracker=0;
	out <<"/n";
      }
      out<<b1.big[i];
      tracker++;
    }
  }
   if(leadzero) { out << 0; }
  return out;
}



//compares if two bigints are equal
bool bigint::operator==(const bigint& b1){

  for(int i=0; i<CAPACITY; ++i){
    if(big[i] != b1.big[i]) return false;
  }
  return true;
}

//overloading >> input operator
std::istream& operator>>(std::istream& in , bigint& b1){

   b1=bigint(); //set b1 to empty
   char c_array[CAPACITY],c='\0';
   int digit=0;
   in >> c;
     while((c!=';') && (!in.eof())){
      c_array[digit]=c;
      ++digit; 
      in >> c;
     }

       for(int i=0; i<digit; ++i){
         b1.big[digit - i - 1]=c_array[i]-'0';// changes char to int
       }

     return in;
}


//overload + operator  
bigint bigint::operator+(const bigint& b2)const {

  bigint result;
  int x=0;
  int y=0;

  for(int i=0;i<CAPACITY;i++){
   y=big[i]+b2.big[i]+y;
   x=y%10;
   y/=10;
   result.big[i]=x;
  }
return result;
}


//overload[]operator
int bigint:: operator[](const int place)const{

    if((place<CAPACITY)&&(place>=0)){
      return big[place];
	}
    else{
      return 0;
    }
}
int& bigint::operator[](const int place){ 

   if((place<CAPACITY)&&(place>=0)){
     return big[place];
   }
  else{
  }
 }

//multiplies bigint with digit
bigint bigint::times_digit(int x)const{
  bigint actual = *this;
  bigint result;
  if(x==0) return bigint(0);
  if(x>0 && x<10){
      for(int i=0; i<x;++i)
	result=result + actual;
    }
  return result;
}

//multiplies bigit with 10^n with n>0
bigint bigint::times_10(int x) const{
  bigint number;
  for(int i=0; i<CAPACITY-x;++i){// shifts bigint to the left x times 
    number[i+x]=big[i];
 }
  return number;
}
//multiplies two bigint
bigint bigint::operator*(bigint b2){
  bigint product=0;
  bigint temp;
  for(int i=0; i<CAPACITY-1;++i){
      temp = this->times_digit(b2[i]);
      product=product + temp.times_10(i);
  }
  return product;
};

