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
void		eval(precedence oper);	//�p��
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
	precedence symbol;		//symbol �O�q���|��pop�X�Ӫ��B��l
	precedence  token;		//token �O�q�B�⦡���Q��X�ӧP�_���B��l/��
	double buffer;			//buffer�ΨӦs��ǳ�push����
	opr[++top_opr] = bottom;

	for(token=get_token(); ; token=get_token())
	{
		/*if(expression[index]==' ')
			continue;
		else*/ if(token == operand)		//�B�⤸�K����push�� opd stack�̭�
		{	
			buffer = expression[index]-'0';	//�i�H�B�z�G��ƥH�W
			while (expression[index+1]<='9' && expression[index+1]>='0')	//�p�G���U���٬O�Ƥl
				buffer = buffer*10 + expression[++index]-'0';	//�쥻����*10 + �n�W�[����
			
			opd[++top_opd] = buffer;
		}

		else if(token==rparen)		//pop until lparen poped
			while( top_opr>-1 && (symbol=opr[top_opr--])!=lparen ) //��pop�X�Ӫ����O���A�� //�o�Ӽg�k�̫�i�H�����A��pop�X�ӡA�B���|�Qeval�B�z��
				eval(symbol);		//pop�X�Ӥ@�ӹB��l���� �N��h�p��
		else if(token==lparen)		//�p�G�O���A���A����push�i�h
			opr[++top_opr] = token;

		else						//other operator + - * / % (
		{
			while(prece[opr[top_opr]] >= prece[token])	//�p�G���|�̭����u���v>=�ثe�n�B�z���B��l �N��pop�X��
			{
				if(top_opr==-1)
				{
					errorflag=1;
					break;
				}
				symbol = opr[top_opr--];			//pop�X�B��l
				eval(symbol);				//�e��eval���B��
			}
			opr[++top_opr] = token;				//push token into operator stack
		}

		if(top_opr<=-1)
		{
			break;
			errorflag = -1;
		}

		if (token==eos)		//�p�G�O�r�굲���A���X�j��
			break;			//�g�b�o�̬O�n���W����token�B�z�A�i�H�B�z�̫᳡����pop �_�h�ٱo�t�~�g
	}
	
	if(top_opd!=0)
		errorflag=1;

	if(errorflag==0)
		printf("%.0lf\n", opd[top_opd--]);
	else
		printf("ERROR\n");

	return;		//�^�ǳ̫᪺���G
}//end of compute funtion

void eval(precedence oper)
{
	double op1, op2;
	if(top_opd<1)
	{
		errorflag=1;
		return;
	}
	op2 = opd[top_opd--];	//�B�⤸1
	op1 = opd[top_opd--];	//�B�⤸2

	switch(oper)		//�N�@���p�⪺��push�^�h
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
