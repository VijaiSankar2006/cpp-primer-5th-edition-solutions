/************************************************************************************************************************************************************
 * @file Ex_16_36.cpp
 * @brief Exercise 16.36: What happens in the following calls:
 * template <typename T> f1(T, T);
 * template <typename T1, typename T2) f2(T1, T2);
 * int i = 0, j = 42, *p1 = &i, *p2 = &j;
 * const int *cp1 = &i, *cp2 = &j;
 * (a) f1(p1, p2); (b) f2(p1, p2); (c) f1(cp1, cp2);
 * (d) f2(cp1, cp2); (e) f1(p1, cp1); (f) f2(p1, cp1);
 * @date 2024-02-13
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * template <typename T> f1(T, T);                    //  return type and function body is needed
 * template <typename T1, typename T2) f2(T1, T2);    //  return type and function body is needed
 * int i = 0, j = 42, *p1 = &i, *p2 = &j;
 * const int *cp1 = &i, *cp2 = &j;
 * (a) f1(p1, p2);  // both arguments are of same type, int *, so f1<int *>(int *, int *) will be instantiated with int * replacing T
 * (b) f2(p1, p2);  // though both arguments are same, still f2<int *, int *>(int *, int *) can be instantiated with int * replacing T1 and int * replcaing T2 
 * (c) f1(cp1, cp2);  // both arguments are of same type, pointer to const int, so f1<const int *>(const int *, const int *) will be instantiated by replacing T with const int *
 * (d) f2(cp1, cp2);  // though both argumenets are same type, stll f2<const int *, const int *>(const int *, const int *) will be instantiated with T1 as const int * and T2 const int *
 * (e) f1(p1, cp1);   // illegal : arguments are different types, 1st arg is int * and 2nd arg is const int *, so this call is in error
 * (f) f2(p1, cp1);   // arguments are of different types, so T1 will be deduced as int * and T2 will be deduced as const int *, f2<int *, const int *>(int *, const int *) will be instantiated
 *************************************************************************************************************************************************************/

#include <iostream>

template <typename T> void f1(T, T) {}
template <typename T1, typename T2> void f2(T1, T2) {}

int main() {

    int i = 0, j = 42, *p1 = &i, *p2 = &j;
    const int *cp1 = &i, *cp2 = &j;
    f1(p1, p2);
    f2(p1, p2); 
    f1(cp1, cp2);
    f2(cp1, cp2);
  //  f1(p1, cp1); 
    f2(p1, cp1);

    return 0;
}