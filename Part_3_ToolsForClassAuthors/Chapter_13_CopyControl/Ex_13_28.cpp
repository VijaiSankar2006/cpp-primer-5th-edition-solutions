/************************************************************************************************************************************************************
 * @file Ex_13_28.cpp
 * @brief Exercise 13.28: Given the following classes, implement a default constructor and the necessary copy-control members.
 *  (a) class TreeNode {            (b) class BinStrTree {
 *      private:                        private:
 *          std::string value;              TreeNode *root;
 *          int count;                  };
 *          TreeNode *left;
 *          TreeNode *right;
 *      };
 * @date 2024-01-24
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
// yet to be writen

#include <iostream>
#include <memory>
#include <string>

class TreeNode {
public :
    TreeNode() : count(1), left(new TreeNode), right(new TreeNode) {}
    TreeNode(const TreeNode &source) : value(source.value), count(source.count), left(source.left), right(source.right) {}
    TreeNode & operator=(const TreeNode &rhs){
        std::string value_copy = rhs.value;
        int count_copy = rhs.count;
        TreeNode *left_copy = rhs.left;
        TreeNode *right_copy = rhs.right;
        delete left;
        delete right;
        value = value_copy;
        count = count_copy
        left = left_copy
    }
private :
    std::string value;              
    int count;                  
    TreeNode *left;
    TreeNode *right;

}