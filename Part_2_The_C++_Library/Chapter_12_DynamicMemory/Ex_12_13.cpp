/************************************************************************************************************************************************************
 * @file Ex_12_13.cpp
 * @brief Exercise 12.13: What happens if we execute the following code?
 *          auto sp = make_shared<int>();
 *          auto p = sp.get(); 
 *          delete p;
 * @date 2024-01-16
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
/*
auto sp = make_shared<int>(); - sp is a shared_ptr pointing to an int initialised using make_shared function
auto p = sp.get();            - p is a built-in ptr initialised with built-in ptr returned from sp.get()
delete p;                     - destroys the object pointed by p and frees the memory, which makes sp a dangling ptr 
                                the program might have undefined behaviour

*/