#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e5 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin>>n>>k;
    while(n>0){
        ll val = 1;
        for (int i = 0; i < n-1; ++i)
        {
            val*=2;
        }
        if(k==val){
            cout<<n<<'\n';
            break;
        }
        if(k>=val)
            k-=val;
        n--;
    }
    return 0;
}