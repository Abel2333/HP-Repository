#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

set<string> dict;

int main (void)
{
	string s, buff;
	while (cin>>s)
	{
		for (int i = 0; i < s.length(); i++)
			if (isalpha(s[i])) s[i] = tolower(s[i]);
			else s[i] = ' ';
		stringstream ss(s); //creat a stream by string s
		while (ss>>buff)
			dict.insert(buff);  //insert the buff to set
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) //it is a itreator
		cout<<*it<<endl;
	return 0;
}
				
