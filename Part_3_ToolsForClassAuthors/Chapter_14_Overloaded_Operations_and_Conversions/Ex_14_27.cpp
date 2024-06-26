/************************************************************************************************************************************************************
 * @file Ex_14_27.cpp
 * @brief Exercise 14.27: Add increment and decrement operators to your StrBlobPtr class.
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

//  libraries needed
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <exception>

// StrBlob, all objects share the same underlying data, vector of strings
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob{
    friend class StrBlobPtr;
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
        StrBlobPtr begin();
        StrBlobPtr end();
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

void StrBlob::push_back(std::string &&word){
    std::cout << "StrBlob::push_back(std::string &&word) : " << std::endl;
    data->push_back(std::move(word));
}

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
    data->push_back(word);
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

// ptr class to StrBlob class, this class creates iterators to iterate through the StrBlob container
class StrBlobPtr{
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    public :
        StrBlobPtr() : curr(0) {}
        StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
        std::string & deref() const;
        StrBlobPtr & incr();
        StrBlobPtr & operator++();
        StrBlobPtr & operator--();
        StrBlobPtr operator++(int);
        StrBlobPtr operator--(int);
    private : 
        std::weak_ptr<std::vector<std::string>> wptr;  // will point to data member, we use weak_ptr to make sure vector is not asscessed if no shared_ptr exists
        size_t curr;
        std::shared_ptr<std::vector<std::string>> check(size_t curr, const std::string &msg) const ; 
};

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
bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs){
    return lhs.curr < rhs.curr;
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

StrBlobPtr & StrBlobPtr::operator++(){
    check(curr, "out of bounds");
    ++curr;
    return *this;
}

StrBlobPtr & StrBlobPtr::operator--(){
    --curr;
    check(curr, "out of bounds");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int){
    auto old = *this;
    ++*this;
    return old;
}

StrBlobPtr StrBlobPtr::operator--(int){
    auto old = *this;
    --*this;
    return old;
}

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

ConstStrBlobPtr StrBlob::cbegin() const{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const{
    return ConstStrBlobPtr(*this, data->size());
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs){
    auto res = !(lhs == rhs);
    return res;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    auto sp1 = lhs.wptr.lock();
    auto sp2 = rhs.wptr.lock();
    if( sp1!= sp2)  // compare pointers of two different containers
        return 0;

    //  if containers are same, we have to check the position of the pointer
    auto res = (lhs.curr == rhs.curr);
    return res;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    auto res =  !(lhs == rhs);
    return res;
}

bool operator<(const StrBlob &lhs, const StrBlob rhs){
    return (*lhs.data) < (*rhs.data);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return lhs.curr < rhs.curr;
}


std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t curr, const std::string &msg) const {
    auto sp = wptr.lock();
    if(!sp){
        throw std::runtime_error("unbound StrBlobPtr");
    }else if(curr >= sp->size()){
        throw std::out_of_range(msg);
    }
    
    return sp;
}

std::string & StrBlobPtr::deref() const{
    auto sp = check(curr, "out of bounds");
    return (*sp)[curr];
}

StrBlobPtr & StrBlobPtr::incr(){
    check(curr, "cannot be incremented");
    ++curr;
    return *this;
}


StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
    return StrBlobPtr(*this, data->size());
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

int main(){
    StrBlob b1{"alpha","beta","gamma","delta"};
    auto iter = b1.begin();
    for(; iter != b1.end(); iter++){
        std::cout << iter.deref() << std::endl;
    }
    
    


    return 0;
}