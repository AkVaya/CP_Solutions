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
//#define endl '\n'
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
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
vector<vector<ll> >v;
vector<bool> vis;
ll n;
string s;
vector<ll> dp;
void bfs(){
	queue<ll> q;
	q.push(0);
	dp[0]=0;
	while(q.size()){
		ll ind=q.front();
		if(ind==n-1)
			break;
		q.pop();
		for(auto i : v[s[ind]-'0']){
			if(!vis[i]){
				vis[i]=true;
				q.push(i);
				dp[i]=min(dp[i],1+dp[ind]);
			}
		}
		//cout<<ind<<' ';
		v[s[ind]-'0'].clear();
		if(ind>0 && !vis[ind-1]){
		//	cout<<"PUSHED PREv"<<endl;
			q.push(ind-1);
			dp[ind-1]=min(dp[ind-1],1+dp[ind]);
		}
		if(ind<n-1 && !vis[ind+1]){
		//	cout<<"PUSHED NEXT"<<endl;
			q.push(ind+1);
			dp[ind+1]=min(dp[ind+1],1+dp[ind]);
		}
	}
}
void solve(){
	cin>>s;
	n=s.size();
	v.resize(10);
	dp.resize(n+1,M);
	vis.resize(n+1,false);
	for (int i = 0; i < s.size(); ++i)
	{
		v[s[i]-'0'].pb(i);
	}
	//cout<<"HERE"<<endl;
	bfs();
	cout<<dp[n-1]<<endl;
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