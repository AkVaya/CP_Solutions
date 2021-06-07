#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e5 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    if(n==1)
        cout<<-1<<'\n';
    else
        cout<<n+1<<' '<<n<<' '<<n*n+n<<'\n';
    return 0;
}