#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	string s;
	vector<bool>v(n+1,true);
	cin>>s;
	int cnt = 0,ind = 0,m = s.length(),i=1;
	while(cnt!=n-1){
		//cout<<ind<<' '<<i<<endl;
		bool check=true;
		if(s[ind]=='y' && v[i]){
			v[i]=false;
			cnt++;
		}
		ind++;
		i++;
		if(i==n+1)
			i=1;
		if(ind==m)
			ind=0;
		while(!v[i]){
			i++;
			if(i==n+1)
				i=1;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if(v[i])
			cout<<i<<endl;
	}
	return 0;
}