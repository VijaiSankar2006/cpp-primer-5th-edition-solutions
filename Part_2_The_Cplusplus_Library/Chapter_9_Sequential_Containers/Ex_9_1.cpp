/************************************************************************************************************************************************************
 * @file Ex_9_1.cpp
 * @brief Exercise 9.1: Which is the most appropriate—a vector, a deque, or a list—for the following program tasks? Explain the
 *        rationale for your choice. If there is no reason to prefer one or another container, explain why not.
 *          (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll 
 *              see in the next chapter that associative containers are better suited to this problem.
            (b) Read an unknown number of words. Always insert new words at the back.Remove the next value from the front.
            (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/**
 * (a) list - is better suited as to add words in the container alphabetically as they are entered, we should be able to insert
 *            the word before the word which comes alphabetically next, or after another which comes first, so we need insertion
 *            at any where in the container and we also need bidirectional access in the container.
 *            Other containers like vector or deque will have poor performance when it comes to insertion at middle
 * (b)  deque - is better suited as a new word added is always at the back and next word removed is always at the front, which 
 *            is simply representing deque container which has implementd FIFO( First In First Out), that is the first element
 *            added will be the first one to be removed, 
 *            Removing first from a vector will require moving all the rest of the elements one step forward, so each insertion 
 *            will be time consuming
 *            list consumes lot of storage compared to deque and vector, as to implement faster insertion in the middle
 * (c) vector - it is much efficient to store the elements in a vector and sort it with the library sort method than using 
 *            any other container
 * 
*/