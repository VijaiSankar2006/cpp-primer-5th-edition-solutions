/************************************************************************************************************************************************************
 * @file Ex_16_49.cpp
 * @brief Explain what happens in each of the following calls:
 * template <typename T> void f(T);
 * template <typename T> void f(const T*);
 * template <typename T> void g(T);
 * template <typename T> void g(T*);
 * int i = 42, *p = &i;
 * const int ci = 0, *p2 = &ci;
 * g(42); g(p); g(ci); g(p2);
 * f(42); f(p); f(ci); f(p2);
 * @date 2024-02-15
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 template <typename T> void f(T);
 template <typename T> void f(const T*);
 template <typename T> void g(T);
 template <typename T> void g(T*);
 int i = 42, *p = &i;
 const int ci = 0, *p2 = &ci;
 a) g(42);
    void g(int), T is deduced a int, is instantiated. 
    As there is no other calls, void g(int) is used with T as int

 b) g(p);
    void g(int *), T is int *, is instantiated 
    void g(int *), T is int , is instantiated
    Both template instantiations provides equally good matches.
    When template instantiations provides equally good matches, more specialised version is used
    In this case, 1st template can be called with any type, but 2nd template can be called with only pointers.
    So instantiation from the 2nd template is used, (ie) void g(T *) with T as int

 c) g(ci) 
    void g(int), T is int , is instantiated, top level const ignored
    As there is no other calls, void g(int) is used with T as int

 d) g(p2);
    void g(const int *), T is const int *, is instantiated
    void g(const int *), T is const int, is instantiated
    As Both instantiations provide equally good matches, more specialised one is choosen.
    1st template can be called with any type, but 2nd can be called with only pointers.
    so 2nd template is used, (ie) void g(T *) with T as const int

 e) f(42);
    void f(int), T is int, is instantiated
    void f(int) is used as there is no other overloaded calls

 f) f(p);
    void f(int *), T is int *, is instantiated
    void f(const int *), T is int, is instantiated
    second version requires const conversion,so void f( int *) is used with T as int *

 g) f(ci);
    void f(int ), T is int, is instantiated.
    void f(int ) is used

 h) f(p2);
    void f(const int *), T is const int *, is instantiated.
    void f(const int *), T is int is instantiated
    more specialised version is used, void f(const T *) is used with T as int.

 *************************************************************************************************************************************************************/