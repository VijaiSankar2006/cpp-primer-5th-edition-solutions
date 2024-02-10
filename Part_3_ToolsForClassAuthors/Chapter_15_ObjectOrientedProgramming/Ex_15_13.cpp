/************************************************************************************************************************************************************
 * @file Ex_15_13.cpp
 * @brief Exercise 15.13: Given the following classes, explain each print function:
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * Exercise 15.13: Given the following classes, explain each print function:
 * class base {
 * public:
 *      string name() { return basename; }
 *      virtual void print(ostream &os) { os << basename; }
 * private:
 *      string basename;
 * };
 * 
 * class derived : public base {
 * public:
 *      void print(ostream &os) { print(os); os << " " << i; }   
 * private:                                                     
 *      int i;
 * };
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * As print() is a virtual function overriden in derived class, which version is called depends on the dynamic type 
 * when the call is made through a pointer or reference. But here print() is called on the implicit this pointer which 
 * results in recursive call leading to recursion loop. 
 *      We have to explicitly tell that we want base version by base name and scope resolution operator
 *  void print(ostream &os) { base::print(os); << " " << i; }  
 *************************************************************************************************************************************************************/



