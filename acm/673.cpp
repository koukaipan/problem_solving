#include <stdio.h>

#define MAX 129

typedef struct{
	int top;
	char data[MAX];
}stack;

void init_stack(stack *s);
void push(stack *s, char v);
char pop(stack *s);
int empty(stack *s);
int full(stack *s);

main()
{
	stack s;
	char line[MAX];
	int i, num_case;
	int flag;
	freopen("673.txt", "r", stdin);

	for(scanf("%d%c", &num_case, &i); num_case; num_case--)
	{
		/* initialize */
		flag = 1;
		init_stack(&s);

		/* input */
		gets(line);
		
		/* process */
		for(i=0; line[i]&&flag; i++)
		{
			switch(line[i])
			{
			case '(':
			case '[':
				push(&s, line[i]);
				break;
			case ')':
				if(empty(&s) || pop(&s) != '(')	flag = 0;
				break;
			case ']':
				if(empty(&s) || pop(&s) != '[')	flag = 0;
				break;
			/*default:*/
			}
		}
		if(!empty(&s))
			flag = 0;

		/* output */
		printf("%s\n", flag ? "Yes" : "No");
	}
}

void init_stack(stack *s)
{
	s->top = -1;
}
void push(stack *s, char v)
{
	s->top++;
	s->data[s->top] = v;
}
char pop(stack *s)
{
	return s->data[s->top--];
}
int empty(stack *s)
{
	return s->top == -1;
}
int full(stack *s)
{
	return s->top == MAX-1;
}