/************************************************************************************************************************************************************
 * @file Ex_15_20.cpp
 * @brief Exercise 15.20: Write code to test your answers to the previous two exercises.
 * @date 2024-02-04
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

class Base {
    public :  //  members, friends, all users - derived class, friends of derived class, general users              
        int pub_mem_base;      
    private :   //  members, friends only
        int pri_mem_base;
    protected : //  members, friends and "derived class can access through its object" 
        int pro_mem_base;
    friend void friend_of_Base(Base &b);
};

/*  when a derived class derives through public derivation from base, every member in base is treated like corresponding member in derived
 *  private of derived = private of derived + private of base
 *  public of derived = public of derived + public of base
 *  protected of derived = protected of derived + protected of base
 */
class Pub_Derv : public Base {
    public :
        int pub_mem_Pub_Derv;
        void access_base(Base &b){
            std::cout << b.pub_mem_base ;  //  ok : only public members can be accessed here, protected members can only be accessed through a derived class object 
            std::cout << pro_mem_base;     //  ok : this->pro_mem_base(accessing through derived class), but we cannot access b.pub_mem_base
        }                                       
    private :
        int pri_mem_Pub_Derv;
    protected :
        int pro_mem_Pub_Derv;
    friend void friend_of_Pub_Derv(Base &b, Pub_Derv &pd);
};

/* private derivation : all members of base resides as the private members of derived, 
 * (ie) when a derived object is constructed it has two parts : base subobject and derived subobject.
 * when derived class derives Base through private derivation, the entire base subobject resides in the private part of the desired subobject 
 * NOTE : Derivation access specifier only dictates the access to members and friends of classes which is derived out of this derived class
 * so the base class is private part of this class, who ever has access to the private member will have access to the base part. */
class Pri_Derv : private Base {
    public :
        int pub_mem_Pri_Derv;
        void access_base(Base &b){
            std::cout << b.pub_mem_base;    //  ok : public mem of base is accessible everyrwhere
            std::cout << pro_mem_base;      //  ok : this->pro_mem_base is accessible to the member of derived
        }
    private :
        int pri_mem_Pri_Derv;
    protected :
        int pro_mem_Pri_Derv;
    friend void friend_of_Pri_Derv(Base &b, Pri_Derv &p);
};

class Pro_Derv : protected Base {
    public :
        int pub_mem_Pro_Derv;
        void access_base(Base &b){
            std::cout << b.pub_mem_base;  // ok
            std::cout << pro_mem_base;    // ok : this->pro_mem_base;  
            //  pri_mem_base is not accessible, therefore a friend of this cannot access it
        }
    private :
        int pri_mem_Pro_Derv;
    protected :
        int pro_mem_Pro_Derv;
    friend void friend_of_Pro_Derv(Base &b, Pro_Derv &p);
};

/* when a class is derived from other, which itself is a derived class derived from another one, then
 * each class control access to its own members.4
 * private member : access to its own members and friend is provided
 * protected member : along with above two, derived class and its friends, and all the classes that derives further
 * from the derived class and friends of those classes has access but only through its own object.
 * (ie) for a derived class, it can access through this->pro_base, but not base.pro_base
 * (ie) for a derived_from_derived_class, it can access through this->pro_base, but not base.pro_base and derived.pro_base and not by friend
 * (ie) a protected member is protected by the derived object, so it can be accessed through this.
 */
class Derived_from_Pub_Der : public Pub_Derv {
    public :
        int pub_mem_Derived_Pub_Der;
        void access_bases(Base &b, Pub_Derv &p){
            std::cout << b.pub_mem_base;    // ok : public member can be accessed by everyone
            std::cout << p.pub_mem_Pub_Derv;  // ok : public member can be accessed by everyone
            std::cout << pro_mem_base;  //  ok : this->pro_mem_base can be accessed by this
        //  std::cout << p.pro_mem_base; // error : can be accessed by this or friend of this
        }

    private :
        int pri_mem_Derived_Pub_Der;
    protected :
        int pro_mem_Derived_Pub_Derv;
    friend void friend_of_Derived_from_Pub_Derv(Base &b, Pub_Derv &p, Derived_from_Pub_Der &dpd);
    //  a friend can access the pro_mem of direct base class only if variable name is used in the declaration
    //  (ie)absence of 'dpd' in declaration will give errors if we call pro_mem_Pub_Der.
};

class Derived_from_Pri_Der : public Pri_Derv {
    public :
        int pub_mem_Derived_Pri_Der;
        void access_bases(Pri_Derv &pd){
            // base object cannot be accessed here as it private even base.pub_mem cannot be accessed
            // no access pd.base_subobject as it is private in pd
            // no access to Pri_Der protected members

            std::cout << pro_mem_Pri_Derv;  //  ok : this->pro_mem_Pri_Derv
            std::cout << pub_mem_Pri_Derv;  //  ok : this->pub_mem_Pri_Derv
        }

