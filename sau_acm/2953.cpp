#include<iostream>
using namespace std;

int main (void)
{
	int t;
	cin>>t;
	while (t--)
	{
		int x, y;
		cin>>x>>y;
		if (y < 1) cout<<"No"<<endl;
		else if (x != 0 && y == 1) cout<<"No"<<endl;
		else if (x < y-1 && y != 1) cout<<"No"<<endl;
		else if ((x-(y-1)) % 2) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
