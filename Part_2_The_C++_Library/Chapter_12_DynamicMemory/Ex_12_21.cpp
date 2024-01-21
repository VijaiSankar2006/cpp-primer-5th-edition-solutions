/************************************************************************************************************************************************************
 * @file Ex_12_22.cpp
 * @brief Exercise 12.21: We could have written StrBlobPtr’s deref member as follows:
 *          std::string& deref() const{ 
 *              return (*check(curr, "dereference past end"))[curr]; 
 *          }
 * Which version do you think is better and why?
 * @date 2024-01-18
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/*

version 1 :

std::string & StrBlobPtr::deref() const{
    auto sp = check(curr, "dereference past end");
    return (*sp)[curr];
}

-------------------------------------------
version 2 :

std::string& deref() const{ 
    return (*check(curr, "dereference past end"))[curr]; 
}
*/


//  version 1 is easy to understand to read, write and modify.
//  it is not a good idea to combine to different actions in one line.
//      - we check whether object is still valid, and dereference is with in bounds
//      - we return the element pointed by curr

