#include<bits/stdc++.h>
using namespace std;
const int nax = 1e3+69; 
bool vis[nax][nax][3];
char a[nax][nax];
int n,m;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0}; 
char dir[4] = {'L', 'R', 'U','D'};
bool check(int i,int j){
	return (i>=0 && i<n && j>=0 && j<m);
}
bool ans = false;
void dfs(int i,int j,int num,char x){
	if(vis[i][j][num] || num>2 || ans) 
		return;
	else if(a[i][j]=='T'){
		ans = true;
		return;
	}
	vis[i][j][num]=true;
	for (int t = 0; t < 4; ++t)
	{
		int currx=i+dx[t],curry=j+dy[t];
		if(check(currx,curry) && !vis[currx][curry][num]){
			char currD;
			if(currx==i+1)
				currD='D';
			else if(currx==i-1)
				currD='U';
			else if(curry==j+1)
				currD='R';
			else if(curry==j-1)
				currD='L';
			dfs(currx,curry,num+(currD!=x),currD);
		}
	}
}
void fun(){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			vis[i][j][0]=vis[i][j][1]=vis[i][j][2]=(a[i][j]=='*');
		}
	}
}
int main(){
	cin>>n>>m;
	int x,y;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
			if(a[i][j]=='S')
				x=i,y=j;
			vis[i][j][0]=vis[i][j][1]=vis[i][j][2]=(a[i][j]=='*');
		}
	}
	dfs(x,y,0,'R');
	fun();
	dfs(x,y,0,'L');
	fun();
	dfs(x,y,0,'U');
	fun();
	dfs(x,y,0,'D');
	if(ans)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}