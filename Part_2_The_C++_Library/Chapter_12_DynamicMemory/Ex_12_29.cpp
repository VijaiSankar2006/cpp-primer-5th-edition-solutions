/************************************************************************************************************************************************************
 * @file Ex_12_29.cpp
 * @brief Exercise 12.29: We could have written the loop to manage the interaction with the user as a do while (§ 5.4.4, p. 189)
 * loop. Rewrite the loop to use a do while. Explain which version you prefer and why.
 * @date 2024-01-19 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

void runQueries(ifstream& infile)
{

    TextQuery tq(infile); 
    
    do{
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
            print(cout, tq.query(s)) << endl;
    }while(true);
}

// in this particular case while() is prefered, as the condition in the loop is always true. 