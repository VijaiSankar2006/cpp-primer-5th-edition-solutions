<h1 style = "text-align : center; color : grey">MyProject</h1>

This projects contains the following *types* which imitates the *corresponding library types* and a simple **Relational Database System**
* smart_pointer
* string
* vector
* array
* list
* queue
* deque
* stack

*The word "pvt" preceeds every type name to distinguish itself from library types for the readers*

# pvt Smart Pointer templates 
These behave similar to library smart pointers.
* pvtshared_ptr 
* pvtunique_ptr
* pvtmake_shared
* pvtmake_unique

#### Operations that are common to pvtshared_ptr and pvtunique_ptr
    pvtshared_ptr<T> sp     Null shared pointer that can point to objects of type T.
    pvtunique_ptr<T> up     Null unique pointer that can point to objects of type T.
    p                       Use p as a condition; true if p points to an object, false if it is null ptr.
    *p                      Dereference p to get the object to which p points, yields lvalue reference.
    p->mem                  Synonym for (*p).mem
    p.get()                 Returns the pointer in p, but the object to which it points get deleted when smart pointer is deleted.
    swap(p,q)               swaps the pointer in p and q, a non-member function
    p.swap(q)               member function

## pvtsmart_ptr 
pvtsmart_pointer is the base class template which will handle all the common operations to both the smart pointers.
