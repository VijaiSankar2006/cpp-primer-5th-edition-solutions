// Exercise 2.40: Write your own version of the Sales_data class.

#include <iostream>

struct sales_data{
    std::string book_no;
    size_t count;
    double revenue;
};

int main(){
    sales_data book1, book2;
    std::cout << "Enter the transactions of two books : \n";
    std::cin >> book1.book_no >> book1.revenue >> book1.count;
    std::cin >> book2.book_no >> book2.revenue >> book2.count;

    std::cout << "List of transactions : \n";
    std::cout << book1.book_no << " " << book1.revenue << " " << book1.count;
    std::cout << book2.book_no << " " << book2.revenue << " " << book2.count;

    return 0;
}
