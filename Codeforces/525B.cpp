#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e6+5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
    ll n,x;
    string s;
    cin>>s>>n;
    ll a[n];
    vector<ll> pref(s.length(),0);
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        pref[a[i]-1]++;
        pref[s.length()-a[i]]--;
    }
    //cout<<pref[0]<<" ";
    for (int i = 1; i < s.length(); ++i)
    {
        pref[i]+=pref[i-1];
        //cout<<pref[i]<<" ";
    }
    //cout<<endl;
    for (int i = 0; i < s.length(); ++i)
    {
        if(pref[i]%2){
            char temp=s[i];
            s[i]=s[s.length()-1-i];
            s[s.length()-1-i]=temp;
            pref[i]=pref[s.length()-1-i]=0;
        }
        else{
            pref[i]=pref[s.length()-1-i]=0;
        }
    }
    cout<<s<<endl;
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
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}