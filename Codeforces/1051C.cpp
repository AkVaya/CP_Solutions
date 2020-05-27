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
    ll n;
    map<ll,ll> m;
    cin>>n;
    ll a[n],count1=0,count2=0,check[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        m[a[i]]++;
        check[i]=false;
    }
    bool set=false,temp=true;
    for (int i = 0; i < n; ++i)
    {
        if(m[a[i]]==1){
            check[i]=set;
            set=!set;
            count1++;
        }
        else if(m[a[i]]>2)
            count2++;
    }
    if(count1%2 && count2==0){
        cout<<"NO";
        return;
    }
    string ans="";
    //cout<<count1<<endl;
    if(count1%2){
        for (int i = 0; i < n; ++i)
        {
            if(m[a[i]]>2 && temp){
                ans+="B";
                temp=false;
            }
            else if(check[i]){
                ans+="B";
            }
            else
                ans+="A";
        }
    }
    else{
        for (int i = 0; i < n; ++i)
        {
            if(check[i]){
                ans+="B";
            }
            else
                ans+="A";
        }
    }
    cout<<"YES"<<endl<<ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
   // cin>>t;
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