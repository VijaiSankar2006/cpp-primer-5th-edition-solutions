/************************************************************************************************************************************************************
 * @file Ex_11_33.cpp
 * @brief Exercise 11.33: Implement your own version of the word-transformation program.
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

void wordTransformation(std::ifstream &abbr, std::ifstream &msg);
std::map<std::string, std::string> buildMap(std::ifstream &abbr);
const std::string & transform(const std::string &word, const std::map<std::string, std::string> &m);

int main(int argc, char **argv){
    std::ifstream abbr(*(argv + 1));
    if(!abbr){
        std::cerr << "Unable to open file : " << *(argv + 1) << std::endl;
    }

    std::ifstream msg(*(argv + 2));
    if(!msg){
        std::cerr << "Unable to open file : " << *(argv + 2) << std::endl;
    }

    wordTransformation(abbr, msg);
}

void wordTransformation(std::ifstream &abbr, std::ifstream &msg){
    auto wordMap = buildMap(abbr);

    std::string line;
    std::string word;
    while(getline(msg, line)){
        std::istringstream linestrm(line);
        bool firstWord = true;
        while(linestrm >> word){
            if(firstWord){
                firstWord = false;
            }else{
                std::cout << " ";
            }
            std::cout << transform(word, wordMap);
        }
        std::cout << std::endl;
    }
}

std::map<std::string, std::string> buildMap(std::ifstream &abbr){
    std::map<std::string, std::string> m;
    std::string line;
    std::string word;
    std::string phrase;

    while(abbr >> word && getline(abbr, line)){
        if(line.size() > 1){
            phrase = line.substr(1);
        }else{
            phrase = word;  //  assigns the word itself if no abbrevation is found
        }
        m[word] = phrase;
    }

    return m;
}

const std::string & transform(const std::string &word, const std::map<std::string, std::string> &m){
    std::map<std::string, std::string>::const_iterator p = m.find(word);
    if(p != m.end()){
        return  p->second;
    }

    return word;
}
