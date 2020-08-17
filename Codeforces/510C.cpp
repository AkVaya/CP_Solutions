#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<bitset>
#include<iomanip>
#include<queue>
#define endl '\n'
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=5e2+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
vector<vector<ll> >v;
vector<bool> vis,out;
bool check=false;  // cycle check
string ans;
void dfs(ll s){
    if(check)
        return;
    vis[s]=out[s]=true;
    for(auto i : v[s]){
        if(vis[i] && out[i]){
            check=true;
            break;
        }
        else if(!vis[i]){
            dfs(i);
        }
    }
    if(check)
        return;
    out[s]=false;
    ans+=char(s+'a');
}
void solve(){
    ll n;
    cin>>n;
    string s[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>s[i];
    }
    v.resize(26);
    vis.resize(26,false);
    out.resize(26,false);
    vector<ll> in(26,0);
    for (int i = 0; i < n; ++i)
    {            
        for (int j = i+1; j < n; ++j)
        {
            ll x=0,y=0;
            while(x<s[i].length() && y<s[j].length() && s[i][x]==s[j][y]){
                ++x;
                ++y;
            }
            if(y==s[j].length() && x!=s[i].length())
                check=true;
            if(x<s[i].length() && y<s[j].length()){
                v[s[i][x]-'a'].pb(s[j][y]-'a');
                in[s[j][y]-'a']++;
            }
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if(in[i]==0 && !vis[i]){
            //cout<<i<<' ';
            dfs(i);
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if(!vis[i])
            dfs(i);
    }
    if(check)
        cout<<"Impossible"<<endl;
    else{
        reverse(ans.begin(), ans.end());
        for(auto i : ans)
            cout<<i;
        cout<<endl;
    }
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
