#include <iostream>
#include <cstring>
#include <algorithm>

/*
�|���ѨM���Ʀr��
ok->�������r��}�C��permutation
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
		//for(j=0; j<length; j++)	//copy�����浲�G����o���
			//cout<<ch[j];
		cout << endl;
		// �ϥ� next_permutation ���ͦr�嶶�Ǫ��U�ӱƦC
		}while(next_permutation(ch,ch+length));

		i++;
		cout<<endl;
	}
	return 0;
}