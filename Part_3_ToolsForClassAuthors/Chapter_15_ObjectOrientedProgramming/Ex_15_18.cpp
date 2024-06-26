/************************************************************************************************************************************************************
 * @file Ex_15_18.cpp
 * @brief Exercise 15.18: Given the classes from page 612 and page 613, and assuming each object has the type
 * specified in the comments, determine which of these assignments are legal. Explain why those that are illegal
 * aren’t allowed:
 * @date 2024-02-04
 *
 * @copyright Copyright (c) 2024
 *
 *************************************************************************************************************************************************************/


 class Base {
 public:
      void pub_mem();     // public member
  protected:
       int prot_mem;       // protected member
  private:
      char priv_mem;           //private member
 };
 
 struct Pub_Derv : public Base {      // ok: derived classes can access protected members 
      char g() { return prot_mem; }
 };
 
 struct Priv_Derv : private Base {    // private derivation doesn’t affect access in the derived class      
    int f1() const { return prot_mem; }
  };
 
 struct Prot_Derv : protected Base {

 };

 struct Derived_from_Public : public Pub_Derv {   // ok: Base::prot_mem remains protected in Pub_Derv 
      int use_base() { return prot_mem; }
 };
  
 struct Derived_from_Private : public Priv_Derv {     
    
 };

struct Derived_from_Protected : public Prot_Derv {
    int use_base() { return prot_mem; }
};  

/************************************************************************************************************************************************************
 * Base *p = &d1; // d1 has type Pub_Derv      //  ok :  derived to base conversion in allowed in user code as Pub_Derv has derived from Base using public derivation specifier
 * p = &d2; // d2 has type Priv_Derv           //  error : d2 has derived from base using private derivation specifier, so user code has no access to derived to base conversion
 * p = &d3; // d3 has type Prot_Derv           //  error : protected derivation, so user code has no access to derived to base conversion
 * p = &dd1; // dd1 has type Derived_from_Public  //  ok : public derivation, so user code has access to derived to base
 * p = &dd2; // dd2 has type Derived_from_Private //  error : user code has no access to derived to base, direct base class of dd1 derived from base using private
 * p = &dd3; // dd3 has type Derived_from_Protected  //  error : user code has no access to derved to base conversion
 *************************************************************************************************************************************************************/

int main(){
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base *p = &d1;
    p = &d2;    error: cannot cast 'Priv_Derv' to its private base class 'Base'
    p = &d3;    error: cannot cast 'Prot_Derv' to its protected base class 'Base'
    p = &dd1;
    p = &dd2;   error: cannot cast 'Derived_from_Private' to its private base class 'Base'
    p = &dd3;   error: cannot cast 'Derived_from_Protected' to its protected base class 'Base

    return 0;
}
