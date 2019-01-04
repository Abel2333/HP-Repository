#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string, int> cnt;
vector<string> words;

string repr(const string& s)  //make all words standardization then all qualified words is same
{
	string ans = s;
	for (int i = 0; i < ans.length(); i++)
		ans[i] = tolower(ans[i]);
	sort(ans.begin(), ans.end());
	return ans;
}

int main (void)
{
	int n = 0;
	string s;
	while (cin>>s)
	{
		if (s[0] == '#')
			break;
		words.push_back(s);  //recording the original words
		string r = repr(s);
		if (!cnt.count(r))
			cnt[r] = 0;  //we haven't let all units initialize to 0
		cnt[r]++;  //recording the times of qualified words
	}
	vector<string> ans;
	for (int i = 0; i < words.size(); i++)
		if (cnt[repr(words[i])] == 1)
			ans.push_back(words[i]);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<endl;
	return 0;
}
