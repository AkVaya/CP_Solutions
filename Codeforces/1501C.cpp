#include<bits/stdc++.h> 
using namespace std; 
const int nax = 5e6 + 69;
int a[nax];
int m[nax][2];
int main() 
{ 
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
	 	cin>>a[i];
	} 
    for (int i = 1; i <= n; ++i) 
    { 
        for (int j = i + 1; j <= n; ++j) 
        { 
            int sum = a[i] + a[j]; 
            if (m[sum][0] == 0){ 
                m[sum][0] = i;
                m[sum][1] = j;
            } 
            else 
            {
            	int x = m[sum][0], y = m[sum][1];
                if(i!=x && j!=y && i && j && i!=y && j!=x){
                	cout<<"YES\n";
                	cout<<i<<' '<<j<<' '<<x<<' '<<y<<'\n';
                	return 0;
                }
            } 
        } 
    } 
	cout<<"NO\n"; 
	return 0; 
} 
