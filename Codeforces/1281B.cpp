#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
bool cmp(const pair<char,int> &a, const pair<char,int> &b){
	if(a.first!=b.first)
		return a.first<b.first;
	return a.second>b.second;
}
int main(){
	int t;
	cin>>t; 
	while(t--){
		string s,t;
		cin>>s>>t;
		multiset<char> v;
		for(int i = 0; i < s.length(); ++i)
			v.insert(s[i]);
		char diff = '#';
		int ind = 0;
		for(int i = 0; i < s.length(); ++i){
			auto it = v.begin();
			if(*it!=s[i]){
				ind = i;
				diff = *it;
				break;
			}
			v.erase(it);
		}
		if(diff!='#')
			for(int i = s.length()-1; i >= 0; --i){
				if(diff==s[i]){
					swap(s[ind],s[i]);
					break;
				}
			}
		if(s<t)
			cout<<s<<'\n';
		else
			cout<<"---\n";
	}
	return 0;
}