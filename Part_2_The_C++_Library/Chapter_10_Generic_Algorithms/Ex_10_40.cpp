/************************************************************************************************************************************************************
 * @file Ex_10_40.cpp
 * @brief Exercise 10.40: What kinds of iterators do you think copy requires? What about reverse or unique?
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

copy : reads elements one after another from a sequence and writes to a container, assumes the destination sequence is large enough as source container
       read - input iterator atleast
       write - output iterator atleast
    
reverse : bidirectional iterator atleast

unique : forward iterator atleast