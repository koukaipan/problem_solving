char* toLowerCase(char* str) {
    char *ptr = str;
    while (*ptr) {
        if (*ptr >= 'A' && *ptr <='Z')
            *ptr = *ptr + 32;
        ptr++;
    }
    return str;
}
