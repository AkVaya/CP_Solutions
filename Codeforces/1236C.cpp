#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);    
    int n;
    cin>>n;
    int a[n][n];
    for(int i=1;i<=n;i++) {
        for(int j=0;j<n;j++) {
            a[i-1][j] = i+j*n;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(j%2==0)
                cout<<a[i][j]<<" ";
            else
                cout<<a[n-i-1][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}