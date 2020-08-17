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
const ll nax=2e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll x=0;
void solve(){
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll ans=0;
	vector<ll> a(n,0);
	stack<ll> zer,one;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='0'){
			if(!one.size()){
				ans++;
				a[i]=ans;
				zer.push(ans);
			}
			else{
				a[i]=one.top();
				one.pop();
				zer.push(a[i]);
			}
		}
		else{
			if(!zer.size()){
				ans++;
				a[i]=ans;
				one.push(ans);
			}
			else{
				a[i]=zer.top();
				zer.pop();
				one.push(a[i]);
			}
		}
	}
	cout<<*max_element(a.begin(), a.end())<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	//x++;
	//cout<<x<<':'<<s<<endl;

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