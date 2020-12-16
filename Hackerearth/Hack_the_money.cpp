#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	long long t,a;
	cin>>t;
	while(t--){
		cin>>a;
		int cnt1 = 0,cnt2 = 0;
		while(a%10==0){
			a/=10;
			cnt1++;
		}
		while(a%2==0){
			a/=2;
			cnt2++;
		}
		if(a>1 || cnt1<cnt2){
			cout<<"No\n";
			continue;
		}
		else{
			cout<<"Yes\n";
		}
	}
	return 0;
}