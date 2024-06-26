/************************************************************************************************************************************************************
 * @file Ex_14_18.cpp
 * @brief Exercise 14.18: Define relational operators for your StrBlob, StrBlobPtr, StrVec,and String classes.
 * @date 2024-01-30
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

//**************************************StrBlob class definition******************************************************************
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <exception>

// StrBlob, all objects share the same underlying data, vector of strings
class ConstStrBlobPtr;
class StrBlob{
    friend class ConstStrBlobPtr;
    friend bool operator<(const StrBlob &lhs, const StrBlob rhs);
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
    public :
        // type alias for size
        typedef std::vector<std::string>::size_type size_type;

        // constructors
        StrBlob();
        StrBlob(const std::initializer_list<std::string> &il);

        // size operations
        size_type size() const;
        bool empty() const;

        // access operations
        ConstStrBlobPtr cbegin() const ;
        ConstStrBlobPtr cend() const ;
        std::string& front();
        std::string& back();
        const std::string & front() const;
        const std::string & back() const;
        void push_back(const std::string &word);
        void push_back(std::string &&word);
        void pop_back();

    private :
        // shared_ptr to point to container
        std::shared_ptr<std::vector<std::string>> data;
        void check(size_type i, const std::string &msg) const ;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(const std::initializer_list<std::string> &il) : data(std::make_shared<std::vector<std::string>>(il)) {}

StrBlob::size_type StrBlob::size() const {
    return data->size();
}

bool StrBlob::empty() const {
    return data->empty();
}

std::string & StrBlob::front(){
    check(0,"container is empty");
    return data->front();
}

std::string & StrBlob::back(){
    check(0,"container is empty");
    return data->back();
}

const std::string & StrBlob::front() const{
    check(0,"container is empty");
    return data->front();
} 

const std::string & StrBlob::back() const{
    check(0, "container is empty");
    return data->back();
}

void StrBlob::push_back(const std::string &word) {
    std::cout << "StrBlob::push_back(const std::string &word) : " << std::endl;
    data->push_back(word);
}

void StrBlob::push_back(std::string &&word){
    std::cout << "StrBlob::push_back(std::string &&word) : " << std::endl;
    data->push_back(std::move(word));
}

void StrBlob::pop_back() {
    check(0, "container is empty");
    data->pop_back();
}

void StrBlob::check(size_type i, const std::string &msg) const {
    if( i >= data->size()){
        throw std::runtime_error(msg);
    }
}


// ptr class to StrBlob class, this class creates iterators to iterate through the ConstStrBlob container
class ConstStrBlobPtr{
    friend bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
    friend bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
    friend bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
    public :
        ConstStrBlobPtr() : curr(0) {}
        ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
        const std::string & deref() const;
        ConstStrBlobPtr & incr();
        
    private : 
        std::weak_ptr<std::vector<std::string>> wptr;  // will point to data member, we use weak_ptr to make sure vector is not asscessed if no shared_ptr exists
        size_t curr;
        std::shared_ptr<std::vector<std::string>> check(size_t curr, const std::string &msg) const ; 
};

// need to implement proper way to compare pointers, as right now 
bool operator==(const StrBlob &lhs, const StrBlob &rhs){ 
    auto iterlhs = lhs.cbegin();
    auto iterrhs = rhs.cbegin();
    if(lhs.size() != rhs.size()){
        std::cout << " 0 " << std::endl;
        return 0;
    }

    while(iterlhs != lhs.cend()){
        auto str1 = iterlhs.deref();
        auto str2 = iterrhs.deref();
        if( str1 != str2){
            return 0;
        }    
        iterlhs.incr();
        iterrhs.incr();    
    }

    return 1;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs){
    auto res = !(lhs == rhs);
    return res;
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs){
    auto sp1 = lhs.wptr.lock();
    auto sp2 = rhs.wptr.lock();
    if( sp1!= sp2)  // compare pointers of two different containers
        return 0;

    //  if containers are same, we have to check the position of the pointer
    auto res = (lhs.curr == rhs.curr);
    return res;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs){
    auto res =  !(lhs == rhs);
    return res;
}

bool operator<(const StrBlob &lhs, const StrBlob rhs){
    return (*lhs.data) < (*rhs.data);
}

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs){
    return lhs.curr < rhs.curr;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(size_t curr, const std::string &msg) const {
    auto sp = wptr.lock();
    if(!sp){
        throw std::runtime_error("unbound StrBlobPtr");
    }else if(curr >= sp->size()){
        throw std::out_of_range(msg);
    }
    
    return sp;
}

const std::string & ConstStrBlobPtr::deref() const{
    auto sp = check(curr, "out of bounds");
    return (*sp)[curr];
}

ConstStrBlobPtr & ConstStrBlobPtr::incr(){
    check(curr, "cannot be incremented");
    ++curr;
    return *this;
}


ConstStrBlobPtr StrBlob::cbegin() const{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const{
    return ConstStrBlobPtr(*this, data->size());
}

//********************************** StrBlob and ConstStrBlobPtr definition ends here ***************************************//

