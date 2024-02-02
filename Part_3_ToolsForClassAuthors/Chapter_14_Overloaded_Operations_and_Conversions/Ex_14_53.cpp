/************************************************************************************************************************************************************
 * @file Ex_14_53.cpp
 * @brief Exercise 14.53: Given the definition of SmallInt on page 588, determine whether the following addition 
 * expression is legal. If so, what addition operator is used? If not, how might you change the code to make it
 * legal? SmallInt s1;
 * double d = s1 + 3.14;
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * class SmallInt {
 * friend SmallInt operator+(const SmallInt&, const SmallInt&);
 * public:
 *      SmallInt(int = 0); // conversion from int
 *      operator int() const { return val; } // conversion to int
 * private:
 *      std::size_t val;
 * };
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * SmallInt s1;
 * double d = s1 + 3.14;  
 * //   call is ambiguous as s1 has a conversion operator to int and also has a conversion constructor taking int.
 * //   both are equaly good, so the call is in error
 *************************************************************************************************************************************************************/