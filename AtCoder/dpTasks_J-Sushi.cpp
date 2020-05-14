#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 10000007
#define inf 1000000000000000000
#define MOD 1000000007
using namespace std;
void solve(){
	ll n,x;
	ll a[4]={0,0,0,0};
	cin>>n;	
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		a[x]++;
	}
	double prob[n+1][n+1][n+1],expected_waste[n+1][n+1][n+1];
	prob[a[1]][a[2]][a[3]]=1;
	for (int c = n; c>=0; --c)
	{
		for (int b = n; b>=0;--b)
		{
			for (int a = n; a>=0; --a)
			{
				if(a==0 && b==0 && c==0)
					continue;
				if(a+b+c>n)
					continue;
				double prob_waste=(double) (n - (a + b + c)) / n;
				double exp_waste=(prob_waste)/(1-prob_waste)+1;
				expected_waste[a][b][c]+=exp_waste*prob[a][b][c];
				if(a!=0){
                    double p_go = (double) a / (a + b + c);
					prob[a-1][b][c]+=prob[a][b][c]*p_go;
					expected_waste[a-1][b][c]+=expected_waste[a][b][c]*p_go;
				}
				if(b!=0){
                    double p_go = (double) b / (a + b + c);
					prob[a+1][b-1][c]+=prob[a][b][c]*p_go;
					expected_waste[a+1][b-1][c]+=expected_waste[a][b][c]*p_go;
				}
				if(c!=0){
                    double p_go = (double) c / (a + b + c);
					prob[a][b+1][c-1]+=prob[a][b][c]*p_go;
					expected_waste[a][b+1][c-1]+=expected_waste[a][b][c]*p_go;
				}
			}
		}
	}
	printf("%.10lf",expected_waste[0][0][0]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0 ;
}
