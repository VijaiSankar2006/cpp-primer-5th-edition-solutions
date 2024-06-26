/************************************************************************************************************************************************************
 * @file Ex_7_42.cpp
 * @brief Exercise 7.42: For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors
 * might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions 
 * and choose one that you think would use a delegating constructor. Write the class definition for that abstraction
 * @date 2023-12-22
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

//  following code defines Date class
#include <iostream>
#include <ctime>
class Date {
public:
    typedef unsigned short number;

    /** Constructors list begins here ------------------------------------------------------------------------------*/
    // constructor that takes parameters for all  3 members, date, month, and year
    Date(number date_p, number month_p, number year_p) 
        :   date(date_p), month(month_p), year(year_p) {
            std::cout << "Date(number date_p, number month_p, number year_p) : invoked" << std::endl; 
    }

    /* constructor with arguments for date and month with default values for both so it serves 
       Date(), Date(date), Date(date,month) */ 
    Date(number date_p = 22, number month_p = 12) : Date(date_p, month_p, 2023) {
        std::cout << "Date(number date_p = 22, number month_p = 12) : invoked" << std::endl;
    }
    // Constructors list ends here----------------------------------------------------------------------------------//

    // assigns date, month, year
    void set(number date_p, number month_p, number year_p);

    /** get() : overloaded functions, overloaded based on number of parameters, values are ignored, const member function
     *  1 param : returns date as string
     *  2 param : returns date, month in format[dd mm] as string
     *  3 param : returns date, month, year in format[dd mm yy] as string
     * */
    std::string get(number , number , number) const;
    std::string get(number) const ;
    std::string get(number , number ) const ;
private:
    number date;
    number month;
    number year;
};

void Date::set(number date_p = 0, number month_p = 0, number year_p = 0){
    date = date_p ? date_p : date;
    month = month_p ? month_p : month;
    year = year_p ? year_p : year;
}

std::string Date::get(number , number , number ) const {
    return std::to_string(date) + " " + std::to_string(month) + " " +  std::to_string(year);
}

std::string Date::get(number , number ) const {
    return std::to_string(date) + " " + std::to_string(month); 
}

std::string Date::get(number ) const {
    return std::to_string(date);
}

int main(){
    Date d1, d2(11), d3(9,8), d4(28,2,2024);
    std::cout << std::endl;
    std::cout << d1.get(0,0,0) << std::endl;
    std::cout << d2.get(0,0) << std::endl;
    std::cout << d3.get(0) << std::endl;
    std::cout << d4.get(0,0,0) << std::endl;

    return 0;
}