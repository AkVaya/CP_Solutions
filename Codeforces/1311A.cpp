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
#define ins insert 
#define mp make_pair
#define fi first
#define se second
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 1000000000000
using namespace std;
int main(){
    ll t,n,b,a,x,y;
    cin>>t;
    while(t--){
        cin>>a>>b;
        ll ans=0;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        else if(a>b ){
            if((a-b)%2==0)
                ans++;
            else{
                ans+=2;
            }
        }
        if(b>a){
            if((b-a)%2){
                ans++;
            }
            else{
                ans+=2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}