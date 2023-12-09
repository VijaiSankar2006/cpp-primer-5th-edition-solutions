# EXPRESSIONS
>   **expression** is composed of **one or more** operands, when evaluated yeilds a **result**. The simplest form of 
>   expression is a **single literal or a single variable**, the result of such expression is value of the variable or
>   literal. A lvalue is a reference to an object and an rvalue is contents of the object

####    decltype
>   **decltype(expression)**     
>   if expression yeilds a lvalue, then the type is a reference as lvalue is nothing but a reference     
>   but *decltype(variable)* is not a reference, as here decltype doesn't evaluate a variable so it just the type of the 
>   variable. Only an **expression** is evaluted.
>   if p is a int \*, 
        decltype(*p) yields reference to the int object as '\*' yields lvalue.       
        decltype(p) yields int *, type of p is int *.          
        decltype(&p) yields int **, as '&' yields an pointer to the object, here the pointer is pointer to int, so we get
        int **.
>   decltype(rvalue) yields the type of the rvalue.