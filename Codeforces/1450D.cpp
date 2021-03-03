#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int a[n+5];
    	vector<int>cnt(n+5,0);
    	int total = -1;
    	for (int i = 0; i < n; ++i){
	    	cin>>a[i];
	    	cnt[--a[i]]++;
    	}
    	while(cnt[total+1]==1)
    		total++;
   	    int res[n]={0};
   	    res[0] = (total==n-1);
   	    res[n-1] = (cnt[0]>0);
	    int l = 0;
	    int r = n-1;
    	for (int i = n-1; i >= 1; --i){
    		if(!res[n-1])
    			break;
    		res[i] = 1;
    		int nxt = n - i - 1;
    		if(--cnt[nxt]==0 && (a[l]==nxt || a[r]==nxt) && cnt[nxt+1]){
    			if(a[l]==nxt)
    				l++;
    			else
    				r--;
    			continue;
    		}
    		break;
    	}
	    for (int i = 0; i < n; ++i)
	    	cout<<res[i];
	    cout<<'\n';
	}
    return 0;
}