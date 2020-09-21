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
const ll nax=3e2+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
	string s;
	cin>>s;
	set<char> se;
	se.ins(s[0]);
	string ans(1, s[0]);
	ll ind=0;
	for (int i = 1; i < s.length(); ++i)
	{
		if(se.find(s[i])!=se.end()){
			if(ind>0 && ans[ind-1]==s[i])
				ind--;
			else if(ind<ans.size()-1 && ans[ind+1]==s[i])
				ind++;
			else{
				cout<<"NO"<<endl;
				return;
			}
		}
		else{
			if(ind==0)
				ans=s[i]+ans;
			else if(ind==ans.length()-1){
				ans+=s[i];
				ind++;
			}
			else{
				cout<<"NO"<<endl;
				return;
			}
		}
		se.ins(s[i]);
	}
	for (int i = 0; i < 26; ++i)
	{
		if(se.find(char(i+'a'))==se.end())
			ans+=char(i+'a');
	}
	cout<<"YES"<<endl<<ans<<endl;
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
