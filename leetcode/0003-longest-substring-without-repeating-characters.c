int lengthOfLongestSubstring(char* s) {
    char show[128] = {0};
    char *i = s;
    char *j;
    int len = 0, max = 0;

    j = i;
    while(*i) {
        while(*j) {
            if(show[*j] == 0) {
                show[*j] = 1;
                len++;
                j++;
            } else {
                break;
            }
        }
        if (len > max)
            max = len;
        /* we already checked str[i:end] and does not find repeated char,
         * lengthOfLongestSubstring(str[i+1:end]) is impossible to be even larger */
        if(*j == NULL)
            break;

        /* move i forward, clear i's mark */
        show[*i] = 0;
        len--;
        i++;
    }

    return max;
}
