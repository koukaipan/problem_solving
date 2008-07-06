#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef enum{lparen, rparen, plus, minus, multiply, divide, eos, bottom, operand} precedence;

int top_opd, top_opr;
double		opd[100];
precedence	opr[100];
int			prece[8]={2,3,4,4,5,5,1,0};//precedence for operator
int			errorflag;
void		compute();
void		eval(precedence oper);	//計算
precedence  get_token();	//to reconize the token
int index = -1;
char expression[200];

int main()
{
	freopen("out.txt", "w", stdout);
	int num_case;
	gets(expression);
	for(num_case=atoi(expression); num_case; num_case--)
	{
		errorflag = 0;
		top_opd = top_opr = index = -1;
		gets(expression);
		compute();
	}

	return 0;
}

void compute()
{	
	precedence symbol;		//symbol 是從堆疊中pop出來的運算子
	precedence  token;		//token 是從運算式中被抓出來判斷的運算子/元
	double buffer;			//buffer用來存放準備push的值
	opr[++top_opr] = bottom;

	for(token=get_token(); ; token=get_token())
	{
		/*if(expression[index]==' ')
			continue;
		else*/ if(token == operand)		//運算元便直接push到 opd stack裡面
		{	
			buffer = expression[index]-'0';	//可以處理二位數以上
			while (expression[index+1]<='9' && expression[index+1]>='0')	//如果接下來還是數子
				buffer = buffer*10 + expression[++index]-'0';	//原本的數*10 + 要增加的數
			
			opd[++top_opd] = buffer;
		}

		else if(token==rparen)		//pop until lparen poped
			while( top_opr>-1 && (symbol=opr[top_opr--])!=lparen ) //當pop出來的不是左括號 //這個寫法最後可以讓左括號pop出來，且不會被eval處理到
				eval(symbol);		//pop出來一個運算子之後 就丟去計算
		else if(token==lparen)		//如果是左括號，直接push進去
			opr[++top_opr] = token;

		else						//other operator + - * / % (
		{
			while(prece[opr[top_opr]] >= prece[token])	//如果堆疊裡面的優先權>=目前要處理的運算子 就先pop出來
			{
				if(top_opr==-1)
				{
					errorflag=1;
					break;
				}
				symbol = opr[top_opr--];			//pop出運算子
				eval(symbol);				//送給eval做運算
			}
			opr[++top_opr] = token;				//push token into operator stack
		}

		if(top_opr<=-1)
		{
			break;
			errorflag = -1;
		}

		if (token==eos)		//如果是字串結束，跳出迴圈
			break;			//寫在這裡是要讓上面的token處理，可以處理最後部分的pop 否則還得另外寫
	}
	
	if(top_opd!=0)
		errorflag=1;

	if(errorflag==0)
		printf("%.0lf\n", opd[top_opd--]);
	else
		printf("ERROR\n");

	return;		//回傳最後的結果
}//end of compute funtion

void eval(precedence oper)
{
	double op1, op2;
	if(top_opd<1)
	{
		errorflag=1;
		return;
	}
	op2 = opd[top_opd--];	//運算元1
	op1 = opd[top_opd--];	//運算元2

	switch(oper)		//將作為計算的值push回去
	{
	case plus:		opd[++top_opd] = (op1+op2);
		break;
	case minus:		opd[++top_opd] = (op1-op2);
		break;
	case multiply:	opd[++top_opd] = (op1*op2);
		break;
	case divide:	opd[++top_opd] = (op1/op2);
		break;
	}/*no error checking*/

	return;
}

precedence get_token()
{
	if(expression[++index]<='9' && expression[index] >= '0')
		return operand;
	switch(expression[index])
	{
	case '(':	return lparen;
	case ')':	return rparen;
	case '+':	return plus;
	case '-':	return minus;
	case '/':	return divide;
	case '*':	return multiply;
	case '\0':	return eos;
	//case ' ':	return operand;
	default :	
		errorflag=1;
		return operand;	/*no error checking, default is operand*/
	}
} //end of get_token function
