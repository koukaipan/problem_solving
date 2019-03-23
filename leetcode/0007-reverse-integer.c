int reverse(int x) {
	int i, j, negative=0;
	long l = 0;

	if (x == INT_MAX || x == INT_MIN)
		return 0;

	if (x < 0) {
		negative = 1;
		x = -x;
	}
	while(x) {
		l = l * 10 + (x % 10);
		x = x / 10;
	}

	if (negative)
		l = -l;

	if (l > INT_MAX || l < INT_MIN)
		l = 0;

	return (int)l;
}
