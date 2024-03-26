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
#include <map>
#include "pause.cpp"

namespace fs = std::filesystem;
class Directory {
    friend std::ostream & operator<<(std::ostream &os, Directory &dir);
    public : 
        explicit Directory(const fs::path &curr_, size_t indent_ = 0) : curr(curr_), indent(indent_){
            for(auto iter = fs::directory_iterator(curr); iter != fs::directory_iterator(); ++iter) {
                std::string fname = iter->path().filename();
                if (fs::is_directory(*iter)) {
                        dir_list[iter->path()] = new Directory(iter->path(), indent + 1);
                } else if (fs::is_regular_file(*iter)) { 
                        file_list.insert(iter->path());
                }
            }
        }

        void set_exclude_extension(const std::initializer_list<std::string> &il) {
            for (auto s : il) {
                exclude_extensionlist.insert(s);
            }
        }

        const std::set<std::string> & get_exclude_extensionlist() {
            return exclude_extensionlist;
        }

        void set_exclude_dir(const std::initializer_list<std::string> &il) {
            for (auto s : il) {
                exclude_dirlist.insert(s);
            }
        }

        void set_exclude_file(const std::initializer_list<std::string> &il) {
            for (auto s : il) {
                exclude_filelist.insert(s);
            } 
        }

        const std::set<std::string> & get_exclude_dir() {
            return exclude_dirlist;
        }

        const std::set<std::string> & get_exclude_file() {
            return exclude_filelist;
        }

        ~Directory() {
            for(auto p : dir_list) {
                delete p.second;
            }
        }

    private :
        fs::path curr;
        size_t indent;
        std::set<fs::path> file_list;
        std::map<fs::path, Directory *> dir_list;
        static std::string hyperlink(const fs::path &p);
        static std::set<std::string> exclude_dirlist;
        static std::set<std::string> exclude_filelist;
        static std::set<std::string> exclude_extensionlist;
};

std::set<std::string> Directory::exclude_dirlist;
std::set<std::string> Directory::exclude_filelist;
std::set<std::string> Directory::exclude_extensionlist;
std::string Directory::hyperlink(const fs::path &p) {
    return std::string("<a href = \"") + std::string(fs::relative(p)) + "\">" + std::string(p.filename()) + "</a>"; 
}

std::ostream & operator<<(std::ostream &os, Directory &dir) {
    std::string indent_str(dir.indent * 3, ' ');
    for (auto p : dir.file_list) {
        if (dir.exclude_filelist.find(p.filename()) == dir.exclude_filelist.end() 
            && dir.exclude_extensionlist.find(p.extension()) == dir.exclude_extensionlist.end()) {     
            os << indent_str << dir.hyperlink(p) << std::endl;
        }    
    }   

    for (auto p : dir.dir_list) {
        if (dir.exclude_dirlist.find(p.first.filename()) == dir.exclude_dirlist.end()) {
            os << indent_str << "[+] " << dir.hyperlink(p.first) << std::endl;
            os << *p.second;
        }        
    }
    
    return os;
}    

int main() {
    std::ofstream ofile("/home/vijai/cpp_projects/c++_primer_github/index.html");
    
    fs::path curr("/home/vijai/cpp_projects/c++_primer_github");
    std::cout << "displaying contents of : " << curr << std::endl;
    Directory d1(curr);
    d1.set_exclude_dir({".git", ".vscode"});
    d1.set_exclude_extension({".exe"});
    d1.set_exclude_file({"rooster"});
    ofile << "<pre>"; 
    ofile << d1 << std::endl;
    ofile <<"</pre>";

    return 0;
}
