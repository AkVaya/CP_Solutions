#include<bits/stdc++.h>
using namespace std;
const long long nax = 1e5 + 69 ;
long long n,k;
bool check(long long val){
	long long currk = k, pages = val;
	while(val/currk){
		pages+=val/currk;
		currk*=k;
	} 
	return pages>=n;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    long long l = 0,r = 1e18;
    while(l<=r){
    	long long mid = (l+r)/2;
    	if(check(mid))
    		r = mid - 1;
    	else l = mid + 1;
    }
    cout<<r + 1<<'\n';
    return 0;
}