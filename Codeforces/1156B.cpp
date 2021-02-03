#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 69;
const int M = 1e9 + 7;
using ll = long long;
bool check(string s){
	for (int i = 1; i < s.length(); ++i)
		if(abs(s[i]-s[i-1])==1)
			return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		vector<int> cnt(26,0);
		vector<char>v1,v2;
		for (auto i : s){
			if((i-'a')%2)
				v1.push_back(i);
			else
				v2.push_back(i);
			cnt[i-'a']++;
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		string s1="",s2="";
		for(auto i : v1)
			s1+=i;
		for(auto i : v2)
			s2+=i;
		if(check(s1+s2))
			cout<<s1+s2<<'\n';
		else if(check(s2+s1))
			cout<<s2+s1<<'\n';
		else
			cout<<"No answer\n";
	}
	return 0;
}