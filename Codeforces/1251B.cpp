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
bool check(string s){
    ll x=0,y=0;
    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i]=='1')
            x++;
        else
            y++;
    }
    return x%2|y%2;
}
void solve(){
    ll n,x;
    cin>>n;
    string s[n];
    ll cnt[3]={0,0,0};
    for (int i = 0; i < n; ++i)
    {
        cin>>s[i];
        if(s[i].length()%2==0){
            if(check(s[i]))
                cnt[1]++;
            else
                cnt[0]++;
        }
        else
            cnt[2]++;
    }
    //cout<<"HEERE AT THE WALL :)"<<endl;
    if(cnt[2])
        cout<<n<<endl;
    else{
        if(cnt[1]%2)
            cout<<n-1<<endl;
        else
            cout<<n<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    cin>>t;
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