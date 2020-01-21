#include<iostream>
#include<set>
#include<vector>
#include<unordered_set>
#define ll long long 
#define mp make_pair
#define pb push_back
using namespace std;
ll binpow(ll a,ll b,ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
ll modInverse(ll a, ll m) 
{ 
    return binpow(a, m-2, m);  
} 
int main(){
    ll alpha,c,n ,q,x,y,z;
    while(1){
        cin>>x>>alpha>>n>>c;
        if(!x && !alpha && !n && !c)
            break;
        z = binpow(alpha,n,c);
        q = ((((z-1)%c * (alpha%c) )%c) * (modInverse(alpha-1 , c) % c))%c;
        z = ((z%c) * (x%c))%c;
        cout<<(z-q+c)%c<<endl;

    }
    return 0;
}