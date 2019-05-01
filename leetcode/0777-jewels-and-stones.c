int numJewelsInStones(char* J, char* S) {
    int cnt = 0;
    char *j;
    char *s = S;
    
    while(*s) {
        j = J;
        while (*j) {
            if (*s == *j) {
                cnt++;
                break;
            }
            j++;
        }
        s++;
    }
    return cnt;
}
