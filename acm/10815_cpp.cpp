/*C++的 container*/

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
        if(isalpha(c) )	//如果是字母就串上字串
            s+=tolower(c) ;
        else if(s!="")	//如果不是字母  且不是空字串就加入set中
		{
            dict.insert(s);
            s="";
        }
    set<string>::iterator p;
    for(p=dict.begin();p!=dict.end();p++)
        cout<<*p;
		
}