#include <iostream>
#include <utility>
#include <memory>
#include <algorithm>
#include <cstring>
#include <vector>

class String {
    friend std::ostream & operator<<(std::ostream &os, const String &str);
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);
    friend bool operator<(const String &lhs, const String &rhs);
    public :
        String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
        String(const char *p);
        String(const String &source);
        String(String &&source) noexcept;
        String & operator=(String rhs);
        String & operator=(String &&rhs);
        char * begin() const;
        char * end() const;
        ~String(){ free(); }
        size_t size() const ;
        void reserve(const size_t sz);
        size_t capacity();
        void push_back(const char &ch);
    private :
        void swap(String &lhs, String &rhs);
        void check_n_alloc();
        void realloc(const size_t sz = 0);
        void free();
        std::pair<char *, char *> alloc_n_copy(const char *b, const char *e);
        char * elements;
        char * first_free;
        char * cap;
        std::allocator<char> alloc;
};

std::ostream & operator<<(std::ostream &os, const String &str){
    auto iter = str.begin();
    while(iter != str.end()){
        os << *iter++;
    }

    return os;
}

String::String(const char *p){
    std::cout << "String(const char *p) : " << std::endl;
    std::cout << "sizeof(p) " << strlen(p) << std::endl;
    auto data = alloc_n_copy(p, p + strlen(p));
    elements = data.first;
    first_free = cap = data.second;
}

String::String(const String &source){
    std::cout << "String(const String &source) :" << std::endl;
    auto data = alloc_n_copy(source.begin(), source.end());
    elements = data.first;
    first_free = cap = data.second;
}

String::String(String &&source) noexcept : elements(source.elements), first_free(source.first_free), cap(source.cap){
    std::cout << "String::String(String &&source) noexcept : " << std::endl;
    source.elements = source.first_free = source.cap = nullptr;
}


char * String::begin() const {
    return elements;
}

char * String::end() const {
    return first_free;
}

String & String::operator=(String rhs){
    std::cout << "operator=(String rhs) : " << std::endl;
    swap(*this, rhs);
    return *this;
}

String & String::operator=(String &&rhs){
    std::cout << "String::operator=(String &&rhs) : " << std::endl;
    if(this != &rhs){
        swap(*this, rhs);
    }
    return *this;
}

void String::swap(String &lhs, String &rhs){
   using std::swap;
   swap(lhs.elements, rhs.elements);
   swap(lhs.first_free, rhs.first_free);
   swap(lhs.cap, rhs.cap);
}

void String::check_n_alloc(){
    if(first_free == cap){
        realloc();
    }
}

size_t String::size() const {
    return first_free - elements;
}

void String::reserve(const size_t sz){
    realloc(sz);
}

size_t String::capacity(){
    return cap - elements;
}

void String::realloc(const size_t sz){
    size_t new_capacity;
    if(!sz){
        new_capacity = size() ? 2 * size() : 1;
    }else if( sz && sz > capacity()){
        new_capacity = sz;
    }else {
        return ;
    }

    auto new_elements = alloc.allocate(new_capacity);
    auto new_first_free = std::uninitialized_copy(std::make_move_iterator(elements), std::make_move_iterator(first_free), new_elements);
    free();
    elements = new_elements;
    first_free = new_first_free;
    cap = elements + new_capacity;
}

