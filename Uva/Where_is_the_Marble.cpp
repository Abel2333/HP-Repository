#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10000;

int main (void)
{
	int n, m, marb[maxn] = {0}, kase = 0;
	while (cin>>n>>m && (n || m))
	{
		cout<<"CASE# "<<++kase<<':'<<endl;
		for (int i = 0; i < n; i++)
			cin>>marb[i];
		sort(marb, marb+n);
		while (m--)
		{
			int x = 0;
			cin>>x;
			int p = lower_bound(marb, marb+n, x) - marb;
			if (marb[p] == x) cout<<x<<" found at "<<p+1<<endl;
			else cout<<x<<" not found"<<endl;
		}
	}
	return 0;
}
