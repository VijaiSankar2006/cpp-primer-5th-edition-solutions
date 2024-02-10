/************************************************************************************************************************************************************
 * @file Ex_15_12.cpp
 * @brief Exercise 15.12: Is it ever useful to declare a member function as both override and final? Why or why 
 * not?
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * when a derived class wants to override a virtual function but at the same time if it doen't want the classes 
 * which inherits from it not to override the virtual function it can declare it as override and final together.
 *       override as it overrides the base class definition, final as no other class for which our derived class
 * is a base class cannot further override, they have to use our derived class definition.
 * 
 * struct b{
 *     virtual void foo();
 * };
 * 
 * struct d : public b{
 *      void foo() override final;  // ok : as foo is virtual in b, base class and no class which inherits from d can override foo
 * };
 * 
 * struct dd : public d{
 *      void foo() override;   //   error : foo is marked as final in d, which is the base class to dd  
 * }
 * 
 *************************************************************************************************************************************************************/

