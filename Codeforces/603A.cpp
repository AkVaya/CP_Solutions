#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int a[nax], b[nax], c[nax], res[nax];
vector<vector<int> > v;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt = 1;
	for (int i = 1; i < n; ++i)
		if(s[i]!=s[i-1])
			cnt++;
	cout<<min(cnt+2,n)<<'\n';
	return 0;
}