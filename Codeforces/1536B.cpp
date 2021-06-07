#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
void create(vector<string> &res){
    for (int i = 0; i < 26; ++i)
    {
        char c = ((i + 'a'));
        string curr;
        curr+=c;
        res.push_back(curr);
        for (int j = 0; j < 26; ++j)
        {
            c = (j + 'a');
            curr += c;
            res.push_back(curr);
            for (int k = 0; k < 26; ++k)
            {                c = (k + 'a');
                curr += c;
                res.push_back(curr);
                curr.pop_back();
            }
            curr.pop_back();
        }
        curr.pop_back();
    }
}
bool cmp(string &a, string &b){
    if(a.length()!=b.length())
        return a.length()<b.length();
    return a <= b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    vector<string> all;
    create(all);
    sort(all.begin(), all.end(), cmp);
    while(t--){
         int n;
         string s;
         cin>>n>>s;
         for(auto i : all){
            //cout<<i<<endl;
            size_t x = s.find(i);
            if(x==string::npos){
                cout<<i<<'\n';
                break;
            }
         }
    }
    return 0;
}
/*          for (int j = 0; j < n; ++j)
            {
                
            }
*/