/************************************************************************************************************************************************************
 * @file Ex_7_57.cpp
 * @brief Exercise 7.57: Write your own version of the Account class
 * @date 2023-12-24
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include<iostream>
#include<string>

/************************************************************************************************************************************************************
 * constructor - account no, customer name, balance, principal, loan must 
 * ruppees - it is the type for money defined in Account
 * init_roi() - takes new_rate_of_interest
 * printCustomerInfo() - prints the customer information
 * printLoanInfo() - prints loan information of the customer
 * get_roi() - returns current rate of interest in ruppees type
 *************************************************************************************************************************************************************/

//  Account class definition starts here
class Account{
    //  Interface starts here
public :
    typedef long double ruppees;
    static void init_roi(ruppees new_interest);
    std::ostream & printCustomerInfo(std::ostream &) const ;
    std::ostream & printLoanInfo(std::ostream &) const ;
    ruppees get_roi() const ;
    Account(const std::string &account_no_p, const std::string &name_p , ruppees balance_p, ruppees principal_p)
        :   account_no(account_no_p), name(name_p), balance(balance_p), principal(principal_p), 
            loan(principal * rate_of_interest / 100 + principal) { }
private :
    static double rate_of_interest;
    std::string account_no;
    std::string name;
    ruppees balance;
    ruppees principal;
    ruppees loan;
};
// Account class definition ends here

// Definitions of member functions of Account class starts here

// https://stackoverflow.com/questions/67948759/unable-to-access-static-member-from-static-function
double Account::rate_of_interest = 9.8; 
void Account::init_roi(ruppees new_interest){
    rate_of_interest = new_interest;
}

std::ostream & Account::printCustomerInfo(std::ostream &out = std::cout) const {
    out << "Account no : " << account_no << "\n" << "Name : " << name << "\n"
        << "Balance : " << balance << std::endl;
    return out;
}

std::ostream & Account::printLoanInfo(std::ostream &out = std::cout) const {
    out << "Principal : " << principal << "\n"
        << "Loan : " << loan << std::endl;
    return out;
}

Account::ruppees Account::get_roi() const {
    return rate_of_interest;
}

//  definitions of member functions ends 

int main(){
    Account::init_roi(4.5);   
    Account customer1("12345", "vijai shankar", 900000, 100000);
    std::cout << "current rate of interest : " << customer1.get_roi() << std::endl;
    customer1.printCustomerInfo();
    customer1.printLoanInfo();
    return 0;
}



