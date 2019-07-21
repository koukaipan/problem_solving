#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define is_digit(c) (c >= '0' && c <= '9')
#define max_stack 8
#define max_length 2048

int copy_back(char* src, int src_len, int repeat, char* dst, int dst_start)
{
	int k;
	for (k = 0; k < repeat; k++) {
		memcpy(&dst[dst_start], src, src_len);
		dst_start += src_len;
	}
	return dst_start;
}

char * decodeString(char * s){
	char *output = malloc(sizeof(char) * max_length);
	char **stack = malloc(sizeof(char*) * max_stack);
	int *cnt = malloc(sizeof(int) * max_stack);
	int *stack_len = malloc(sizeof(int) * max_stack);
	int i, j, depth = -1;
	int __cnt = 0;

	for (i = 0, j = 0; s[i]; i++) {
		if (!is_digit(s[i]) && s[i] != '[' && s[i] != ']' && depth == -1) {
			/* normal case, just copy */
			output[j++] = s[i];
		} else {
			if (is_digit(s[i])) {
				/* get deeper, covert int string to int */
				__cnt = __cnt * 10 + s[i] - '0';
			} else if (s[i] == '[') {
				/* start a new stack */
				depth++;
				stack[depth] = malloc(sizeof(char) * max_length);
				stack_len[depth] = 0;
				cnt[depth] = __cnt;
				__cnt = 0;
			} else if (s[i] == ']') {
				if (depth >= 1) {
					stack_len[depth-1] = copy_back(stack[depth], stack_len[depth],
									cnt[depth],
									stack[depth-1], stack_len[depth-1]);
				} else {
					/* at depth=0, copy back to output */
					j = copy_back(stack[depth], stack_len[depth],
							cnt[depth],
							output, j);
				}
				free(stack[depth]);
				depth--;
			} else {
				/* alphabet in bracket, append to current stack */
				stack[depth][stack_len[depth]] = s[i];
				stack_len[depth]++;
			}
		}
	}
	output[j] = '\0';

	free(stack);
	free(stack_len);
	return output;
}

char *inputs[] = {
	"23[abc34[cd]]56[xy]",
	"abc2[x]",
	"3[a]2[bc]",
	"3[a2[c]]",
	"2[abc]3[cd]ef",
	"10[a2[x]3[y]]",
	""
};

int main()
{
	int i;
	char *p;
	for (i = 0; inputs[i][0]; i++) {
		printf("%s\n", inputs[i]);
		p = decodeString(inputs[i]);
		printf("%s\n", p);
		free(p);
	}

	return 0;
}
