/************************************************************************************************************************************************************
 * @file EX_12_12.cpp
 * @brief Exercise 12.12: Using the declarations of p and sp explain each of the following calls to process. If the call is 
 * legal, explain what it does. If the call is illegal, explain why:
 *          auto p = new int();
 *          auto sp = make_shared<int>();
 * (a) process(sp);
 * (b) process(new int());
 * (c) process(p);
 * (d) process(shared_ptr<int>(p));
 * 
 * @date 2024-01-16
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
/*
(a) process(sp);   : legal
        sp, a shared_ptr is passed to process, in the function the use_count will be 2, once function block ends the shared_ptr
        in process is destroyed, so after the control returns, use_count of sp will be 1.

(b) process(new int());   : illegal 
        built-in pointer cannot be implicitly converted to a shared_ptr, the call is in error 

(c) process(p);  : illegal  
        p is a buil-in pointer, implicit conversion from built-in pointer to shared_ptr is not possible. so the call is in error

(d) process(shared_ptr<int>(p));    :  legal
        temporary shared_ptr is created by using p, once the expression in which the call operator ends, the temporary shared_ptr
        will be destroyed, and the use_count will become zero, so the memory will be freed. But we still have p pointing to the 
        address freed, so p becomes a dangling pointer, the program is in serious bug, as dereferencing a dangling pointer is undefined
*/
