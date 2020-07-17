#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<iomanip>
#include<queue>
#define endl '\n'
#define pb push_back
#define Fir first
#define Sec second
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e5+5;
const ll inf=1e18;
using pii = pair<ll,ll>;
bool check(string s1,string s2){
    if(s1==s2){
        return true;
    }
    if(s1.length()==1)
        return false;
    if(s1.length()%2 || s2.length()%2)
        return false;
    //cout<<s1<<" "<<s2<<endl;
    if(check(s1.substr(0,s1.length()/2),s2.substr(s2.length()/2,s2.length()/2))){
        if(check(s1.substr(s1.length()/2,s1.length()/2),s2.substr(0,s2.length()/2))){
        //    cout<<"  "<<s1<<" "<<s2<<endl;
            return true;
        }
    }
    if(check(s1.substr(0,s1.length()/2),s2.substr(0,s2.length()/2))){
        if(check(s1.substr(s1.length()/2,s1.length()/2),s2.substr(s2.length()/2,s2.length()/2))){
        //    cout<<"  "<<s1<<" "<<s2<<endl;
            return true;
        }
    }
    return false;
}
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    if(check(s1,s2))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

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