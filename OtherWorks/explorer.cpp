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
#include <fstream>
#include <set>

namespace fs = std::filesystem;
void displayDirectory(const fs::path &curr, std::ostream &os, size_t level = 0);

int main() {
    std::ofstream ofile("index.html");
    
    fs::path curr("/home/vijai/cpp_projects/c++_primer_github");
    ofile << "displaying contents of : " << curr << std::endl;
    displayDirectory(curr, ofile);

    return 0;
}

void displayDirectory(const fs::path &curr, std::ostream &os, size_t level) {
    std::set<std::string> dirlst;
    for(auto iter = fs::directory_iterator(curr); iter != fs::directory_iterator(); ++iter) {
        if (fs::is_directory(*iter)) {
            std::string fname = iter->path().filename();
            if (fname != ".vscode" && fname != ".git") {
                dirlst.insert(fname);
                displayDirectory(*iter, os, level + 1);
            }    
        } else if (fs::is_regular_file(*iter)) {
            //ofile << iter->path().filename() << " " << iter->file_size() << std::endl;
        }
    }

    for (auto &s : dirlst) {
        os << std::string(level * 3, ' ') << "[+]" << s << std::endl; 
    } 
}
