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
#define Fi first
#define Se second
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =998244353;
const ll nax=3e5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
	ll n;
	cin>>n;
	string s;
	ll num[2]={n/2,n/2};
	cin>>s;
	if(n%2){
		cout<<":("<<endl;
		return;
	}
	string ans=s;
	if(s[0]==')' || s[n-1]=='('){
		cout<<":("<<endl;
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='(')
			num[0]--;
		else if(s[i]==')')
			num[1]--;
	}
	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='?'){
			if(num[0]){
				ans[i]='(';
				num[0]--;
			}
			else if(num[1]){
				ans[i]=')';
				num[1]--;
			}
		}
	}
	num[0]=1;
	num[1]=0;
	for (int i = 1; i < n-1; ++i)
	{
		if(ans[i]=='('){
			num[0]++;
		}
		else if(ans[i]==')'){
			if(num[0]>1 )
				num[0]--;
			else{
				//cout<<ans<<endl;
				cout<<":("<<endl;
				return;
			}
		}
	}
	if(num[0]==1)
		cout<<ans<<endl;
	else
		cout<<":("<<endl;
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