    private :
        int pri_mem_Derived_Pri_Der;
    protected :
        int pro_mem_Derived_Pri_Derv;
    friend void friend_of_Derived_from_Pri_Der(Pri_Derv &pd, Derived_from_Pri_Der &dpd);
};

class Derived_from_Pro_Der : public Pro_Derv {
    public :
        int pub_mem_Derived_Pro_Der;
        void access_bases(Base &b, Pro_Derv &pd){
            std::cout << b.pub_mem_base;   //  ok : public member
            
            std::cout << pd.pub_mem_Pro_Derv; //  ok : public member

            std::cout << pub_mem_base;       // ok : public member
            std::cout << pro_mem_base;       //  ok : this->pro_mem_base   

            std::cout << pub_mem_Pro_Derv;   //   ok : public
            std::cout << pro_mem_Pro_Derv;   //   ok : thsi->pro_mem_Pro_Derv;
        }
    private :
        int pri_mem_Derived_Pro_Der;
    protected :
        int pro_mem_Derived_Pro_Derv;

    friend void friend_of_Derived_from_Pro_Derived(Base &b, Pro_Derv &pd, Derived_from_Pro_Der &dpd);
};

void friend_of_Base(Base &b){
    std::cout << b.pub_mem_base;  //   ok : friend to base can access all members of base
    std::cout << b.pro_mem_base;  //   ok : friend to base can access all members of base
    std::cout << b.pri_mem_base;  //   ok : friend to base can access all members of base
}

void friend_of_Pub_Derv(Base &b, Pub_Derv &pd){
    std::cout << b.pub_mem_base ;    // ok : only public member can be accessed here as Pub_Derv is a public derived from base

    std::cout << pd.pro_mem_base;    // ok : protected member can be accessed through derived object  

    std::cout << pd.pri_mem_Pub_Derv;   //  ok : friend of a class has access to all the objects members
    std::cout << pd.pub_mem_Pub_Derv;   //  ok : friend of a class has access to all the objects members
    std::cout << pd.pro_mem_Pub_Derv;   //  ok : friend of a class has access to all the objects members
}                                    


void friend_of_Pri_Derv(Base &b, Pri_Derv &p){
    std::cout << b.pub_mem_base;  // ok : base class has given access of public member of its object to everyone
    std::cout << p.pub_mem_base;  // ok : friend has access to all members of a class including private members
    std::cout << p.pro_mem_base;  // ok : friend can access, but b.pro_mem_base is not accessible.
}

void friend_of_Pro_Derv(Base &b, Pro_Derv &p){
    std::cout << b.pub_mem_base; //  ok : public member is accessible to all
    std::cout << p.pub_mem_base; //  ok : friend has access all members of a class
    std::cout << p.pro_mem_base; //  ok : friend has access to all members of a class   
}

void friend_of_Derived_from_Pub_Derv(Base &b, Pub_Derv &pd, Derived_from_Pub_Der &dpd){
    std::cout << b.pub_mem_base;  // ok : public member can be accessed by every one

    std::cout << pd.pub_mem_base; // ok : public member

    std::cout << dpd.pub_mem_base; // ok : public member, but not dpd.pro_mem_base

    std::cout << dpd.pub_mem_Pub_Derv; // ok : public member
    std::cout << dpd.pro_mem_Pub_Derv; // ok : pro_mem can be accessed by a friend

    std::cout << dpd.pub_mem_Derived_Pub_Der;
    std::cout << dpd.pro_mem_Derived_Pub_Derv;
    std::cout << dpd.pro_mem_Derived_Pub_Derv;
}

void friend_of_Derived_from_Pri_Der(Pri_Derv &pd, Derived_from_Pri_Der &dpd){
    //  base object independent or subobject of direct base class, as the derivation is private, no access to friend
    //  (ie) all members of base are redeclared as private to this and its friends
    std::cout << pd.pub_mem_Pri_Derv;
   
    std::cout << dpd.pub_mem_Pri_Derv;
    std::cout << dpd.pro_mem_Pri_Derv;

    std::cout << dpd.pro_mem_Derived_Pri_Derv;
    std::cout << dpd.pub_mem_Derived_Pri_Der;
    std::cout << dpd.pri_mem_Derived_Pri_Der;
 }

void friend_of_Derived_from_Pro_Derived(Base &b, Pro_Derv &pd, Derived_from_Pro_Der &dpd){
    std::cout << b.pub_mem_base;   //  ok : protected member of direct base class
            
    std::cout << pd.pub_mem_Pro_Derv; //  ok : public member
            
    std::cout << dpd.pub_mem_base;       // ok : public member
    std::cout << dpd.pro_mem_base;       //  ok : this->pro_mem_base   

    std::cout << dpd.pub_mem_Pro_Derv;   //   ok : public
    std::cout << dpd.pro_mem_Pro_Derv;   //   ok : thsi->pro_mem_Pro_Derv;
}   

int main(){

}