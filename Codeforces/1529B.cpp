#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        bool check = false;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin>>a[i];
        sort(a, a+n);
        int mx = INT_MAX;
        for (int i = 0; i < n && !check; ++i)
        {
            if(i)
                mx = min(mx, a[i]-a[i-1]);
            if(a[i]>0){
                if(mx>=a[i])
                    cout<<i+1<<'\n';
                else
                    cout<<i<<'\n';
                check = true;
                break;
            }
        }
        if(!check)
            cout<<n<<'\n';
    }
    return 0;
}