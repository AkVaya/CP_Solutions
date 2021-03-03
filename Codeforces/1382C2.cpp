#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		vector<int> v1,v2;
		for (int i = 0; i < n-1; ++i)
		{
			if(a[i]!=a[i+1])
				v1.push_back(i);
			if(b[i]!=b[i+1])
				v2.push_back(i);
		}
		if(a[n-1]=='1')
			v1.push_back(n-1);
		if(b[n-1]=='1')
			v2.push_back(n-1);
		cout<<v1.size()+v2.size()<<' ';
		for(auto i : v1)
			cout<<i+1<<' ';
		for(int i = v2.size()-1; i >= 0; --i)
			cout<<v2[i]+1<<' ';
		cout<<'\n';
	}
   	return 0;
}