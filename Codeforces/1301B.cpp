#include<bits/stdc++.h>
using namespace std;
const long long nax = 1e5 + 69 ;
int n,a[nax];
bool check(int val){
	int l = 0,r = 1e9 + val;
	for (int i = 1; i < n; ++i)
	{
		if(a[i-1]==-1 && a[i]!=-1){
			l = max(a[i]-val,l);
			r = min(a[i]+val,r); 
		}
		else if(a[i-1]!=-1 && a[i]==-1){
			l = max(a[i-1]-val,l);
			r = min(a[i-1]+val,r);
		}
		else if(a[i]!=-1 && a[i-1]!=-1 && abs(a[i]-a[i-1])>val)
			return false;
	}
	return l<=r;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
	    cin>>n;
	    for (int i = 0; i < n; ++i)
	    {
	    	cin>>a[i];
	    }
	    int l = 0,r = 1e9;
	    while(l<=r){
	    	int mid = l + (r-l)/2;
	    	if(check(mid))
	    		r = mid - 1;
	    	else
	    		l = mid + 1;
	    }
	    cout<<r+1<<' ';
	    int le = 0,ri = 1e9 + r + 1;
		for (int i = 1; i < n; ++i)
		{
			if(a[i-1]==-1 && a[i]!=-1){
				le = max(a[i]-r-1,le);
				ri = min(a[i]+r+1,ri); 
			}
			else if(a[i-1]!=-1 && a[i]==-1){
				le = max(a[i-1]-r-1,le);
				ri = min(a[i-1]+r+1,ri); 		
			}
		}
		cout<<le<<'\n';
	}
    return 0;
}