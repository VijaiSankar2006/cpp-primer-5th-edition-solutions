/************************************************************************************************************************************************************
 * @file Ex_16_23.cpp
 * @brief Exercise 16.23: Predict when the call operator will be executed in your main query program. If your expectations
 * and what happens differ, be sure you understand why.
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * At end of the main function our TextQuery object gets deleted which calls the destructor of shared_ptr for both file_vector
 * and word_map, which executes the call operator of our DebugDelete which in-turn deletes the pointer.
 *************************************************************************************************************************************************************/