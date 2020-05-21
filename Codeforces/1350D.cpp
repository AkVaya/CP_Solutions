#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<math.h>
#include<string.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
#define inf 1000000000000000000
using namespace std;
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,check1=0,x=0;
    cin>>n>>k;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(a[i]==k){
            x=1;
            a[i]=1;
        }
        else if(a[i]<k)
            a[i]=0;
        else
            a[i]=2;
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n && j-i<=2;++j){
            if(a[i] && a[j]){
                check1=1;
                break;
            }
        }
    }
    if(n==1 && x)
        check1=1;
    if(!x)
        check1=0;
    if(!check1)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){        
        solve();
    }
    return 0 ;
}