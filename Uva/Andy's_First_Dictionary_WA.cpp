#include<iostream>
#include<string>
#include<set>
#include<cstring>
using namespace std;
const int maxn = 205;

set<string> dict;

int main (void)
{
	string s;
	char buff[maxn];
	while (cin>>s)
	{
		memset(buff, 0, sizeof(buff));
		for (int i = 0, j = 0; i < s.length(); i++)
			if (isalpha(s[i])) buff[j++] = tolower(s[i]);
		dict.insert(buff);
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
		cout<<*it<<endl;
	return 0;
}
