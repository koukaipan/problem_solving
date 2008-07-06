#include <iostream>
#include <cstring>
#include <algorithm>

/*
尚未解決重複字串
ok->直接拿字串陣列做permutation
*/

using namespace std;

int main()
{
	ostream_iterator<char> it(cout);
	char ch[11];
	int num, i=0,/* j,*/ length;
	
	cin>>num;
	while(i<num)
	{
		//input
		cin>>ch;
		length = strlen(ch);

		//sort
		sort(ch, ch+length);
		//cout<<ch;

		//permutation
		do{
			copy(ch,ch+length,it);
		//for(j=0; j<length; j++)	//copy的執行結果等於這兩行
			//cout<<ch[j];
		cout << endl;
		// 使用 next_permutation 產生字典順序的下個排列
		}while(next_permutation(ch,ch+length));

		i++;
		cout<<endl;
	}
	return 0;
}