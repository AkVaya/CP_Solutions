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
const ll nax=5e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
    string s;
    cin>>s;
    vector<ll> cnt(10,0);
    ll ans=M;
    ll n=s.length();
    for (int i = 0; i < n; ++i)
    {
    	cnt[s[i]-'0']++;
    	ans=min(ans,n-cnt[s[i]-'0']);
    }
    for (int i = 0; i < 10; ++i)
    {
    	for (int j = 0; j < 10; ++j)
    	{
    		if(i==j)
    			continue;
    		ll cnt=0;
    		bool check=true;
    		for (int k = 0; k < n; ++k)
    		{
    			if(check && s[k]==i+'0'){
    				cnt++;
    				check=!check;
    			}
    			else if(!check && s[k]==j+'0'){
    				cnt++;
    				check=!check;
    			}
    		}
    		//if(cnt)
    		//	cout<<i<<' '<<j<<' '<<cnt<<endl;
    		if(cnt%2==0)
    			ans=min(ans,n-cnt);
    	}
    }
    cout<<ans<<endl;
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
