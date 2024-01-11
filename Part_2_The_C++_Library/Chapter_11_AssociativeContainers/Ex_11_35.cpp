/************************************************************************************************************************************************************
 * @file Ex_11_35.cpp
 * @brief Exercise 11.35: In buildMap, what effect, if any, would there be from rewriting 
 *          trans_map[key] = value.substr(1); 
 *          as 
 *          trans_map.insert({key, value.substr(1)})?
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/**
 *  trans_map[key]          // fetches the value associated with key if key not found new element with key will be added and the value will be returned
 *      = value.substr(1)   //  assigns substr with out 1st letter to the value
 * 
 * trans_map.insert({key, value.substr(1)})  // insert inserts the key-value pair in to the map if and only if key is not already present
 *                                           // or else it does nothing
 * 
 * 1st case : if the key is repeated, then the last abbrevation will be the one present in the map
 * 2nd case : if the key is repeated, then the first abbrevation will be the one present in the map
 *  
*/