#include <iostream>
#include <vector>
#include <string>
#include <bitset>
class dog{
   int d;
   public :
      int e;
};
int main(){
      int i; 
      double d; 
      const std::string *ps; 
      char *pc; 
      void *pv; 
      pv = const_cast<void *>(static_cast<const void *>(ps));  
      char ch ='d';
      pc= &ch;
      i = static_cast<int>(*pc);
      pv = &d; 
      pv = &d;
      pc = static_cast<char *>(pv);
   return 0;
}