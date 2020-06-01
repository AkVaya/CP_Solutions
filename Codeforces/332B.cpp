#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#include<ctime>
#include<cmath>
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
const ll M =1e9+7;
const ll nax=2001;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n],end[n],sum=0,maxfrom[n][2];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        sum+=a[i];
        if(i>=k-1){
            end[i]=sum;
            sum-=a[i-k+1];
        }
        else
            end[i]=sum;
        //cout<<end[i]<<endl;
    }
    ll mx=0,ind1,ind2;
    sum=0;
    for (int i = n-1; i >=0; --i)
    {
        sum+=a[i];
        if(i<=n-k){
            if(mx<=sum){
                maxfrom[i][1]=i;
                mx=sum;
            }
            else
                maxfrom[i][1]=maxfrom[i+1][1];
            maxfrom[i][0]=mx;
            sum-=a[i+k-1];
        }
        else{
            maxfrom[i][0]=sum;
            maxfrom[i][1]=i;
        }
        //cout<<i<<" "<<maxfrom[i][0]<<" "<<maxfrom[i][1]<<endl;
    }
    mx=0;
    for (int i = k-1; i <=n-k-1; ++i)
    {
        if(mx<end[i]+maxfrom[i+1][0]){
            mx=end[i]+maxfrom[i+1][0];
          //  cout<<i<<" "<<end[i]+maxfrom[i+k][0]<<" "<<maxfrom[i+1][1]<<endl;
            ind1=i-k+2;
            ind2=maxfrom[i+1][1]+1;
        }
    }
    cout<<ind1<<" "<<ind2<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}