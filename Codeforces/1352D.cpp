#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
using namespace std;
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,Al=0,Bo=0,num=1;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    ll ind1=1,ind2=n,check=1,prevA=a[0],prevBo=0;
    Al=a[0];
    while(ind1<ind2 ){
        if(check){
            check=0;
            num++;
            prevBo=0;ll currBo=0;
            while(currBo<=prevA && (ind1<ind2) ){
                Bo+=a[--ind2];
                currBo+=a[ind2];
                prevBo+=a[ind2];
            }
        }
        else{
            check=1;
            num++;
            prevA=0;
            ll currAl=0;
            while(prevBo>=currAl && (ind1<ind2)){
                currAl+=a[ind1++];
                prevA+=a[ind1-1];
                Al+=a[ind1-1];
            }
        }
    }
    cout<<num<<" "<<Al<<" "<<Bo<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,q,x;
    cin>>t;
    while(t--){        
        solve();
    }
    return 0 ;
}