void String::free(){
    while(first_free != elements){
        std::destroy_at(--first_free);
    }
    alloc.deallocate(elements, cap - elements);
    elements = first_free = cap = nullptr;
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e){
    auto new_elements = alloc.allocate(e - b);
    auto new_first_free = std::uninitialized_copy(b, e, new_elements);
    return {new_elements, new_first_free};
}

void String::push_back(const char &ch){
    check_n_alloc();
    std::construct_at(first_free++, ch);
}

bool operator==(const String &lhs, const String &rhs){
    if(lhs.size() != rhs.size()){
        return 0;
    }
    auto blhs = lhs.begin();
    auto brhs = rhs.begin();
    while(blhs != lhs.end()){
        if(*blhs++ != *brhs++){
            return 0;
        }
    }

    return 1;
}

bool operator!=(const String &lhs, const String &rhs){
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs){
    auto iterlhs = lhs.begin();
    auto iterrhs = rhs.begin();
    if(lhs.size() == rhs.size()){
        std::cout << "equal size " << std::endl;
        while(iterlhs != lhs.end()){
            if(*iterlhs++ > *iterrhs++){
                return 0;
            }
        }    
    }else if( lhs.size() < rhs.size()){
        std::cout << "lhs.size() < rhs.size()" << std::endl;
        iterlhs = lhs.begin();
        iterrhs = rhs.begin();
        while(iterlhs != lhs.end()){
            if(*(iterlhs++) > *(iterrhs++)){
                return 0;
            }
        } 
        return 1;
    }else {
        std::cout << "lhs.size() > rhs.size()" << std::endl;
        iterlhs = lhs.begin();
        iterrhs = rhs.begin();
        while(iterrhs != rhs.end()){
            if(*iterlhs++ > *iterrhs++){
                return 0;
            }
        }
        return 1;
    }

    return 1;
}
//************************************************* String class ends here ************************************************

//************************************************* StrVec class begins here **********************************************

/*****************************************StrVec program begins here********************************************************/
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <string>
#include <initializer_list>

class StrVec{
    friend void swap(StrVec &lhs, StrVec &rhs);
    friend bool operator<(const StrVec &lhs, const StrVec &rhs);
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
    public :
        StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
        StrVec(const StrVec &);
        StrVec(StrVec &&) noexcept;
        StrVec & operator=(const StrVec &rhs);
        StrVec & operator=(StrVec &&rhs) noexcept;
        StrVec(const std::initializer_list<std::string> &il);
        size_t size() const ;
        size_t capacity() const;
        void reserve(const size_t sz);
        void push_back(const std::string &);
        const std::string *begin() const ;
        const std::string *end() const ;
        ~StrVec(){ free(); }

    private :
        std::string *elements;
        std::string *first_free;
        std::string *cap;

        std::allocator<std::string> alloc;
        void realloc(const size_t sz = 0);
        void check_n_alloc();
        std::pair<std::string *, std::string *> alloc_n_copy(const std::string *b, const std::string *e);
        void free();
};

