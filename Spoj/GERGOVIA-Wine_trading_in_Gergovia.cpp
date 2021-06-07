#include<bits/stdc++.h> 
using namespace std; 
const int nax = 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin>>t;
    while(1){
        int n;
        cin>>n;
        if(!n)
            break;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        ll res = 0, curr = a[0];
        for (int i = 1; i < n; ++i)
        {
            res+=abs(curr);
            curr+=a[i];
        }
        cout<<res<<'\n';
    }
    return 0;
}