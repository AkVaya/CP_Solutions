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
#define Fir first
#define Sec second
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define aint(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e5+5;
const ll inf=1e18;
using pii = pair<int,int>;
void solve(){
    int n;
    cin>>n;
    int a[n],ans=0;
    vector<vector<int> >pos(200); 
    vector<vector<int> > till(n+1,vector<int>(200,0));\
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        till[i+1][a[i]-1]++;
        pos[a[i]-1].pb(i);
    }    
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < 200; ++j)
        {
            till[i][j]+=till[i-1][j];
        }
    }
    //cout<<endl;
    for (int i = 0; i < 200; ++i)
    {
        ans=max(ans,(int)pos[i].size());
        //cout<<i<<endl;
        //cout<<pos[0].size()<<endl;
        for (int j = 0; j < pos[i].size()/2; ++j)
        {
            int left=pos[i][j]+1;
            for (int k = 0; k < 200; ++k)
            {
                int temp=till[pos[i][pos[i].size()-j-1]][k]-till[left][k];
                ans=max(temp+2*j+2,ans);
            }
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

    int t=1,t1=1;
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