/************************************************************************************************************************************************************
 * @file Ex_13_9.cpp
 * @brief Exercise 13.9: What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * destructor :
 *      A destructor does whatever is needed to free the resourses allocated by the object and destroys the non-static data members 
 * of the object. non-static members are destroyed in the reverse order to the initialisation order implicitly.
 *      it is a member function with name same as the class name preceeded by ~,tilde and empty parameter list, no return type
 * and a function body. It takes no parameters and returns nothing, so it cannot be overloaded. There is always only one destructor
 * defined in a class.
 *      class foo{
 *      public :
 *          ~foo(){}   //  destructor
 *      }
 * Synthesized destructor :
 *      Compiler synthesize a destructor for us when our class doesn't define it's own
 * It has a empty function body, it destroys all the non-static datamembers in the reverse order to the initialisation order implicitly
 * for members of string and other class type, their destructor is called to destroy
 * for built-in types, as they don't have destructors nothing is done
 * for pointer's of built-in type, object is not deleted, but for smart pointers, its destructor is run to destroy the object
 *************************************************************************************************************************************************************/

