/************************************************************************************************************************************************************
 * @file Ex_15_23.cpp
 * @brief Exercise 15.23: Assuming class D1 on page 620 had intended to override its inherited fcn function, how 
 * would you fix that class? Assuming you fixed the class so that fcn matched the definition in Base, how would
 *  the calls in that section be resolved?
 * @date 2024-02-05
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

class Base {
    public:
        virtual int fcn();
};

class D1 : public Base {
    public:
        int fcn() override ; //overrides virtual fcn from Base
        int fcn(int); // overloaded fcn 
        virtual void f2(); // new virtual function that does not exist in Base
};

class D2 : public D1 {
    public:
        int fcn(int); // nonvirtual function hides D1::fcn(int)
        int fcn(); // overrides virtual fcn from D1 
        void f2(); // overrides virtual f2 from D1
};

int main()
{
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;

    bp1->fcn(); // virtual call, will call Base::fcn at run time
    bp2->fcn(); // virtual call, will call D1::fcn at run time
    bp3->fcn(); // virtual call, will call D2::fcn at run time

    D1* d1p = &d1obj;
    D2* d2p = &d2obj;
 //   bp2->f2(); // error: Base has no member named f2
    d1p->f2(); // virtual call, will call D1::f2() at run time
    d2p->f2();  // virtual call, will call D2::f2() at run time
}