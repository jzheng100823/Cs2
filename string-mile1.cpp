/* 
implementation file for string.hpp
Jerry Zheng 
*/

#include <iostream>
#include "string.hpp"

//empty string 
String::String(){
  str[0]='\0';
}

//string with character
String::String(char a){
  str[0]=a;
  str[1]='\0';
}

//String with multiple characters
String::String(const char charArr[]){
  int i=0;
  while (charArr[i]!='\0'){
    str[i]=charArr[i];
    if (i >= capacity()) {
      break;
    }
    ++i;
  }
    str[i]=0;   
}
  //modifier for []
char& String::operator[](int i){
    return str[i];
  }

//accessor for []
 char String::operator[](int i) const{
   return str[i];
 }

 //return the max capcity withought null
 int String::capacity()const {
   return STRING_SIZE -1;
 }

 //return how many characters are in the string
 int String::length()const {
   int i=0;
   while (str[i]!='\0'){
     ++i;
   }
   return i;
 }

 String& String::operator+=(const String s2){
   int offset=length();
   int i=0;
   while(str[i]!='\0'){
     str[offset + i] =s2.str[i];
     ++i;
 }
   str[offset+ i]='\0';
   return *this;
 }


String String::operator+(const String& s2)const{
 int offset=length();
 String result(str);
   int i=0;
   while(s2.str[i]!='\0'){
     if((offset +i)>=(capacity()))
       break;
    result.str[offset+i]=s2.str[i];
     ++i;
   }
   result.str[offset +i]='\0';
   return result;
}

 //compares two string are equal
 bool String::operator==(const String& s2)const{
   int i=0;
   while((str[i]!='\0'&& s2.str[i]!='\0' && str[i]==s2.str[i]))
     ++i;
   return str[i]==s2.str[i];
  
 }

 //overloading < 
bool String::operator< (const String& s2) const{
 int i=0;
 while(str[i]!='\0'&& s2.str[i]!='\0' && str[i]==s2.str[i]){
     ++i;
 }
 if(str[i]==s2.str[i])
   return false;
 if (str[i]<s2.str[i])
   return true;
 if(str[i]=='\0' && s2.str[i]=='\0')
   return false;
 else
   return false;

}
 // return substring from start to end position
 String String::substr(int start, int end) const {
   String result;
   int i;
   if(start<0){start=0;}
   if(start>end){return String();}
   if (start>= length()){return String();}
   for (i=start; i<=end; ++i){
     result.str[i-start]=str[i];
   }
   result.str[i-start]='\0';
   return result;
 }


 //returns location of ch at pos
 int String::findch (int pos,char ch) const{
   if(pos<0){pos=0;}
   if((pos>length())||(pos<0)){return -1;}

   while((str[pos]!=0)&&(str[pos]!=ch))
     ++pos;
   if(str[pos]=='\0')
     return -1;
   else{
     return pos;
   }
 }

 
int String::findstr(int pos, const String& s2)const{
  if (pos < 0) {
    pos = 0;
  }
  if (pos > length() - s2.length()) {
    return -1;
  }
  int len = s2.length();
  int i = pos;
  while (str[i] != '\0') {
    if (substr(i, i + len - 1) == s2) {
      return i;
    }
    ++i;
  }
  return -1;
}




 //overlaoding inputstram
 std::istream& operator>>(std::istream& in , String& s2){
    char c;
    in.get(c);
   int i=0;
   while ((c!=' ')&&(c!='\n')&&(!in.eof())){
     s2.str[i]=c;
     ++i;
     in.get(c);
   }
   s2.str[i]='\0';
   return in;
  
 }
 //overloading output stream 
 std::ostream& operator<<(std::ostream& out , const String& s2){
   int cnt=0;
   while( s2.str[cnt]!='\0'){
   out<< s2.str[cnt];
   cnt++;
   }
   return out;
 }



 //overloading relational operators
 String operator+(const char s1[], const String& s2){
   String result(s1);
   return(result+ s2);
 }

 String operator+(char s1 , const String& s2){
   String result(s1);
   return (result+s2);
   }

 bool operator ==(const char s1[], const String& s2){
   return(String(s1)==s2);
 }

bool operator ==(char s1 , const String& s2){
  return (String(s1)==s2);
}

bool operator< (const char s1[],const  String& s2){
  return(String(s1)<s2);
}

bool operator< ( char s1, const  String& s2){
  return(String(s1)<s2);
}

bool operator <=(const String& s1, const String& s2){
  return((s1 < s2)||(s1 == s2));
}

bool operator !=(const String& s1, const String& s2){
  return!(s1==s2);
}

bool operator>(const String& s1, const String& s2){
  return (s2<s1);
}

bool operator >=(const String& s1, const String& s2){
  return(!(s1<s2)||(s1==s2));
}
