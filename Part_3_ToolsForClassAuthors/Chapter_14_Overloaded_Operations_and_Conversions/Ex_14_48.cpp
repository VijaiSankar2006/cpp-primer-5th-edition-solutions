/************************************************************************************************************************************************************
 * @file Ex_14_48.cpp
 * @brief Exercise 14.48: Determine whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) should have
 * a conversion to bool. If so, explain why, and explain whether the operator should be explicit. If not, explain
 * why not.
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * Date class should have a conversion to bool to check whether a date object is initialised with valid date or not
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <ctime>
#include <string>
#include <set>

class Date {
public:
    typedef unsigned short number;
    friend void swap(Date &lhs, Date &rhs);
    friend bool operator<(const Date &d1, const Date &d2);
    friend std::ostream & operator<<(std::ostream &os, const Date &dt);
    friend std::istream & operator>>(std::istream &is, Date &dt);
    friend number operator-(const Date &lhs, const Date &rhs);
    friend number operator-=(Date &lhs, const Date &rhs);
    Date() : date(0), month(0), year(0) {};
    Date(number date_p, number month_p, number year_p) 
        :   date(date_p), month(month_p), year(year_p) { }
    Date(const Date &source) : date(source.date), month(source.month), year(source.year) {}
    Date(Date &&source) : date(0), month(0), year(0){
        swap(*this, source);
    }
    Date & operator=(const Date &rhs);
    Date & operator=(Date &&rhs);
    void set(number date_p, number month_p, number year_p);
    std::string get(number dummy1 , number dummy2 , number dummy3) const;
    std::string get(number) const ;
    std::string get(number , number ) const ;
    explicit operator bool() const {
        return date > 0 && month > 0 && year > 0;
    }
private:
    static int days_left(const Date &dt);
    number date;
    number month;
    number year;
};

Date & Date::operator=(const Date &rhs){
    if(this != &rhs){
        this->date = rhs.date;
        this->month = rhs.month;
        this->year = rhs.year;
    }

    return *this;
}

Date & Date::operator=(Date &&rhs){
    if(this != &rhs){
        swap(*this, rhs);
    }

    return *this;
}

void swap(Date &lhs, Date &rhs){
    using std::swap;
    swap(lhs.date, rhs.date);
    swap(lhs.month, rhs.month);
    swap(lhs.year, rhs.year);
}

std::ostream & operator<<(std::ostream &os, const Date &dt){
    os << dt.date << "-" << dt.month << "-" << dt.year;
    return os;
}

std::istream & operator>>(std::istream &is, Date &dt){
    is >> dt.date >> dt.month >> dt.year;
    if(!(is && ( dt.date <= 32 && dt.month <= 12))){
        is.setstate(std::iostream::failbit);
        dt = Date();
    }

    return is;
}

int Date::days_left(const Date &dt){
    int days ;
    std::set<int> thirty_one{1,3,5,7,8,10,12}, thirty{4,6,9,11};
    if(thirty_one.contains(dt.month)){
        days = 31 - dt.date; 
    }else if(thirty.contains(dt.month)){
        days = 30 - dt.date;
    }else{
        if(dt.year % 4){
            days = 28 - dt.date;
        }else{
            days = 29 - dt.date;
        }
    }

    int month = dt.month + 1;
    while(month <= 12){
        if(thirty_one.contains(month)){
            days += 31;
        }else if(thirty.contains(month)){
            days += 30;
        }else {
            if(dt.year % 4){
                days += 29;
            }else{
                days += 28;
            }
        }
        ++month;
    }

    return days;
}
//  need to test for the corrctness
Date::number operator-(const Date &lhs, const Date &rhs){
    std::set<int> thirty_one{1,3,5,7,8,10,12}, thirty{4,6,9,11};
    Date big = lhs;
    Date small = rhs;
    if( rhs.year > lhs.year || ((rhs.year == lhs.year && rhs.month > lhs.month) || (rhs.month == lhs.month && rhs.date >= lhs.date))){
        big = rhs;
        small = lhs;
    }   

    int days_left_small = Date::days_left(small);
    std::cout << "days_left_small : " << days_left_small << std::endl;
    int days_elapsed_big;
    int days_left_big = Date::days_left(big);
    if(big.year % 4){
        days_elapsed_big = 365 - days_left_big;
        std::cout << "days_elapsed_big[not a leap year] : " << days_elapsed_big << std::endl; 
    }else{
        days_elapsed_big = 366 - days_left_big;
        std::cout << "days_elapsed_big[leap year] : " << days_elapsed_big << std::endl;
    }
    

    int diff_year = big.year - small.year - 1;
    int daysFromYear = 0;
    if(diff_year >= 0){
        int yy = small.year + 1;
        while(yy != big.year){
            if(yy % 4){
                daysFromYear += 365;
            }else {
                daysFromYear += 366;
            }
            ++yy;
        }
    }
    std::cout << "daysFromYear : " << daysFromYear << std::endl;

    int total_days = days_left_small + days_elapsed_big + daysFromYear;
        
    return total_days;
} 


void Date::set(number date_p = 0, number month_p = 0, number year_p = 0){
    date = date_p ? date_p : date;
    month = month_p ? month_p : month;
    year = year_p ? year_p : year;
}

std::string Date::get(number , number , number ) const {
    return std::to_string(date) + " " + std::to_string(month) + " " +  std::to_string(year);
}

std::string Date::get(number) const {
    return std::to_string(date);
}

std::string Date::get(number , number) const {
    return std::to_string(date) + " " + std::to_string(month);
}

bool operator<(const Date &d1, const Date &d2){
    if(d1.year < d2.year || ((d1.year == d2.year && d1.month < d2.month) || (d1.year == d2.year && d1.month == d2.month && d1.date < d2.date))){
        return 1;
    }

    return 0;
}

int main(){
    const Date d1(0,0,0);
    std::cout << ( d1 ? "true" : "false") << std::endl;
}