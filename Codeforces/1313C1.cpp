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
const ll nax=200001;
void solve(){
    ll n;
    cin>>n;
    ll a[n],ans[n];
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    ll x=0;
    for (int i = 0; i < n; ++i)
    {
    	ll temp=a[i],sum=a[i];
    	vector<ll> v(n);
    	v[i]=a[i];
    	for (int j = i-1; j >= 0 ; --j)
    	{
    		temp=min(temp,a[j]);
    		v[j]=temp;
    		sum+=v[j];
       	}
       	temp=a[i];
       	for (int j = i+1; j < n ; ++j)
    	{
    		temp=min(temp,a[j]);
    		v[j]=temp;
    		sum+=v[j];
       	}
       	if(sum>x){
       		x=sum;
       		for (int j = 0; j < n; ++j)
       		{
       			ans[j]=v[j];
       		}
       	}        	
    }
    for (int i = 0; i < n; ++i)
    {
    	cout<<ans[i]<<" ";
    }


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