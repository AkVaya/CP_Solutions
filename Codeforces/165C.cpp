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
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e9+7;
const ll nax=1e5+1;
void solve(){
    ll k;
    cin>>k;
    string s;
    cin>>s;
    ll n=s.length();
    ll count[n];
    count[0]=s[0]=='1';
    vector<ll> ones;
    if(count[0])
        ones.pb(0);
    for (int i = 1; i < n; ++i)
    {
        count[i]=count[i-1];
        count[i]+=s[i]=='1';
        if(count[i]-count[i-1])
            ones.pb(i);
    }
    ll ans=0;
    if(k==0){
        ll x;
        for (int i = 0; i < n; ++i)
        {
            x=0;
            while(s[i]=='0'){
                x++;
                i++;
            }
            ans+=x+(x*(x-1))/2;
        }
        cout<<ans<<endl;
    }
    else{
        if(k>count[n-1]){
            cout<<0<<endl;
            return;
        }
        for (int i = 0; i < ones.size()-k+1; ++i)
        {
            ll first=ones[i],last=ones[i+k-1];
            ll count1=1,count2=1;
            first--;
            last++;
            while(first>=0 && s[first]=='0'){
                count1++;
                first--;
            }
            while(last<n && s[last]=='0'){
                count2++;
                last++;
            }
            ans+=(count1*count2);
            //cout<<count1<<" "<<count2;
        }
        cout<<ans<<endl;
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