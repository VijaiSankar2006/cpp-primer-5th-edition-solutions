/************************************************************************************************************************************************************
 * @file Ex_13_33.cpp
 * @brief Exercise 13.33: Why is the parameter to the save and remove members of Message a Folder&? Why didn’t we define that
 * parameter as Folder? Or const Folder&?
 * @date 2024-01-24
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * save function adds a pointer to the folder so it needs to be a reference or else we will be adding a temp and folder added
 * need to add the message, if it is non-reference type then again message will be added to temp which gets destroyed at end of
 * the save function
 * delete needs to delete the pointer, so we need a reference to the folder and folder needs delete the message, so it needs 
 * to be a reference or else we will try to delete a temporary and ask the temporary to delete the msg which is of no use
 * 
 *************************************************************************************************************************************************************/