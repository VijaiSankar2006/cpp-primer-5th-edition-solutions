/************************************************************************************************************************************************************
 * @file Ex_13_26.cpp
 * @brief Exercise 13.26: Write your own version of the StrBlob class described in the previous exercise.
 * @date 2024-01-24
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

// StrBlob class that has a value like behaviour, (ie) is when copied or assigned data is copied rather than shared
class StrBlobPtr;
class StrBlob{
    friend class StrBlobPtr;
    public :
        // type alias for size
        typedef std::vector<std::string>::size_type size_type;

        // constructors
        StrBlob();
        StrBlob(const std::initializer_list<std::string> &il);
        StrBlob(const StrBlob &source) 
            : data(std::make_shared<std::vector<std::string>>(*source.data)) {} 
        StrBlob & operator=(const StrBlob &rhs){
            std::vector<std::string> local_copy = *rhs.data;
            data = std::make_shared<std::vector<std::string>>(local_copy);
            return *this;
        }

        // size operations
        size_type size() const;
        bool empty() const;

        StrBlobPtr begin();
        StrBlobPtr end();
        std::string& front();
        std::string& back();
        const std::string & front() const;
        const std::string & back() const;
        void push_back(const std::string &word);
        void pop_back();
        void info(std::string str){
            std::cout << str << ".usecount : " << data.use_count() << std::endl;
        }

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

// ptr class to StrBlob class, this class creates iterators to iterate through the StrBlob container
class StrBlobPtr{
    public :
        StrBlobPtr() : curr(0) {}
        StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
        std::string & deref() const;
        StrBlobPtr & incr();
        
    private : 
        std::weak_ptr<std::vector<std::string>> wptr;  // will point to data member, we use weak_ptr to make sure vector is not asscessed if no shared_ptr exists
        size_t curr;
        std::shared_ptr<std::vector<std::string>> check(size_t curr, const std::string &msg) const ; 
};

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

void print(StrBlob &blob){
    auto iter = blob.begin();
    for(StrBlob::size_type i = 0; i != blob.size(); ++i){
        std::cout << iter.deref() << " ";
        iter.incr();
    }
    std::cout << std::endl;
}


int main(){
    StrBlob b1, b2({"hello","world"}), b3(b2);
    b1.info("b1"); print(b1);
    b2.info("b2"); print(b2);
    b3.info("b3"); print(b3);
    b1 = b2;
    b1.info("b1"); print(b1);
    b2.info("b2"); print(b2);
    b3.info("b3"); print(b3);

}

