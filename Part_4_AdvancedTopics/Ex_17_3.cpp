/************************************************************************************************************************************************************
 * @file Ex_17_3.cpp
 * @brief Exercise 17.3: Rewrite the TextQuery programs from § 12.3 (p. 484) to use a tuple instead of the QueryResult
 * class. Explain which design you think is better and why.
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <tuple>

using std::tuple; using std::vector; using std::string; using std::shared_ptr; using std::map; using std::set; using std::get;
class TextQuery;
typedef std::tuple<string, shared_ptr<vector<string>>, shared_ptr<map<string, set<size_t>>>, vector<set<size_t>::iterator>> QueryResult;
class TextQuery{
    public :
        typedef std::vector<std::string>::size_type index_type;

        TextQuery(std::ifstream &ifile);  //  constructor that takes a filestrm object
        inline QueryResult query(const std::string & word) const ;  //  queries the text
        inline void debug() const;

    private :
        std::shared_ptr<std::vector<std::string>> text;  //  contains the text from the file
        std::shared_ptr<std::map<std::string, std::set<index_type>>> word_map;  //  contains each word in the file and line numbers they appear 
        void ignoreCase(std::string &word);
};

TextQuery::TextQuery(std::ifstream &ifile){
    //  code to dynamicaly allocate memory
    text = std::make_shared<std::vector<std::string>>();    // text is allocated memory and initialised with empty vector of strings
    word_map = std::make_shared<std::map<std::string, std::set<index_type>>>();  // word_map is allocated memory and initialised with empty map

    std::string line;
    index_type line_no = 0;
    while(getline(ifile, line)){  //  extracts one line at a time from the file
        std::istringstream linestrm(line);
        std::string word;
        text->push_back(line);  //  each line is added as a seperate element in the vector 

        while(linestrm >> word){
            ignoreCase(word);   //  changes all the letters to lowercase so "as" and "As" will be considered as same words
            (*word_map)[word].insert(line_no);  //  map is subscripted with word, and corresponding line_no is added to set returned
        }

        ++line_no;
        line.clear();  //  to clear the eof 
    }
}

void TextQuery::debug() const {  
    //  prints the vector that contains the file
    std::cout << "the text from the file as follows..........." << std::endl;
    for(auto iter = text->cbegin(); iter != text->cend(); ++iter){
        std::cout << *iter << std::endl;
    }

    //  prints the word_map of the file
    std::cout << "\nword map builded out of text is as follows.........." << std::endl;
    for(auto iter = word_map->cbegin(); iter != word_map->cend(); ++iter){
        std::cout << iter->first << " [" ;
        for(auto beg = iter->second.cbegin(); beg != iter->second.cend(); ++beg){
            std::cout << *beg << " ";
        }    
        std::cout << "]" << std::endl;
    }
}

void TextQuery::ignoreCase(std::string &word){
    for(std::string::size_type i = 0; i != word.size(); ++i){
        word[i] = tolower(word[i]);
    }
}


QueryResult TextQuery::query(const std::string &word) const {
    std::vector<std::set<TextQuery::index_type>::iterator> lines;
    auto res_iter = word_map->find(word);
    
    if(res_iter != (word_map->cend())){
         for( auto iter = res_iter->second.begin(); iter != res_iter->second.end(); ++iter){
            lines.push_back(iter);
         }
    }

    return QueryResult(word, text, word_map, lines);
}


std::ostream & print(std::ostream &out,const QueryResult qr){
    if(get<3>(qr).empty()){
        out << get<0>(qr) << " not found in the text" << std::endl;
    }else{
        out << get<0>(qr) << " found in the following lines........\n" << std::endl;
        for(auto iter = get<3>(qr).begin(); iter != get<3>(qr).end(); ++iter){  
            TextQuery::index_type n = **iter;   //  since iter is a iterator in to the lines-vector. first dereference will return iterator in to set, second dereference yields line_num
            out << "[ " << n << " ]  " << (*get<1>(qr))[n] << std::endl;
        }
    }

    return out;
}

int main(){
    std::ifstream ifile("text.txt");
    if(!ifile){
        std::cerr << "unable to open the file" << std::endl;
        return -1;
    }

    TextQuery tq(ifile);
    std::string word;
    std::cout << "\nEnter the word to search or q to quit : ";
    while(std::cin >> word && word != "q"){
        print(std::cout, tq.query(word)) << std::endl;
            std::cout << "\nEnter the word to search or q to quit : ";
    }

    return 0;
}

/************************************************************************************************************************************************************
 * Designing QueryResult as a class is much better then designing it as a tuple.
 *  1. In tuple we have to explicitly pass the positions of the members, which is trublesome, as the QueryResult contains
 *      types which contains other types as its members, again those members itself contains other types as members.
 *      So there is a lot of chances for us to go wrong with the positions.
 *  2. using members with positions is hard to read and understand.
 *  3. As a class definition, each member as a name, which makes it easy to address whereever and whenever we want
 *  4. Once a tuple is initialised with data, there is no way to add additional data to it, where as we add an element 
 *     to a data member of an object.
 *  5. So a tuple is usefull only when we have to return more than 2 unrelated types once in a program, If it is used 
 *     again and again in some other part of the code, defining the type as a class is better.
 * 
 *************************************************************************************************************************************************************/