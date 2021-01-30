#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int x[n],pos[n],t[n],res = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>t[i]>>x[i];
			pos[i] = 0;
		}
		int to = x[0],curr = 0;
		for (int i = 1; i < n; ++i)
		{
			if(abs(to-curr)<=t[i]-t[i-1]){
				pos[i] = to;
				curr = to;
				to = x[i];
			}
			else if(to<curr){
				curr -= (t[i]-t[i-1]);
				pos[i] = curr;
			}
			else{
				curr += t[i] - t[i-1];
				pos[i] = curr; 
			}
		}
		for (int i = 0; i < n-1; ++i)
		{
			if((pos[i+1]<=x[i] && pos[i]>=x[i]) || (pos[i+1]>=x[i] && pos[i]<=x[i]) )
				res++;
		}
		if((curr<=to && to>=x[n-1] && x[n-1]>=curr) || (curr>=to && to<=x[n-1] && x[n-1]<=curr) )
				res++;
		cout<<res<<'\n';
	}
	return 0;
}