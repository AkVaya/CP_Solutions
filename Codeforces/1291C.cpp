#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e5 + 69;
using ll = long long;

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        int a[n];
        k = min(k, m-1);
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        int ans = *min_element(a, a+n);
        for (int i = 0; i <= k; ++i)
        {
            int l = i, r = n-(k-i)-1;
            //cout<<i<<' '<<l<<' '<<r<<endl;
            int temp = 0, res = INT_MAX;

            int x = m-k-1;
            while(x>=0){
                res = min(res, max(a[l+x],a[r-(m-k-1)+x]));
                x--;
            }
            //cout<<i<<' '<<res<<endl;
            if(res!=INT_MAX)
                ans = max(ans, res);
        }  
        cout<<ans<<'\n';
    }
    return 0;
}