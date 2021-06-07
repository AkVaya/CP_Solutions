#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n], even = 0, odd= 0, res = 0;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            even += (a[i]%2==0);
            odd += (a[i]%2);
        }
        res = (even*(even - 1))/2 + odd*even;
        for (int i = 0; i < n; ++i)
        {
            if(a[i]%2){
                for (int j = i+1; j < n; ++j)
                {
                    if(a[j]%2 && __gcd(a[i], a[j])>1)
                        res++;
                }
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}