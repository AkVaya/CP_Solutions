#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t;
    cin>>n;
    map<int,int> m;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    sort(a,a+n);
    int res = 0;
    cin>>t;
    for (int i = 0; i < n; ++i)
    {
    	int ind = upper_bound(a,a+n,a[i]+t) - a;
    	res = max(res, ind-i);
    }
    cout<<res<<endl;
	return 0;
}