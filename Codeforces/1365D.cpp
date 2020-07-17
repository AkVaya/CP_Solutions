#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<bitset>
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
#define all(x) x.begin(),x.end()
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
vector<vector<ll> > adj;
ll n,m;
char a[nax][nax];
bool can[nax][nax];
void bfs(){
    queue<pii> q;
    if(a[n-1][m-1]!='#')
        q.push({n-1,m-1});
    while(q.size()){
        pii p= q.front();
        q.pop();
        ll i= p.Fir,j = p.Sec;
        if(can[i][j])
            continue;
        can[p.Fir][p.Sec]=true;
        if(i>0 && a[i-1][j]!='#')
            q.push({i-1,j});
        if(i<n && a[i+1][j]!='#')
            q.push({i+1,j});
        if(j>0 && a[i][j-1]!='#')
            q.push({i,j-1});
        if(j<m && a[i][j+1]!='#')
            q.push({i,j+1});
    } 
}
void solve(){
    cin>>n>>m;
    bool check=true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>a[i][j];
            can[i][j]=false;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(a[i][j]=='B'){
                if(i<n-1 && a[i+1][j]=='G')
                    check=false;
                else if(i<n-1 && a[i+1][j]=='.')
                    a[i+1][j]='#';
                if(i>0 && a[i-1][j]=='G')
                    check=false;
                else if(i>0 && a[i-1][j]=='.')
                    a[i-1][j]='#';
                if(j>0 && a[i][j-1]=='G')
                    check=false;
                else if(j>0 && a[i][j-1]=='.')
                    a[i][j-1]='#';
                if(j<m-1 && a[i][j+1]=='G')
                    check=false;
                else if(j<m-1 && a[i][j+1]=='.')
                    a[i][j+1]='#';
                a[i][j]='#';
            }
            if(!check){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    //cout<<"YAHA : ";
    //for (int i = 0; i < n; ++i)
    //{
    //    for (int j = 0; j < m; ++j)
    //    {
    //        cout<<can[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    bfs();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {

            if(a[i][j]=='G' && !can[i][j]){
                check=false;
            }
            if(!check){
                cout<<"No"<<endl;
                return;
            }
        }
        //cout<<endl;
    }
    cout<<"Yes"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

    //clock_t t3 = clock();
    ll t=1,t1=1;
    cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}