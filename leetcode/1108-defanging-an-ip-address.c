char * defangIPaddr(char * address){
    char *str = (char*)malloc(24);
    char *p = address;
    int i = 0;
    while(*p) {
        if (*p == '.') {
            str[i] = '[';
            str[i+1] = '.';
            str[i+2] = ']';
            i += 3;
        } else {
            str[i] = *p;
            i++;
        }
        p++;
    }
    str[i] = '\0';
    return str;
}
