#include<bits/stdc++.h>
using namespace std;
const int nax = 1e3+69;
char a[nax][nax];
bool vis[nax][nax];
int n;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
bool isValid(int i,int j){
	return (i>=0 && i<n && j>=0 && j<n);
}
int dfs(int i,int j){
    vis[i][j]=true;
    int cnt = 1;
    for (int a = 0; a < 4; ++a)
    {
    	if(isValid(i+dx[a],j+dy[a]) && !vis[i+dx[a]][j+dy[a]])
    		cnt+=dfs(i+dx[a],j+dy[a]);
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>a[i][j];
            if(a[i][j]=='W')
                vis[i][j] = true;
        }
    }
    int ans=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(!vis[i][j]){
            	ans = max(ans,dfs(i,j));
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}