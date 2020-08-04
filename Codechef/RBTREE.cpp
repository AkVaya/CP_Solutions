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
const ll nax=1e3+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
bool flip=true;
ll lvl(ll a){
	ll cnt=0;
	while(a){
		a/=2;
		cnt++;
	}
	return cnt;
}
void solve(){
	string s;
	cin>>s;
	//cout<<temp++<<endl;
	if(s[1]=='i'){
		flip=!flip;
		return;
	}
	ll a,b;
	cin>>a>>b;
	if(a>b)
		swap(a,b);
	ll lvl1=lvl(a),lvl2=lvl(b),x=0;
	//cout<<lvl1<<' '<<lvl2<<endl;
	ll cntb=0,cntr=0;
	while(a!=b){
		if(a>b){
			if(lvl1%2){
				if(flip)
					cntb++;
				else
					cntr++;
			}
			else{
				if(flip)
					cntr++;
				else
					cntb++;
			}
			a/=2;
			lvl1--;
		}
		else{
			if(lvl2%2){
				if(flip)
					cntb++;
				else
					cntr++;
			}
			else{
				if(flip)
					cntr++;
				else
					cntb++;
			}
			b/=2;
			lvl2--;
		}
		//cout<<a<<' '<<b<<endl;
		//x++;
		//if(x>10)
		//	break;
	}
	if(lvl1%2 && flip)
		cntb++;
	else if(lvl1%2)
		cntr++;
	else{
		if(flip)
			cntr++;
		else
			cntb++;
	}
	if(s[1]=='b')
		cout<<cntb<<' ';
	else
		cout<<cntr<<' ';
	//cout<<endl;
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