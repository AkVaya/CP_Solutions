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
    cin>>t;
    while(t--){
        ll w, h, n;
        cin>>w>>h>>n;
        if(!n){
            cout<<h*w<<endl;
            continue;
        }
        ll a[n], b[n];
        ll mx1 = 0, mx2 = 0;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i]>>b[i];
        }
        sort(a, a+n);
        sort(b, b+n);
        for (int i = 0; i < n; ++i)
        {
            if(i){
                mx1 = max(mx1, a[i]-a[i-1]-1);
                mx2 = max(mx2, b[i]-b[i-1]-1); 
            }
            else
                mx1 = a[i]-1, mx2 = b[i]-1;
        }
        mx1 = max(mx1, w-a[n-1]);
        mx2 = max(mx2, h-b[n-1]); 
        mx1*=mx2;
        cout<<mx1<<'\n';
    }
    return 0;
}