#include<bits/stdc++.h>
using namespace std;
const int nax = 5e2 + 69;
int n,a[nax],k;
bool check(long long val){
	int cnt = 1,curr=0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i]>val)
			return false;
		if(curr+a[i]<=val)
			curr+=a[i];
		else{
			curr = a[i];
			cnt++;
		}
	}
	if(val==99)
		cout<<cnt<<endl;
	return cnt<=k;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,t1=1;
    cin>>t;
    while(t--){
    	cin>>n>>k;
    	long long sum = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>a[i];
    		sum+=a[i];
    	}
    	long long l = 0,r = sum;
    	while(l<=r){
    		long long mid = (l+r)/2;
    		if(check(mid))
    			r = mid-1;
    		else l = mid + 1; 
    	}
    	long long curr = 0;
    	unordered_set<int> pos;
    	for (int i = n-1; i >= 0; --i)
    	{
    		if(curr+a[i]<=r+1)
				curr+=a[i];
			else{
				curr = a[i];
				pos.insert(i);
			}
    	}
    	int temp = 0;
    	while(pos.size()<k-1){
    		if(!pos.count(temp))
    			pos.insert(temp);
    		temp++;
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		cout<<a[i]<<' ';
    		if(pos.count(i)){
    			cout<<"/ ";
    		}
    	}
    	cout<<'\n';
    }
	return 0;
}