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
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+1;
string fun(char a){
    if(a=='4')
        return "322";
    else if(a=='6')
        return "53";
    else if(a=='8')
        return "7222";
    else if(a=='9')
        return "7332";
    string s;
    s+=a;
    return s;
}
void solve(){
    ll n;
    cin>>n;
    char a[n];
    string ans="";
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(a[i]>'1')
            ans+=fun(a[i]);
        //cout<<fun(a[i])<<endl;
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
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