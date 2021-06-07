class Solution {
public:
    void dfs(int s, vector<bool>& vis, vector<vector<int> > &v){
        //cout<<s<<endl;
        if(vis[s])
            return;
        vis[s] = true;
        for(int i : v[s]){
            //cout<<i<<' '<<vis[i]<<endl;
            if(!vis[i])
                dfs(i, vis, v);
        }
    }
    int makeConnected(int n, vector<vector<int>>& x) {
        int cnt = 0;
        if(x.size()<n-1)
            return -1;
        vector<vector<int> > v(n);
        for(auto i : x){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n+1, false);
        for(int i = 0; i < n; ++i){
            //cout<<i<<' '<<vis[i]<<endl;
            if(!vis[i]){
                cnt++;
                dfs(i, vis, v);
            }
        }
        return cnt-1;
    }
};