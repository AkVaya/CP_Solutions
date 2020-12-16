#include<bits/stdc++.h>
using namespace std;
const long long nax = 2e5 + 69;
long long n;
bool check(long long val){
	long long curr = min(val,n);
	long long temp = n;
	temp -= curr;
	//cout<<val<<endl;
	while(temp){
		temp-=temp/10;
		curr += min(val,temp);
		temp-= min(val,temp);
	}
	return curr>=((n+1)/2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    long long l = 1,r = n+1;
    while(l<=r){
        long long mid = (l+r)/2;
        if(check(mid))
        	r = mid - 1;
        else l = mid + 1;
    }
    cout<<r+1<<'\n';
    return 0;
}