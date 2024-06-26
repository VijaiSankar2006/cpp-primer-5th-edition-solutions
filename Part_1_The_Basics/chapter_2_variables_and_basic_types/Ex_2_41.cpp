/*  Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22),§ 1.5.2 (p. 24), and § 1.6 (p. 25).
    For now, you should define your Sales_data class in the same file as your main function.*/

//  ######################################################################################################################

//  ------------------------------------------------------------------------------------------------------------------------
//  Section 1.5.1
/*  Exercise 1.20 : write a program that reads a set of book sales transactions, writing each transaction to the 
    standard output. */

#include <iostream>

// sales_data class definition
struct sales_data{
    std::string book_no;
    size_t units_sold;
    double revenue;
};

/*
int main(){

    // code to read transactions of two books
    std::cout << "Enter the transactions of book1[isbn, price, units_sold] : ";
    sales_data book1, book2;
    double price;
    std::cin >> book1.book_no >> price >> book1.units_sold;
    book1.revenue = price * book1.units_sold;
    std::cout << "Enter the transactions of book2[isbn, price, units_sold] : ";
    std::cin >> book2.book_no >> price >> book2.units_sold;
    book2.revenue = price * book2.units_sold;

    // code to print transactions
    std::cout << "List of transactions : \n";
    std::cout << book1.book_no << " " << book1.units_sold << " " << book1.revenue;
    std::cout << book2.book_no << " " << book2.units_sold << " " << book2.revenue;

    return 0;
}
// -----------------------------------------------------------------------------------------------------------------------


// Ex 1.21 : Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

#include <iostream>

// sales_data class definition
struct sales_data{
    std::string book_no;
    size_t units_sold;
    double revenue;
};

int main(){

    // code to read transactions of two books
    std::cout << "Enter the transactions of book1[isbn, price, units_sold] : ";
    sales_data book1, book2;
    double price;
    std::cin >> book1.book_no >> price >> book1.units_sold;
    book1.revenue = price * book1.units_sold;
    std::cout << "Enter the transactions of book2[isbn, price, units_sold] : ";
    std::cin >> book2.book_no >> price >> book2.units_sold;
    book2.revenue = price * book2.units_sold;

    // code to calculate the sum
    if( book1.book_no == book2.book_no ){
        double total_revenue = book1.revenue + book2.revenue;
        size_t total_units_sold = book1.units_sold + book2.units_sold;
        std::cout << book1.book_no << " " << total_units_sold << " " << total_revenue << std::endl;
        std::cout << "Average revenue : "<< total_revenue / total_units_sold << std::endl;
        return 0;
    }else{
        std::cerr << "ISBN should match" << std::endl;
        return -1;
    }
}
//  ----------------------------------------------------------------------------------------------------------------------


//  Exercise 1.22 :
//  Write a program that reads several transactions for the same ISBN .Write the sum of all the transactions that were read.

#include <iostream>

// sales_data class definition
struct sales_data{
    std::string book_no;
    size_t units_sold;
    double revenue;
};

int main(){
    
    std::cout << "Enter the transactions to add : \n";
    sales_data book, total;
    double price;
    std::cin >> total.book_no >> price >> total.units_sold;
    total.revenue = price * total.units_sold; 

    // while loop will execute untill user enters different bookno
    while(1){
        std::cin >> book.book_no >> price >> book.units_sold;
        book.revenue = price * book.units_sold;
        if( total.book_no == book.book_no ){
            total.units_sold += book.units_sold;
            total.revenue += book.revenue;
        }else{
            // this will get printed if different book no is printed
            std::cout << total.book_no << " " << total.units_sold << " " << total.revenue;
            return 0;
        }
    }
    return 0;
}
//------------------------------------------------------------------------------------------------------------------------

//  section 1.5.2 
//  Exercise 1.23: Write a program that reads several transactions and counts how many transactions occur for each ISBN .

int main(){

    sales_data prev, curr;
    std::cout << "Enter the list of transactions : \n";
    double price;
    std::cin >> prev.book_no >> price >> prev.units_sold;
    prev.revenue = price * prev.units_sold;
    size_t count = 1;

    while(std::cin >> curr.book_no >> price >> curr.units_sold ){
        curr.revenue = price * curr.units_sold;
        if( curr.book_no == prev.book_no ){
            ++count;
        }else{
            std::cout << prev.book_no << " occurs " << count << " times" << std::endl;
            prev = curr;
            count = 1;
        }
    }

    // when user ends the input this will be printed
    std::cout << prev.book_no << " occurs " << count << " times" << std::endl;
}
//  ----------------------------------------------------------------------------------------------------------------------

*/
/*  Exercise 1.24: Test the previous program by giving multiple transactions representing multiple ISBN s. The records for
 *  each ISBN should be grouped together.
 *
 *  refer solution of above section */
//  ----------------------------------------------------------------------------------------------------------------------

//  Section 1.6
//  Exercise 1.25: Using the Sales_data class , compile and execute the bookstore program presented in this section.

int main(){

    sales_data total, book;
    double price;
    std::cout << "Enter the list of transactions : \n";
    
    if( std::cin >> total.book_no >> price >> total.units_sold ){
        total.revenue = price * total.units_sold;
        while( std::cin >> book.book_no >> price >> book.units_sold ){
            book.revenue = price * book.units_sold;
            if( total.book_no == book.book_no ){
                total.revenue += book.revenue;
                total.units_sold += book.units_sold;
            }else{
                std::cout << total.book_no << " " << total.units_sold << " " << total.revenue << std::endl;
                total = book;
            }
        }
        std::cout << total.book_no << " " << total.units_sold << " " << total.revenue << std::endl;
        return 0;
    }else{
        std::cerr << "No input" << std::endl;
        return -1;
    }
}