/************************************************************************************************************************************************************
 * @file singly_linked_lst.cpp
 * @brief just a simple implementation of singly_linked_list
 * @date 2024-02-26
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#include <iostream>
#include <memory>

template <typename T>
struct node {
    T data;
    node * next = nullptr;
    static size_t size;
};

template <typename T>
size_t node<T>::size = 0;

template <typename T>
void print(const node<T> *current) {
    while(current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void insert(node<T> *current, T const &val, size_t pos) {
    if(pos >= current->size) {
        std::cout << "out of bounds" << std::endl;
        return;
    }

    for(size_t i = 0; i < pos; ++i) {
        current = current->next;
    }

    auto *p = new node<T>({val});
    p->next = current->next;
    current->next = p;
    ++current->size;
}

template <typename T>
void remove(node<T> *current, size_t pos) {
    if(pos >= current->size) {
        std::cout << "out of bounds" << std::endl;
        return;
    }

    for(size_t i = 0; i < pos; ++i) {
        current = current->next;
    }

    auto *p = current->next;
    current->next = p->next;
    --current->size;
    delete p;
}

/*
int main() {
    node<std::string> *first = new node<std::string>({"hello world"});
    ++first->size;
    
    node<std::string> *current = first;
    for(size_t i = 0; i != 10; i++) {
        auto *p = new node<std::string>({std::to_string(i)});
        current->next = p;
        current = current->next;
        ++current->size;
    }

    print(first);
    insert(first, std::string("middle"), 11);
    print(first);
    remove(first, 7);
    print(first);
    std::cout << "size of list : " << first->size << std::endl;
    return 0;
}
*/