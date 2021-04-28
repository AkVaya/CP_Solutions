#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s, res;
		cin>>s;
		int n = s.length();
		vector<int> fir,sec;
		int a = 0, b = 0;
		for(int i = 0; i < n; ++i)
			if((s[i]-'0')%2)
				fir.push_back(i);
			else
				sec.push_back(i);
		while(a<fir.size() && b<sec.size()){
			if(s[fir[a]]<s[sec[b]])
				res+=s[fir[a++]];
			else
				res+=s[sec[b++]];
		}
		while(a<fir.size())
			res+=s[fir[a++]];	
		while(b<sec.size())
			res+=s[sec[b++]];	
		cout<<res<<'\n';
	}
	return 0;
}