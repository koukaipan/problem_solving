#include <stdio.h>

char code2char(char ch[])
{
	/*  | o   .  o|
	    01234567890  */
	char c=0;
	//c += 128*(ch[1]=='o'?1:0);
	c += 64*(ch[2]=='o'?1:0);
	c += 32*(ch[3]=='o'?1:0);
	c += 16*(ch[4]=='o'?1:0);
	c +=  8*(ch[5]=='o'?1:0);
	c +=  4*(ch[7]=='o'?1:0);
	c +=  2*(ch[8]=='o'?1:0);
	c +=  1*(ch[9]=='o'?1:0);
	return c;
}

int main()
{
	char ch[12];

	gets(ch);
	while(gets(ch))
		if(ch[0]!='_')
			printf("%c", code2char(ch));
		else
			break;

	return 0;
}


/*

a  oo**.**o    A  o***.**o 
b  oo**.*o*    B  o***.*o* 
c  oo**.*oo    C  o***.*oo 
d  oo**.o**    D  o***.o** 
e  oo**.o*o    E  o***.o*o 
f  oo**.oo*    F  o***.oo* 
g  oo**.ooo    G  o***.ooo 

h  oo*o.***    H  o**o.*** 
i  oo*o.**o    I  o**o.**o 
j  oo*o.*o*    J  o**o.*o* 
k  oo*o.*oo    K  o**o.*oo 
l  oo*o.o**    L  o**o.o** 
m  oo*o.o*o    M  o**o.o*o 
n  oo*o.oo*    N  o**o.oo* 
o  oo*o.ooo    O  o**o.ooo 

p  ooo*.***    P  o*o*.*** 
q  ooo*.**o    Q  o*o*.**o 
r  ooo*.*o*    R  o*o*.*o* 
s  ooo*.*oo    S  o*o*.*oo 
t  ooo*.o**    T  o*o*.o** 
u  ooo*.o*o    U  o*o*.o*o 
v  ooo*.oo*    V  o*o*.oo* 
w  ooo*.ooo    W  o*o*.ooo 

x  oooo.***    X  o*oo.*** 
y  oooo.**o    Y  o*oo.**o 
z  oooo.*o*    Z  o*oo.*o* 
*/