#include<bits/stdc++.h>
using namespace std;

int main (void)
{
	int n, q;
	while (cin>>n>>q)
	{
		int x0, y0, sum = 0;
		cin>>x0>>y0;
		while (q--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			if (abs(x) == abs(x0) || abs(y) == abs(y0))
				sum++;
			else if (abs(y-y0) == abs(x-x0))
				sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
