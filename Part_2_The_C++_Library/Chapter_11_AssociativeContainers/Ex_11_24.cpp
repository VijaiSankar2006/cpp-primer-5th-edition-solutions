/************************************************************************************************************************************************************
 * @file Ex_11_24.cpp
 * @brief Exercise 11.24: What does the following program do?
 *          map<int, int> m;
 *          m[0] = 1;
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

map<int, int> m;    // creates a map type m with int to int
m[0] = 1    // searches m for key 0, if not present inserts a key-value pair with 0 as key and value value-initialised to 0
            // returns the element to which 1 is assigned to its value