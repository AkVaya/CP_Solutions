#include<bits/stdc++.h> 
using namespace std; 
const int nax = 3e5 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;
    	if(s[0]!='1' || s[n-1]=='0'){
    		cout<<"NO\n";
    		continue;
    	}
    	string res1 = "(", res2 = "(";
    	int cnt = 0;
    	int x = 1, y = 1;
    	for (int i = 1; i < n; ++i)
    	{
    		if(s[i]=='1'){
    			if(x>0 && y>0){
    				if(x==1 && y==1 && i<n-1 && s[i+1]=='0'){
    					x++;
    					y++;
    					res1+="(";
    					res2+="(";
    				}
    				else{					
	    				res1+=")";
	    				res2+=")";
	    				x--;
	    				y--;
    				}
    			}
    			else{
    				res1+="(";
    				res2+="(";
    				x++;
    				y++;
    			}
    		}
    		else{
    			if(x>=y){
    				if(x<=0)
    					break;
    				res1+=")";
    				x--;
    				res2+="(";
    				y++;
    			}
    			else{
    				if(y<=0)
    					break;
    				res1+="(";
    				x++;
    				res2+=")";
    				y--;
    			}
    		}
    		//cout<<x<<' '<<y<<' '<<s[i]<<endl;
    		//cout<<res1<<' '<<res2<<endl<<endl;
    	}
    	if(!x && !y && res1.length()==n)
    		cout<<"YES\n"<<res1<<'\n'<<res2<<'\n';
    	else
    		cout<<"NO\n";
    }
	return 0;
} 