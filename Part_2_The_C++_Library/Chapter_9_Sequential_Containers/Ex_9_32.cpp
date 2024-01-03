/************************************************************************************************************************************************************
 * @file Ex_9_32.cpp
 * @brief Exercise 9.32: In the program onpage 354 would it be legal to write the call to insert as follows? If not, why not?
 *        iter = vi.insert(iter, *iter++);
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/**
 * we have no idea about the order in which the arguments will be passed, so it can be
 *  (iter + 1) = vi.insert((iter + 1), *iter)
 *  or
 *  (iter + 1) = v1.insert(iter, *(iter + 1));
 *  or
 *  iter = v1.insert((iter +1 ), *iter) or it can be another
 *  so we should not mix 
 *  changing the state of the variable and referencing in the expression
*/