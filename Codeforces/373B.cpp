#include<bits/stdc++.h>
using namespace std;
const long long nax = 69;
long long w,m,k,cnt=0;
long long binpow(long long a,long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res*a);
        a = (a*a);
        b >>= 1;
    }
    return res;
}
bool check(long long val){
    long long curr = m,x= cnt,cost=0;
    while(curr != val){
        long long temp = min(binpow(10,x),val);
        cost += (temp-curr)*x;
        x++;
        curr = temp;
        if(cost>w)
        	return false;
    }
    return cost<=w;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>w>>m>>k;
    w/=k;
    long long l = m , r = 1e18,temp = m;
    while(temp){
    	cnt++;
    	temp/=10;
    }
    while(l<=r){
    	long long mid = l + (r-l)/2;
    	if(check(mid))
    		l = mid + 1;
    	else
    		r = mid - 1;
    }
    cout<<l-m-1<<'\n';
}