### Assigning out of range value to a unsinged integer
    value wraps around the range 
    (ie) unsigned char ch; ( 0 - 255 )
    ch = 256 = 0;
    ch = 257 = -1;
    ch = -1 = 255;
    ch = -2 = 254;
    ---------------------

### Assigning out of range value to a singned integer
    The result is undefined, even if the program works it is not guaranteed to work the same.

# Undefined behaviour :
    even if program compiles, it is not guaranteed to work the same with compiler updates or other compilers. It is always in error

# Implementation defined :
    using something that is implementation defined makes the program un-portable. For example sizeof(int) is not same across machines, as compiler vendors can free in implementation

- Both *undefined behaviour* and *implementation defined* should be avoided in programs.

# Implicit type conversions
when **signed** and **unsigned** is mixed in an expression, *signed* is always converted to *unsigned*      
    unsigned int m = 10;      
    int n = -1;       
    m + n != 9;      
    m + n = wraps around the range of unsigned int.       

# Literals
## integer literal 
     decimal, octal and hexadecimal literals.
     By default decimal literals are signed, it will be int < long < long long
     octal and hexadecimal literals can be signed or unsigned. the types can be
     * int , unsigned int
     * long , unsigned long
     * long long, unsigned long long
     in which ever the value fits

     there is no literal of short 
## floating point literal
    By default floating point literal is double
## char and string literal 
    a string literal is array of const chars, 
    compiler appends '\0' - null character at the end of every string literal to mark its end
    two string literal that appear in same line is concatinated in to single literal by the compiler

# Escape sequences 
    newline         \n      
    horizontal tab  \t
    alert (bell)    \a
    vertical tab    \v
    backspace       \b 
    double quote    \"
    backslash       \\ 
    question mark   \? 
    single quote    \’
    carriage return \r 
    formfeed        \f
    \x followed by one or more hexa decimal digits 
    \ followed by one, two, three octal digits

### Bool and Pointer literals
    true and false are bool literals
    nullptr is pointer literals

# Specifying type of a literal

    Character and Character String Literals
        Prefix    Meaning Type   
            u       Unicode 16 character char16_t
            U       Unicode 32 character char32_t
            L       wide character wchar_t
            u8      utf-8 (string literals only) char
            
    Integer Literals        Floating-Point Literals
    Suffix   Minimum Type           Suffix  Type
    u or U      unsigned            f or F  float
    l or L      long                l or L  long double
    ll or LL    long long

# Initialisation 

**Initialisation :** variable is given a value when it is created       
**Assignment :** old value is deleted and replaced by a new value      
There are *four* ways to initialise a variable    

    int a = 0;
    int a = {0};
    int a{0};
    int a(0);

    {} list initialisation, it differs from the rest of the methods by *not allowing* narrowing conversions where loss of information happens like
    int i = {3.14}  //  error, here we are assigning double to int where the value will be truncated  
    int i{3.14}     //  error
    int i = 3.14    //  ok
    int i(3.14)     //  ok

**default initialisation** when we don't initialise a variable, it is default initialised      
*built-in type* is given **0**, if it is defined outside any function, and *undefined* if defined inside a function     
it is an *error* to access the value of the variable which is undefined.      
*Objects of class type* which are uninitialised have a value defined by the class.  

### definition
    it specifies 
    - the type name ,
    - variable name ,
    - gives a value if specified
### declaration
    - it makes a name known to the program
    - if a variable is defined in another file, then to use it, it must be declared in the current file
    - we declare a variable defined elsewhere using the keyword 'extern'
    - a variable can be declared any no of times but should be defined only once.

## static typing
    c++ is a statically typed language, which means types are checked at compile time, it is known as type checking

# Scope 
> **scope** is a point of program in which is name has a specific meaning, it is usually delimited by curly braces {}     
> **global scope** names defined *outside* any function, will be visible through out the code       
> **block scope** names defined *inside* a function or a block, will be visible from the point of declaration till the end of the block.     

# Declaration   
**declaration** specifies type name and list of variable names of that type. But indepth it is as follows 
> **declaration** consists of **base type** followed by a list of **declarators**, each declarator names a variable and gives the variable the type that is related to the base type. 

### Reference
> ***reference*** is a another name to an existing object, when we define a reference the declarator will be of the form 
> &d, where '&' is a type modifier
> when we *initialise* a reference we bind the reference to its initialiser, and there is no way we can rebind the  reference to another object, therefore a reference should be initialised.
> reference is not an object, its just a name alias, so we cannot have a pointer to reference and no array of references, as reference doesn't have a address.

### Pointer 
> ***pointer*** are types that point to another object. a pointer can point to
> to an **object**
> to a location just **immedietly past** the object
> can be a **nullptr**, will point to no address
> an invalid pointer, which is not the above three
    declarator will be of the form *p, where '*' is a type modifier
