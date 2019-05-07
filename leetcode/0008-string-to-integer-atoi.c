int myAtoi(char * str){
    long x = 0;
    char *ptr, c;
    int negative = 0;

    /* skip leading spaces */
    ptr = str;
    while(*ptr==' ') {
        ptr++;
    }

    if (*ptr == '-') {
        ptr++;
        negative = 1;
    } else if (*ptr == '+') {
        ptr++;
    }

    /* only digits are accepted in the remaining characters */
    for(; c = *ptr; ptr++) {
        if (c < '0' || c > '9')
            break;
        x = x * 10 + c - '0';
        if (x > INT_MAX)
            return negative ? INT_MIN : INT_MAX;
    }

    return negative ? -x : x;
}
