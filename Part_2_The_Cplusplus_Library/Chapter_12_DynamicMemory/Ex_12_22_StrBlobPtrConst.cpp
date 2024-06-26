/************************************************************************************************************************************************************
 * @file Ex_12_22.cpp
 * @brief Exercise 12.22: What changes would need to be made to StrBlobPtr to create a class that can be used with a 
 * const StrBlob? Define a class named ConstStrBlobPtr that can point to a const StrBlob
 * @date 2024-01-18
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
class ConstStrBlobPtr;
class StrBlob{
    friend class ConstStrBlobPtr;
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

// ptr class to StrBlob class, this class creates iterators to iterate through the ConstStrBlob container
class ConstStrBlobPtr{
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

int main(){
    const StrBlob blob{"hello world","this is a test","this works like expected"};
    
    StrBlob::size_type pos = 0;
    for( ConstStrBlobPtr cbeg = blob.cbegin(); pos != blob.size(); ++pos, cbeg.incr()){
        std::cout << cbeg.deref() << std::endl;
    }

    return 0;
}