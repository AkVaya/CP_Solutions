#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e4 + 69;
using ll = long long;
const int M = 1e9 + 7;
vector<vector<int> >v;
vector<bool> vis;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        priority_queue<ll, vector<ll>, greater<ll> >pq;
        ll res = 0, sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum+=a[i];
            res++;
            pq.push(a[i]);
            while(sum<0 && pq.size()){
                res--;
                sum-=pq.top();
                pq.pop();
            }
        }
        cout<<res<<'\n';
    }
    return 0;
} 