bool isPalindrome(int x){
    int y = x;
    long z = 0;
    if (x < 0)
        return false;

    while(y){
        z = z * 10 + y % 10;
        y = y / 10;
    }

    if (x == (long)z)
        return true;
    else
        return false;
}
