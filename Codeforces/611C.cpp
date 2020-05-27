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
using namespace std;
const ll M =1e9+7;
const ll nax=2001;
ll hdp[nax][nax],vdp[nax][nax];
void solve(){
    ll h,w;
    cin>>h>>w;
    char a[h+1][w+1];
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin>>a[i][j];
        }
    }
    memset(hdp,0,sizeof(hdp));
    memset(vdp,0,sizeof(vdp));
    for (int i = 0; i <h; ++i)
    {
        for (int j = 0; j <w; ++j)
        {
            hdp[j+1][i+1] = hdp[j][i+1] + hdp[j+1][i] - hdp[j][i];
            vdp[j+1][i+1] = vdp[j][i+1] + vdp[j+1][i] - vdp[j][i];
            if(a[i][j]== '#') 
                continue;
            if(j<w-1 && a[i][j+1] == '.') 
                hdp[j+1][i+1]++;
            if(i<h-1 && a[i+1][j] == '.')
                vdp[j+1][i+1]++;
           // cout<<hdp[i][j]<<" "<<vdp[i]<<" ";
        }
        //cout<<endl;
    }

    ll q,r1,c1,r2,c2;
    cin>>q;
    while(q--){
        cin>>r1>>c1>>r2>>c2;
        r1--;c1--;
        ll x=hdp[c2-1][r2]-hdp[c1][r2]-hdp[c2-1][r1]+hdp[c1][r1];
        x+=vdp[c2][r2-1]-vdp[c1][r2-1]-vdp[c2][r1]+vdp[c1][r1];
        cout<<x<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
   // cin>>t;
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