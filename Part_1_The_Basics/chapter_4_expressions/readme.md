# EXPRESSIONS
>   **expression** is composed of **one or more** operands, when evaluated yeilds a **result**. The simplest form of     
>   expression is a **single literal or a single variable**, the result of such expression is value of the variable or    
>   literal. A lvalue is a reference to an object and an rvalue is contents of the object     
     
####    decltype    
>   **decltype(expression)**           
>   if expression yeilds a lvalue, then the type is a reference as lvalue is nothing but a reference          
>   but *decltype(variable)* is not a reference, as here decltype doesn't evaluate a variable so it just the type of the  
>   variable. Only an **expression** is evaluted.     
>   if p is a int *,      
        decltype(*p) yields reference to the int object as '*' yields lvalue.       
        decltype(p) yields int *, type of p is int *.          
        decltype(&p) yields int **, as '&' yields an pointer to the object, here the object is pointer to int, so we get
        int **.    
>   decltype(rvalue) yields the type of the rvalue.      

### Order of Evaluation, Precedence and Associativity    
>   f() * g() + h() + i()      
>   **Precedence**, says to which operators the operands will grouped first, so here as per precedence the operands will be grouped as **( f() * g() ) + h() + i()**    

>   **associativity**, says how to group when the operators are of *same precedence*, here '+' is left to right, start grouping from the left to right, so the expression becomes **( (f() * g()) + h() ) + i()**     
>   **order of evaluation**, says which operand will be evaluted first, but most of the operators doesn't say anything about *order of evaluation*, here '+' and '*' has no order of evalution defined. So any function may be evaluated first, same thing happens for variables too, there is not guarantee that which variable will be evaluated first. So the expression is in **error** if it contains two or more operands which refer and change the state of same variable and it results in undefined value, for example **i * ++i**, here based on which 'i' or '++i' is evaluated first, we get different results, so this is in error      
>  **&&, ||, comma(,), conditional(?:)** are the only operators that guarantee order of evalation      
        && - left operand is evaluated first, only if it is 'true' the right operand is evaluated      
        || - left operand is evaluated first, only if it is 'false' the right operand is evaluated   
        expr1 ? expr2 : expr3, either expr2 or expr3 is evaluated based on expr1 but not both
        left-operand,right-operand - left-operand is evaluated but ignored, right operand is evaluated and returned  

### MODULUS %   (m/n)*n + m%n = m
        (-m % n) = -(m % n)
        (m % -n) = m % n        //  that is how it is implemented in c++, there is no proper standard for this in mathamatics
        
### if(val == true)     // error
        in an expression involving bool type and non-bool type, the bool type is converted to whatever the other type 
        represents.so the above expression becomes
        if( val == 1 )  //  assuming val is int
        so here val is compared with 1, so val is anyother number, the condition evaluates to false
        so always use 
        if(val) // true if val is non-zero otherwise false

### Increment and Decrement operators
**prefix** operators returns modified object as a **lvalue**
**postfix** operators returns a copy of the object's original value as **rvalue**

### Conditional operator( ? : ) 
        cond ? expr1 : expr2   
        if condition is expression, then expr1 and expr2 should be same type as the expression in condition or they should be able to convert to a common type
        returns lvalue if expr1, expr2 are both lvalues or can be converted to lvalue otherwise an rvalue
        guaranties only expr1 or expr2 is evaluated.
        condition operator form : cond/expr ? expr : assignment_expression
                true_case - is whatever from '?' to ':' 
                fail_case - is up to first sequence point
                example : 
                someValue ? --x, --y : ++x, ++y;
                true_case = --x amd --y
                false_case = ++x
                ++y will be executed regardless of the value of someValue as ++y is not part of conditional operator
[stackoverflow : how conditional operator works](https://stackoverflow.com/a/47539293/22415216)  
### Bitwise operators - use only unsigned type
        takes integral type and use that as collection of bits to check individual bit
        if value is -ve, then how sign bit is handled is machine dependent, so left shifting a -ve value is undefined

### sizeof operator 
        sizeof (type)
        sizeof expr
        returns the size of expr or typename in bytes. 
        it is a constant expression, executed at compile time
        it does not evaluate the operand
        ex:- int i, *p; int arr[10];
        sizeof(int) or sizeof int
        sizeof(i) or sizeof i
        sizeof(p) or sizeof p
        sizeof(*p) or sizeof *p   //  sizeof is right associative and has same precedence as *
        sizeof(arr) or sizeof arr
        As the operand is not evaluated arr doesn't covert in to a pointer and in the case of *p, a invalid pointer can be pased to sizeof

### Comma operator
        Comma operator(,) takes two operands evalutes left to right, returns the value of right expression 
        left operand is evaluated and the value is discarded
        right operand is evaluated and value is returned    

### Type Conversion
#### Implicit type conversion
        • type conversion is done from smaller to a wider type to preserve information
        • In most expressions, values of integral types smaller than int are first promoted to an appropriate larger      
          integral type.
        • In conditions, nonbool expressions are converted to bool.
        • In initializations, the initializer is converted to the type of the variable; in assignments, the right-hand 
          operand is converted to the type of the left-hand.
        • In arithmetic and relational expressions with operands of mixed types, the types are converted to a common type.
        • In expressions involving unsigned and signed, if unsigned is of same or larger than signed type, then signed 
          type is converted to unsigned. 
          If unsigned is smaller than signed then if all values in the unsigned type fit in the signed type, then unsigned
          type is converted to signed type, otherwise signed is converted to unsigned type
        • 0 and ptr literal nullptr are converted to any pointer type. 
        • ptr to any non-const type can be converted to void *, ptr to any const type can be converted to const void *
        • ptr can be converted to bool       
        • array name decay in to ptr to the first array element, except in decltype, sizeof as they don't evaluate
        • we can convert a ptr/ref to non-const to ptr/ref to const, but the opposite is not allowed
        • for class type, the class define conversion, that compiler will automaticaly apply, but only one class type 
          conversion is allowed
          c-style string is converted to library string,
          cin/cout is converted to bool
#### Explicit type conversion
        • cast_name<type_name>(expr)
                • static_cast<type_name>(expr) ===   static_cast<double>(i)/j, static_cast<int *>(ptr)  // ptr is a void * which was originaly pointing to int otherwise it will fail
        • const_cast<char *>(ch), removes the low level const, it is used to convert ptr/ref to const to ptr/ref to non-const. It will not convert to different type, it only casts away the const
          using a const_cast to get write access is legal however writing to a const object is undefined
          (ie) T is non-const type, p is ptr/ref to const to T, q = const_cast<T>(p), as T is non-const *q = val is ok
          but if T const type, then *q = val is undefined      
        • reinterpret_cast<char *>(iptr), if iptr is int *, then it will convert it to char *, but any subsequent usage of assuming it as char * is useless. avoid using reinterpret_cast
