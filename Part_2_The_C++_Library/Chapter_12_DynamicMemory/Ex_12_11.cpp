/************************************************************************************************************************************************************
 * @file Ex_12_11.cpp
 * @brief Exercise 12.11: What would happen if we called process as follows?
 *          process(shared_ptr<int>(p.get()));
 * @date 2024-01-16
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * temporary shared_ptr will be independently initialised with built-in ptr returned by p.get().
 * though both p and temp shared_ptr points to the same address, they are independent of each other, both will have use_count 1
 * once the process function ends, the temp shared_ptr will be deleted as the use_count becomes 0, the memory will be freed
 * As a result, p will become dangling pointer, as it points to a address that's freed
 * 
 *************************************************************************************************************************************************************/

