/************************************************************************************************************************************************************
 * @file Ex_16_48.cpp
 * @brief Exercise 16.48: Write your own versions of the debug_rep functions.
 * @date 2024-02-15
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <sstream>

/**
 * @brief declaration is nedded before template definition or else template version will be instantiated.
 * declarations of all non-template overloads should be placed above template overload to make sure those non-template
 * overloads are considered for function matching 
 */
std::string debug_rep(const std::string &);

/**
 * @brief template overload of debug_rep that can called with any object including const & as reference to pointers
 * @tparam T 
 * @param const &val 
 * @return std::string
 */
template <typename T>
std::string debug_rep(const T &val) {
    std::ostringstream ret;
    ret << val;

    return ret.str();
} 

/**
 * @brief template overload of debug_rep that can only be called with a pointer, const or non-const
 * @tparam T
 * @param *p
 * @return std::string
 */
template <typename T> 
std::string debug_rep(T *p) {
    std::ostringstream ret;
    if(p) {
        ret << p << " " << debug_rep(*p);
    } else {
        ret << "null pointer" << " ";
    }

    return ret.str();
} 

/**
 * @brief overload of debug_rep that get the string to be printed in double quoutes.
 * @param const std::string &
 * @return std::string
 */
std::string debug_rep(const std::string &s) {
    return '"' + s + '"';
}

/**
 * @brief non-template overload of debug_rep to print char * as string
 * @param char *
 * @return std::string
 */
std::string debug_rep(char *p) {
    std::string str(p);
    return debug_rep(&str);
}

/**
 * @brief non-template overload of debug_rep to print const char * as string
 * @param const char * 
 * @return std::string
 */
std::string debug_rep(const char *p) {
    const std::string str(p);
    return debug_rep(&str);
}


