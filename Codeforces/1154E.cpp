#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e5 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int a[n], res[n], val = 1;
    set<pair<int,int> >s;
    set<int> left;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        s.insert({a[i], i});
        left.insert(i);
    }
    while(left.size()){
        auto it = s.end();
        --it;
        s.erase(it);
        int ind = it->second;
        //cout<<it->first<<endl;
        res[ind] = val;
        auto x = left.upper_bound(ind);
        int cnt = 0;
        while(cnt<k && x!=left.end()){
            res[*x] = val;
            s.erase({a[*x], *x});
            auto temp = x;
            ++x;
            left.erase(*temp);
            cnt++;
        }
        x = left.lower_bound(ind);
        if(x!=left.begin())
            --x;
        cnt = 0;
        while(cnt<k && x!=left.begin()){
            res[*x] = val;
            s.erase({a[*x], *x});
            auto temp = x;
            --x;
            left.erase(*temp);
            cnt++;
        }
        if(cnt<k){
            res[*x] = val;
            s.erase({a[*x], *x});
            int temp = *x;
            left.erase(temp);
        }
        left.erase(ind);
        val = 3 - val;
    }
    for (int i = 0; i < n; ++i)
    {
        cout<<res[i];
    }
    cout<<'\n';
    return 0;
}