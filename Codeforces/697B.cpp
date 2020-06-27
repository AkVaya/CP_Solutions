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
void solve(){
    ll exp,fi;
    char c[3];
    string s="",ans="";
    cin>>c[0]>>c[1];
    fi=c[0]-'0';
    while(1){
        cin>>c[2];
        if(c[2]=='e')
            break;
        s+=c[2];
    }
    cin>>exp;
    ans+=c[0];
    ll ind=0;
    while(exp>0 && ind<s.length()){
        ans+=s[ind++];
        exp--;
    }
    if(ind<s.length())
        ans+=".";
    else{
        while(exp--)
            ans+="0";
        if(!fi)
            ans=ans.substr(1,ans.length()-1);
    }
    while(ind<s.length()){
        ans+=s[ind++];
    }
    ind=-1;
    for (int i = 0; i < ans.length(); ++i)
    {
        if(ans[i]=='.'){
            ind=i;
            break;
        }
    }
    if(ind>0){
        bool check=false;
        for (int i = ind+1; i < ans.length(); ++i)
        {
            if(ans[i]!='0'){
                check=true;
                break;
            }
        }
        if(!check)
            ans=ans.substr(0,ind);
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