/* 
implementation file for string.hpp
Jerry Zheng 
*/

#include <iostream>
#include "string.hpp"
#include <vector>

//empty string 
String::String(){
  stringSize=1;
  str=new char[stringSize];
  str[0]='\0';
}

//string with character
String::String(char a){
  stringSize=2;
  str=new char[2];
  str[0]=a;
  str[1]='\0';
}

//String with multiple characters
String::String(const char charArr[]){
  int len=0;
  while(charArr[len]!='\0'){
    ++len;
  }
   stringSize=len+1;
  str=new char[stringSize];
  for (int i=0; i<len;++i){
      str[i]=charArr[i];
 }
  str[len]='\0';
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
   return (stringSize-1);
 }

//returns how many characters are in the string
 int String::length()const {
   int i=0;
   while (str[i]!='\0'){
     ++i;
   }
   return i;
 }

 String& String::operator+=(const String& s2){
   int offset=length();
   *this=String(length()+s2.length(),str);
   for(int i=0;i<=s2.length();++i)
     str[offset+i]=s2.str[i];
   return *this;
 }

//concatenation
String String::operator+(const String& rhs)const{
  String result(str);
  if((rhs.length()+length()+1)>capacity())
    result.resetCapacity(rhs.length()+length()+1);
  int offset = length();                       
  int i = 0;
  while(rhs.str[i] != '\0'){
    result.str[offset + i] = rhs.str[i];
    ++i;
  }  

  result.str[offset + i] = '\0';
  result.stringSize = offset+i+1;
  return result;
}


 //compares two string are equal
 bool String::operator==(const String& s2)const{
   if(length()!=s2.length())
     return false;

     for(int i=0; i<length();++i)
       if(str[i]!=s2.str[i])
     return false;

     return true;
  
 }

 //overloading < 
bool String::operator< (const String& s2) const {
  if(length()<s2.length()){
      for(int i=0; i < length();++i){
	if(str[i]>s2[i])
	  return false;
      }
      return true;
    }
    else{
      for(int i=0;i<=s2.length();++i){
	if(str[i]<s2[i])
	  return true;
      }
	return false;
    }
}
 // return substring from start to end position
 String String::substr(int start, int end) const {
   if(start<0){start=0;}
   if(start>end){return String();}
   if (start>= length()){return String();}
   if (start>length()){return String();}
   int len=0;
   if(start==end)
     len=2;
   else{
     len=(end-start)+1;
   }  
   int i;
     char temp[len];
     for ( i=start;i<=end;++i)
       temp[i-start]=str[i];
     temp[i-start]='\0';
     String result(temp);
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
  if (pos<0){
    pos=0;
  }
  if(pos>length()-s2.length()){
    return -1;
  }
  int len=s2.length();
  int i=pos;
  while(str[i]!='\0'){
    if(substr(i,i+len-1)==s2){
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


//destructor
String::~String(){
  delete[]str;
}


//copy constructor
String::String(const String& s2){
  stringSize=s2.stringSize;
  str=new char[stringSize];
  for(int i=0;i<stringSize;++i)
      str[i]=s2.str[i];
}

String::String(int x){
  stringSize=x+1;
  str=new char[stringSize];
  str[0]='\0';
}

String::String(int x, const char charArr[]){
  int len=0;
  while(charArr[len] != '\0'){
    ++len;
  }
 stringSize=len+1;
 str=new char[stringSize];
 for (int i=0; i< x ;++i){
   str[i]=charArr[i];
 }
 str[len]='0';
}

//swap function
void String::swap(String& s2){
  char *temp=str;
  str=s2.str;
  s2.str=temp;

  int tmp;
  tmp=stringSize;
  stringSize=s2.stringSize;
  s2.stringSize=tmp;
}


 
//operator overload function
 String& String::operator=(String s2){
  swap(s2);
  return *this;
}
void String::resetCapacity(int x){
  char *temp = new char[x];
  for(int i=0; i<length();++i)
    temp[i]=str[i];
  delete[]str;
  str=temp;
  stringSize=x;
}
std::vector<String>String::split(char c)const{
  std::vector<String> v;
  if(c=='\0'){
    for(int i=0;i<length();++i){
      v.push_back(str[i]);
  }
  return v;
}

  String temp;
  for(int i=0; i<length();++i){
    if(str[i]!=c){
      temp=temp+str[i];
    }
    else{
      v.push_back(temp);
      if(str[i+1]!=str[i]){
	temp=str[++i];
      }
      else{
	String temp2;
	temp=temp2;
      }
    }
  }
return(v.push_back(temp),v);
}
/*int String::stringInt(){
  int begin=length()-1;
  if(str[begin]=='-')
    return 0;

  int result=0; tens=1;
  for(int i=0;i >=0;--i){
    result = result + (int(str[i] - int('0')) * ten);
    ten *= 10;
  }
  return result;

}
*/
 //overloading relational operators
 String operator+(const char s1[], const String& s2){
   String result(s1);
   return(result + s2);
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
