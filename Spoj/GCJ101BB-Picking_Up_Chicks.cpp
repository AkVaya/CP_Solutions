#include<bits/stdc++.h> 
using namespace std; 
const int nax = 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1, x = 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<x++<<": ";
        int n, b, k, tot;
        cin>>n>>k>>b>>tot;
        int cnt = 0;
        vector<pair<int, int> > v(n);
        for (int i = 0; i < n; ++i)
            cin>>v[i].first;
        for (int i = 0; i < n; ++i){
            cin>>v[i].second;
            if((b-v[i].first + v[i].second - 1)/v[i].second <=tot)
                cnt++;
        }
        //cout<<cnt<<endl;
        if(cnt<k){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        sort(v.begin(), v.end());
        int res = 0;
        cnt = 0;
        for (int i = n-1; i >= 0 && k>0; --i)
        {
            if((b-v[i].first + v[i].second - 1)/v[i].second > tot){
            //    cout<<v[i].first<<' '<<v[i].second<<endl;
                cnt++;
            }
            else{
                res+=cnt;
                k--;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}