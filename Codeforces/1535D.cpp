#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
vector<int> tree(4*nax);
string s;
int n;
void merge(int curr){
    if(curr>=(n-1)/2){
        tree[curr] = (s[curr]=='?' ? 2 : 1);
        return;
    }
    if(s[curr]=='?')
        tree[curr] = tree[2*curr+2] + tree[2*curr+1];
    else if(s[curr] == '0')
        tree[curr] = tree[2*curr+2];
    else
        tree[curr] = tree[2*curr+1];
}
void build(int r){
    for (int i = r; i >= r/2; --i)
    {
        tree[i] = (s[i] == '?' ? 2 : 1); 
    }
    for(int i = r/2-1; i >= 0; --i)
        merge(i);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin>>n;
    n = pow(2, n) - 1;
    cin>>s;
    reverse(s.begin(), s.end());  
    cin>>q;
    build(n-1);
    // for (int i = 0; i < 7; ++i)
    // {
    //     cout<<i<<' '<<s[i]<<' '<<tree[i]<<endl;
    // }
    // cout<<endl;
    while(q--){
        int a;
        char b;
        cin>>a>>b;
        a = n - a;
        // cout<<a<<endl;
        s[a] = b;
        while(a>0){
            merge(a);
            a=(a-1)/2;
        }
        merge(a);
        // for (int i = 0; i < 7; ++i)
        // {
        //     cout<<i<<' '<<s[i]<<' '<<tree[i]<<endl;
        // }
        // cout<<endl;
        cout<<tree[0]<<'\n';  
    }
    return 0;
}