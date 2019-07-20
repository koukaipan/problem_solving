#include <stdio.h>
#include <string.h>

int __find_substring(char *s, int left, int right, int len)
{
	int cnt = 0;
	while(left >= 0 && right < len) {
		if (s[left] != s[right])
			return cnt;

		cnt++;
		left--;
		right++;
	}

	return cnt;
}

int countSubstrings(char * s){
	int i, cnt, len = strlen(s);

	cnt = len;
	for (i = 0; i < len; i++) {
		/* odd length */
		cnt += __find_substring(s, i-1, i+1, len);
		/* even length */
		cnt += __find_substring(s, i, i+1, len);
	}

	return cnt;
}

char *inputs[] = {
	"abc",
	"aaa",
	"xyyz",
	"xyzzy",
	""
};

int main()
{
	int i;
	for (i = 0; strlen(inputs[i]); i++) {
		printf("%s\n", inputs[i]);
		printf("%d\n", countSubstrings(inputs[i]));
	}

	return 0;
}
