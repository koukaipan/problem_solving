/* greedy
   min heap 
   pop the minimal 2 num, 
   push sum to heap
   */
#include <queue>
#include <algorithm>
#include <cstdio>
#define MAX 5002
using namespace std;


main()
{
	int n, arr[MAX];
	int tmp, i, a, b, cost;
	//priority_queue <int, vector<int>, greater<int> > q;
	freopen("10954.txt", "r", stdin);
	while(scanf("%d", &n) && n)
	{
		//q = priority_queue <int, vector<int>, greater<int> >();
		cost = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
			/*scanf("%d", &tmp);
			q.push(tmp);*/
		}

		//make heap
		make_heap(&arr[0], &arr[n], greater<int>());

		//min heap faster
		i=n;
		while(i>1)
		{
			a = arr[0];
			pop_heap(&arr[0], &arr[i--], greater<int>());
			b = arr[0];
			pop_heap(&arr[0], &arr[i--], greater<int>());
			tmp = a + b;
			cost += tmp;
			arr[i++] = tmp;
			push_heap(&arr[0], &arr[i], greater<int>());
		}
		//piority queue
		/*while(q.size()>1)
		{
			a = q.top(), q.pop();
			b = q.top(), q.pop();
			tmp = a+b;
			cost += tmp;
			q.push(tmp);
		}*/
		printf("%d\n", cost);
		

	}
}
