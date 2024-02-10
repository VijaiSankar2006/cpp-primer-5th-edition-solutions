/************************************************************************************************************************************************************
 * @file Ex_15_38.cpp
 * @brief Exercise 15.38: Are the following declarations legal? If not, why not? If so, explain
 * what the declarations mean.
 * BinaryQuery a = Query("fiery") & Query("bird");
 * AndQuery b = Query("fiery") & Query("bird");
 * OrQuery c = Query("fiery") & Query("bird");
 * @date 2024-02-07
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * BinaryQuery a = Query("fiery") & Query("bird");  // illegal : BinaryQuery is an abstract class, so we cannot create an object, it can only be constructed as a part of derived object
 * AndQuery b = Query("fiery") & Query("bird");  // legal : & operator returns a AndQuery object which will be used to synthesised copy_construct AndQuery b
 * OrQuery c = Query("fiery") & Query("bird");  // Illegal : OrQuery object cannot be copy_constructed from a AndQuery object
 * 
 *************************************************************************************************************************************************************/