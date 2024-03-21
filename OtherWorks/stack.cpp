#include <iostream>

template <typename T, unsigned SZ>
class stack {
    public :
        void push(const T &val) {
            if (curr == SZ) {
                std::cout << "out of bounds" << std::endl;
                return ;
            }
            data[curr++] = val;
        }

        void pop() {
            if(curr)
            --curr;
        }

        T top() {
            if(curr)
                return data[curr - 1]; 
            else { 
                std::cout << "stack is empty" << std::endl;
                std::runtime_error("stack is empty");
            }
            return T(0);     
        }

    private :
        T data[SZ];
        size_t curr = 0;
};

/*
int main() {
    stack<std::string, 10> strstck;

    for(size_t i = 0; i != 12; ++i) {
        strstck.push(std::to_string(i));
    }

    for(size_t i = 0; i != 12; ++i) {
        std::cout << strstck.top() << std::endl;
        strstck.pop();
    }

    return 0;
}
*/