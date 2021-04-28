#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e5 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int a[n], pref[n];  
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    sort(a, a+n);
    pref[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
    	pref[i] = a[i] + pref[i-1];
    }
    int q;
    cin>>q;
    while(q--){
    	int x;
    	cin>>x;
    	int ind = upper_bound(a, a+n, x) - a;
    	cout<<ind<<' '<<pref[ind-1]<<'\n';
    }
	return 0;
}