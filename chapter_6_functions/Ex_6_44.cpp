//Exercise 6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline

#include <iostream>

inline bool isShorter(const std::string &s1, const std::string &s2){
    return s1.size() < s2.size();
}

int main(){
    bool shorter = isShorter("hello","hello world");
    std::cout << shorter << std::endl;
    const std::string str1{"timmoty"};

    std::string str2{"small"};
    std::cout << isShorter(str1, "zebra") << std::endl;
    
    return 0;
}