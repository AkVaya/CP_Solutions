#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
#define inf 1000000000000000000
using namespace std;
string s1,s2;
string s3="";
void solve(){
	while(cin>>s1 && cin>>s2)
    {
    	int m,n;
    	if(s1.length()<s2.length()){
    		s3=s2;
    		s2=s1;
    		s1=s3;
    	}
    	s3="";
        m=s1.length();n=s2.length();
        int ans[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    ans[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1]){
                    ans[i][j]=1+ans[i-1][j-1];
                }
                else{
                    ans[i][j]=max(ans[i][j-1],ans[i-1][j]);
                }
            }
        }
        vector<char> v;
        vector<int> x,y;
        int i=m,j=n;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                v.push_back(s1[i-1]);
                i--;j--;
                x.pb(i);y.pb(j);
            }
            else if(ans[i-1][j]>ans[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        i=0;j=0;
        ll ind1=x.size()-1,ind2=y.size()-1;
        while(i<m && j<n){
          	while(ind1>=0 && i<m && i<x[ind1])
        	{
        		s3+=s1[i];
        		i++;
        	}
        	while(ind2>=0 && j<n && j<y[ind2])
        	{
        		s3+=s2[j];
        		j++;
        	}
        	if(ind1==-1)
        		break;
        	s3+=s1[i];
        	ind1--;ind2--;
        	i++;j++;
        }
        while(i<m)
        {
        		s3+=s1[i];
        		i++;
       	}
        while(j<n)
        {
        		s3+=s2[j];
        		j++;
       	}
        cout<<s3<<endl;
    }
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