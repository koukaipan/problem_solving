/*C++�� container*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
using namespace std;
main()
{
    set<string> dict;
    string s="";
    char c;
    while(scanf("%c",&c)!=EOF)
        if(isalpha(c) )	//�p�G�O�r���N��W�r��
            s+=tolower(c) ;
        else if(s!="")	//�p�G���O�r��  �B���O�Ŧr��N�[�Jset��
		{
            dict.insert(s);
            s="";
        }
    set<string>::iterator p;
    for(p=dict.begin();p!=dict.end();p++)
        cout<<*p;
		
}
