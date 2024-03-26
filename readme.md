# Solutions to **C++ Primer 5th Edition** by Stanley B. Lippman, Josée Lajoie, Barbara E. Moo 
This repositor contains solutions to almost all exercises in **C++ Primer 5th edition** book and also some exercises I tried on my own. Please do inform about any corrections.

# [Project : DBMS](DBMS)
A simple dbms which accepts SQL to
1. Create table 
    CREATE table table_name
2. Save table to file
3. Get **data type** of the information from the user at run time.
    * int
    * double
    * char
    * string
    all the above types are supported         
List of SQL Operations supported
1. SELECT : user can select which fields of information from the table to be displayed        
    ` SELECT *` // * implies all coloumns.
    * SELECT col1, col2
2. FROM : It handles the table from which information needs to be provided
    * FROM table_name
3. WHERE : It helps to filter specific records from the table
    * **relational operators supported**
    * = equal to, returns records with the value equal to provided
    * != not equal to, returns records with the value not equal to provide
    * < lesser than, returns records with the value lesser than provided 
    * \> greater than, returns records with the value greater than provided   
    * <= lesser than, returns records with the value lesser than or equal to provided
    * \>= greater than, returns records with the value greater than or equal to provided
    * **logical operators supported**
    * AND, returns the records which satisfies both the constraints 
    * OR, returns the records which satisfies either or the other constraints
    * NOT, returns the records which didn't satisfy the constraint
    all the above operators and operations are supported.
    * WHERE col1 \<relational operator> val
    * WHERE \<logical operator> col1 \<relational operator> col2       
    `WHERE NOT age >= 45 AND gender = f OR city = chennai`
4. ORDER_BY : sorts the list in ascending order by default.
    * DESC, sorts the list in descending order        
    ` ORDER_BY emp_id`         
     `ORDER_BY emp_id DESC ` 
        
    ```SQL
    ex : 
        SELECT * 
        FROM employees
        WHERE join_yr < 2012 AND NOT gender = f OR city = chennai
        ORDER_BY emp_id DESC
    ```
5. HELP : 
   * HELP ALL : lists all suported commands
   * HELP <command> : displays information about the specified command     
6. OPEN : OPEN <file_name> , loads Table from the file.   
7. ADD : adds records to the Table.
8. DELETE : delets a record from the Table

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/vijaishankar/CPP-Primer-5th-Edition-Solutions">CPP-Primer-5th-Edition-Solutions</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/vijaishankar">Vijai Sankar S</a> is marked with <a href="http://creativecommons.org/publicdomain/zero/1.0?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC0 1.0 Universal<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/zero.svg?ref=chooser-v1"></a></p>
