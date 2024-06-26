/*  Exercise 5.13: Each of the programs in the highlighted text on page 184 contains a common programming error.
 *  Identify and correct each error*/

(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {                       //  this program will work correctly if and only all characters are vowels 
        case ’a’: aCnt++; break;        //  break is added
        case ’e’: eCnt++; break;        //  break is added
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    int ix;                             //  ix is declared outside
    switch (index) {
        case 1:
    //  int ix = get_value();           //  compiler won't to allow this declaration as ix is used in default
        ix = get_value();
        ivec[ ix ] = index;
        break;
        default:
        ix = ivec.size()-1;
        ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1 : case 3 : case 5 : case 7 : case 9:    //    each case label should be defined as[ case lbl_name : ]
        oddcnt++;
        break;
        case 2 : case 4 : case 6 : case 9:  case 10:
        evencnt++;
        break;
    }
(d) const unsigned ival=512, jval=1024, kval=4096;      // case labels must be integral constant expressions
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
        bufsize = ival * sizeof(int);   
        break;
        case jval:
        bufsize = jval * sizeof(int);
        break;
        case kval:
        bufsize = kval * sizeof(int);
        break;
    }
