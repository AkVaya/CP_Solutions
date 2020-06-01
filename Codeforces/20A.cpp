#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#include<ctime>
#include<cmath>
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e9+7;
const ll nax=1e3+1;
void solve(){
    string s,ans="";
    cin>>s;
    ll check=s[0]=='/';
    ll ind=1;
    if(check){
    	while(ind<s.length() && s[ind]==s[ind-1])
    		ind++;
    	ans+="/";
    }
    check=0;
    for (int i = ind; i < s.length() ; ++i)
    {
    	check=0;
    	if(s[i]=='/'){
    		ans+="/";
    		while(i<s.length() && s[i]=='/'){
    			i++;
    			check=1;
    		}
    		if(check)
    			i--;
    	}
    	else
    		ans+=s[i];
    }
    check=0;
    if(s[s.length()-1]=='/'){
    	ind=s.length()-1;
    	while(ind>0 && s[ind]=='/')
    		ind--;
    	if(ind)
    		check=1;
    }
    for (int i = 0; i < ans.length()-check; ++i)
    {
    	cout<<ans[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}