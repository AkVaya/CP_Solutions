#include<bits/stdc++.h>
using namespace std;
vector<long long> phi(1000001),ans(1000001);
void sieve(){
    for (int i = 0; i < 1000001; ++i)
    {
        if(i%2)
            phi[i] = i;
        else
            phi[i] = i/2;
        ans[i] = 0;
    }
    for (long long int i = 3; i <= 1e6; i+=2)
    {
        if(phi[i]==i){
            for (long long int j = i; j <= 1e6; j+=i)
            {
                phi[j] -= (phi[j])/i;
            }
        }
    }
}
void LCMsum(){
    for (long long int i = 1; i <= 1e6; i++)
    {
        for (long long int j = i; j <= 1e6; j+=i)
        {
            ans[j] += phi[i]*i;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);cin.tie(NULL);
    long long int a,t;
    sieve();
    LCMsum();
    cin>>t;
    while(t--){
        cin>>a;
        cout<<((ans[a] + 1)*a)/2<<'\n';
    }
    return 0;
}