/************************************************************************************************************************************************************
 * @file Ex_15_14.cpp
 * @brief Exercise 15.14: Given the classes from the previous exercise and the following objects, determine which
 *  function is called at run time:
 * base bobj; base *bp1 = &bobj; base &br1 = bobj;
 * derived dobj; base *bp2 = &dobj; base &br2 = dobj;
 * (a) bobj.print(); (b) dobj.print(); (c) bp1->name();
 * (d) bp2->name(); (e) br1.print(); (f) br2.print();
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
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
 *      void print(ostream &os) { print(os); os << " " << i; }   //  base::print(os);
 * private:                                                     
 *      int i;
 * };
 *  
 * base bobj; base *bp1 = &bobj; base &br1 = bobj;
 * derived dobj; base *bp2 = &dobj; base &br2 = dobj;
 * 
 * (a) bobj.print();   //  base::print()  is called  
 * (b) dobj.print();   //  derived::print() is called
 * (c) bp1->name();    //  base::name() is called 
 * (d) bp2->name();    //  base::name(), as it is not virtual function, derived class inherits the function as it is 
 * (e) br1.print();    //  base::print() is called
 * (f) br2.print();    //  derived::print() is called 
 *************************************************************************************************************************************************************/

