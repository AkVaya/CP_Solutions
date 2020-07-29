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
const ll nax=2e5+69;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
	ll n;
    cin>>n;
    string s="";
    ll a[n];
    vector<int> v;
    for (ll i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    ll l=0,r=n-1,last=0;
    while(1){
    	if(a[l]!=a[r]){
    		if(a[l]>last){
    			if(a[r]>last && a[l]<a[r]){
    				last=a[l++];
    				s+="L";
    			}
    			else if(a[r]>last){
    				last=a[r--];
    				s+="R";
    			}
    			else{
    				last=a[l++];
    				s+="L";
    			}
    		}
    		else if(a[r]>last){
    			last=a[r--];
    			s+="R";
    		}
    		else
    			break;
    	}
    	else if(a[l]>last){
    		ll cnt1=1,cnt2=1;
    		while(a[r-cnt2]>a[r-cnt2+1] && r-cnt2>=l)
    			cnt2++;
    		while(a[l+cnt1]>a[l+cnt1-1] && l+cnt1<=r)
    			cnt1++;
    		if(cnt1==1 && cnt2==1){
    			s+="L";
    			break;
    		}
    		if(cnt1>=cnt2){
    			l+=cnt1-1;
    			last=a[l];
    			while(cnt1--)
    				s+="L";
    		}
    		else{
    			r-=cnt2-1;
    			last=a[r];
    			while(cnt2--)
    				s+="R";
    		}
    	}
    	else
    		break;
    	if(l>r)
    		break;
    }
    cout<<s.size()<<endl<<s<<endl;

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