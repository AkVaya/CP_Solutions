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
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 100000000000000007
using namespace std;
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll a[n],count[n]={0},max=0,ind;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        count[i]=0;
    }
    for (int i = n-2; i >=0; --i)
    {
        if(i<=n-k-1){
            if(i>0 && a[i]>a[i-1] && a[i]>a[i+1])
                count[i-1]++;
            count[i]+=(count[i+1]);
            if (a[i+k-1]>a[i+k-2] && a[i+k-1]>a[i+k])
            {
                count[i]--;
            }
        }
        else{
            if(i>0 && a[i]>a[i-1] && a[i]>a[i+1])
                count[i-1]++;
            count[i]+=count[i+1];
        }
        if(max<=count[i]){
            max=count[i];
            ind=i;
        }
    }
    
   // cout<<endl;
    if(ind>n-k)
        ind=n-k;
    cout<<max+1<<" "<<ind+1<<endl;
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