/************************************************************************************************************************************************************
 * @file explorer.cpp
 * @brief code to learn to use std::filesystem
 * @date 2024-03-22
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::cout << "ls :" << std::endl;
    fs::path curr("/home/vijai/cpp_projects/c++_primer_github");
    for( const auto &entry : fs::recursive_directory_iterator(curr, fs::directory_options::follow_directory_symlink)) {
        if (fs::is_directory(entry)) {
            std::cout << "[+]" << entry.path().filename() << std::endl; 
        } else if (fs::is_regular_file(entry)) {
            std::cout << entry.path().filename() << " " << entry.file_size() << std::endl;
        }
    }
    return 0;
}

