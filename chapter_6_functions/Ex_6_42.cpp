/* Exercise 6.42: Give the second parameter of make_plural (§ 6.3.2, p. 224) a default argument of ’s’. Test your program 
 * by printing singular and plural versions of the words success and failure. */

#include <iostream>

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main(){
    std::string str1 = make_plural(2, "success", "es");
    std::string str2 = make_plural(2,"failure");
    std::cout << str1 << " " << str2 << std::endl;
    str1 = make_plural(1,"success");
    str2 = make_plural(1, "failure");
    std::cout << str1 << str2 << std::endl;

    return 0;
}