> as pointer is an *object*, we can have reference to a pointer
>> int *&r = p, where r is reference to a pointer that point to an object of type int
>> r gives the address stored in the pointer
>> *r deferences the pointer which in-turn yields the object

# Top-level const and Low-level const
> *pointer* is an object that can point to different object, so we can speak whether pointer is const or object is const indepently
> when *pointer* itself is *const*, it is **top level** const.
> when *pointer* can point to a *const object*, it is **low level** const
>> ## Top-level const
>> when the object **itself** is const, it can be
>> 1) built-in type
>> 2) compound type - pointer, reference
>> 3) class type
>> ## Low-level const     
>> when the pointer can **point to const object**, it appears in ***base type*** of compound types like pointers, references       
>> - const int *p, const is low level const      
>> - const int *const p, p has both low level and top level const     
>> - simply, in types **reference to const** and **pointer to const** , const is lowlevel       
>> - as references are not objects, there is no const reference, so const is always low level.      
***top level, low level*** matters only when we copy object.        
>> - when we copy an object, top level is *ignored* as copied object is *not modified*       
>> - but if copied object is low level const qualified, then the copying object needs to be low level qualified 

## Const-expressions
> *const-expressions* are the expressions that can be evaluated at *compile time* 
> const int j = 32, 42, const int k = j, are const expressions
> when we want to define a obect as const, we can make the compiler to verify it by using **constexpr** keyword
> **literal types** are the types used to initialise the **variable** declared as constexpr.
>> arithmatic, pointer, references are literal types 
> for the pointer to be a constexpr, the address that it is initialised must be a **fixed address**
> objects defined with in functions dont have address fixed, but variable defined ***outside all functions*** and defined as static have fixed address 
> constexpr functions can be used to initialise.
> const int *p, constexpr int *p, are not same as constexpr implies a top level const by default, so
> - const int *p, p is pointer to const int, const is lowlevel
> - constexpr int *p, p is const pointer to int       

## Type alias
> **type alias** is another name to the type, it can be created in two ways        
> 1) **typedef**

    typedef double rupees               here rupees is another name to double        
    typedef double price, *d_ptr        price is another name double,   
                                        d_ptr is another name for double *, '*' is a typemodifier, it modifies the base type  
> 2) **using**        

    using rupees = double         
    using d_ptr = double *      
> we can use **type alias** where ever type name is expected

    rupees salary, cost_price, *interest;        
    price net_amout, gross_amout;      
    d_ptr d = &dval;       
         *d = 6.7;      
         std::cout << *d << std::endl;       
         
> when **const** applied with typedef       

    typedef int number, *ptint;      
    const number age = 32;      //  const keyword qualifies the number type, so age is const int      
    const ptint p1;             //  const qualifies (int *), as const(pointer to int), which becomes const pointer to int
                                    so p1 is const pointer to int      
                                 
    if we just replace ptint with int *, then       
        const ptint p1;      
        const int *p1;           // here p1 becomes pointer to const int which is wrong         
    const used in type alias names makes the type being defined const       

# Decltype 
**decltype** returns the type from analysing the expression without evaluation it    

    int k;      
    const int ci = 0, *ciptr = &ci, &r = ci;     
    decltype(ci) j = 0, here decltype returns 'const int' as type of 'ci' is const int, 'ci' is not evaluated      
    decltype(r) a_name, here decltype returns 'const int &', 'r' type is const int &, again 'r' is not evaluated like auto       
    but,      
    decltype(ciptr) pt2; type returned is const int *        
    decltype(*k) , here dereferencing returns the object which is lvalue which can be assigned, so the type is int &     
    decltype(k) num, type is int      
    decltype((k)), here a variable inside double parantheses,'()' is considered as an expression, a variable is an 
                    expression that can be left hand side of the assignment, so the type returned is int &.   
    decltype(45) num, 45 is not id-expression, so the type returned is type of the literal, so it is int     

# TYPES 
> - **Built-in types** types that are closely defined related to machines hardware
> - **Compound types** types that are defined in terms of another type
>> ### Built-in types 
>> **Arrithmatic types** 
>> 1) Integral types - int, char, bool.
>> 2) floating point types - float
>> ### Compound types
>> 1) pointers - a type that stores the address of other type
>> 2) reference - a name alias for an existing object
>> 3) pointer to const - pointer which points to const object, const is low level and integral part to the type
>> 4) reference to const - reference which is binded to const object, const is low level and integral part to the type

## auto
- deduces the type from the initialiser, 
    int i, &r = i;
    auto n = r  //  the type of n is int, as r is an alias for the i, so when we use reference as initialiser, the type of the object it refers is the type of the variable.

    const string s = "keep out";
    for( auto &ch : s ){ /* */ }
    //  auto deduces the type of ch as 'const char', as reference to object which is const is low-level so the reference is binded to const char