StrVec::StrVec(const StrVec &source){
    std::cout << "StrVec::StrVec(const StrVec &source)" << std::endl;
    auto new_data = alloc_n_copy(source.begin(), source.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::StrVec(StrVec &&source) noexcept : elements(source.elements), first_free(source.first_free), cap(source.cap){
    std::cout << "StrVec::StrVec(StrVec &&source) noexcept : " << std::endl;
    source.elements = source.first_free = source.cap = nullptr;
}


StrVec & StrVec::operator=(const StrVec &rhs){
    std::cout << "StrVec::operator=(const StrVec &rhs) : " << std::endl;
    auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = new_data.first;
    first_free = cap = new_data.second;

    return *this;
}

void swap(StrVec &lhs, StrVec &rhs){
    std::cout << "void swap(StrVec &lhs, StrVec &rhs) : " << std::endl;
    using std::swap;
    swap(lhs.elements, rhs.elements);
    swap(lhs.first_free, rhs.first_free);
    swap(lhs.cap, rhs.cap);
}

StrVec & StrVec::operator=(StrVec &&rhs) noexcept{
    std::cout << "StrVec::operator=(StrVec &&rhs) noexcept : " << std::endl;
    if(this != &rhs){
        swap(*this, rhs);
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}


StrVec::StrVec(const std::initializer_list<std::string> &il){
    std::cout << "StrVec::StrVec(const std::initializer_list<std::string> &il) : " << std::endl;
    auto data = alloc_n_copy(il.begin(), il.end());
    elements = data.first;
    first_free = cap = data.second;
}

size_t StrVec::size() const {
    return first_free - elements;
}

size_t StrVec::capacity() const{
    return cap - elements;
}

void StrVec::reserve(const size_t sz) {
    realloc(sz);
}

void StrVec::push_back(const std::string &str){
    check_n_alloc();
    std::construct_at(first_free++, str);
}

const std::string *StrVec::begin() const{
    return elements;
}

const std::string *StrVec::end() const{
    return first_free;
}

void StrVec::realloc(const size_t sz){
    std::cout << "StrVec::realloc(const size_t sz) : " << std::endl;
    size_t new_capacity;
    if (!sz) {
        new_capacity = size() ? 2 * size() : 1;
    } else if (sz && sz > capacity()) {
        new_capacity = sz;
    } else {
        return;
    }
    auto new_elements = alloc.allocate(new_capacity);
    auto new_first_free = std::uninitialized_copy(std::make_move_iterator(elements), std::make_move_iterator(first_free), new_elements);
    free();
    elements = new_elements;
    first_free = new_first_free;
    cap = elements + new_capacity;
}

void StrVec::check_n_alloc(){
    if(first_free == cap)
        realloc();
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e){
    auto new_elements = alloc.allocate(e - b);
    auto first_free = std::uninitialized_copy(b, e, new_elements);
    return {new_elements, first_free};
}

void StrVec::free(){
    if(elements){
        while(first_free != elements){
            std::destroy_at(--first_free);
        }
    }
    alloc.deallocate(elements, cap - elements);
}   
void print(const StrVec &svec){
    if(svec.size() == 0){
        std::cout << "list is empty" << std::endl;
        return;
    }

    std::cout << "====================================================" << std::endl << "##  ";
    for(auto iter = svec.begin(); iter != svec.end(); ++iter){
        std::cout << *iter << " ";
    }
    std::cout << "  ##" << std::endl;
    return;
}

bool operator==(const StrVec &lhs, const StrVec &rhs){
    if(lhs.size() != rhs.size()){
        return 0;
    }

    auto iterlhs = lhs.begin();
    auto iterrhs = rhs.begin();
    while(iterlhs != lhs.end()){
        if(*iterlhs++ != *iterrhs++){
            return 0;
        }
    }
    return 1;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs){
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs){
    auto iterlhs = lhs.begin();
    auto iterrhs = rhs.begin();
    if(lhs.size() == rhs.size()){
        while(iterlhs != lhs.end()){
            if(*iterlhs++ > *iterrhs++){
                return 0;
            }
        }
        return 1;
    } else if (lhs.size() < rhs.size()) {
        auto iterlhs = lhs.begin();
        auto iterrhs = rhs.begin();
        while(iterlhs != lhs.end()){
            if(*iterlhs++ > *iterrhs++){
                return 0;
            }
        }
        return 1;
    } else {
        auto iterlhs = lhs.begin();
        auto iterrhs = rhs.begin();
        while(iterrhs != rhs.end()){
            if(*iterlhs++ > *iterrhs++){
                return 0;
            }
        }
        return 0;
    }
}
//********************************************** StrVec class ends here ******************************************************

int main(){
    StrBlob b1{"alpha", "beta", "gamma"}, b2{"alpha", "beta", "Gamma", "delta"};
    std::cout << "b1 < b2 : " << (b1 < b2) << std::endl;

    auto beg = b1.cbegin();
    auto end = b2.cend();
    std::cout << "end < beg : " << (end < beg) << std::endl;

    return 0;
}   