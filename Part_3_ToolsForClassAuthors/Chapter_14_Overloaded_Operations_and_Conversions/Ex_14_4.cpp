/************************************************************************************************************************************************************
 * @file Ex_14_4.cpp
 * @brief Exercise 14.4: Explain how to decide whether the following should be class members:
 * (a) % (b) %= (c) ++ (d) -> (e) << (f) && (g) == (h) ()
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * (a) %      //  returns the reminder, when lhs is divided by rhs, no class can have meaningful way of division, in case if it is meaninng full
 *                as this is a symmetrical operator it should be defined as non-member of class    
 * (b) %=     //  assigns the reminder of lhs/rhs to lhs, as it assigns the result to lhs it should be defined as non-member function  
 * (c) ++     //  increments by one, iterators defines them to point the next one in the sequence, it takes one operand, so it has to be defined
 *                as member function  
 * (d) ->     //  member access operator,   
 * (e) <<     //  output stream operator, should be defined has non-member funtion, as it's left operand is output stream operator, to call memberfunction
 *                left operand should be class type  
 * (f) &&     //  true if both operand are true, symmetrical operator, so should be defined as non-member type  
 * (g) ==     //  equality of both operands, symmetrical operator, should be defined as non-member type  
 * (h) ()     //  single operand, so should be defined as member, will make the object callable  
 * 
 *************************************************************************************************************************************************************/