#include<bits/stdc++.h>
using namespace std;
int main()
{
    double u,v,w,U,V,W;
    int t=0;
    cin>>t;
    while(t--)
    {
        cin>>u>>v>>w>>W>>V>>U;
        double a,b,c,d,x,y,z,X,Y,Z;
        X=(w-U+v)*(U+v+w);
        x=(U-v+w)*(v-w+U);
        Y=(u-V+w)*(V+w+u);
        y=(V-w+u)*(w-u+V);
        Z=(v-W+u)*(W+u+v);
        z=(W-u+v)*(u-v+W);
        a=sqrt(x*Y*Z);
        b=sqrt(y*Z*X);
        c=sqrt(z*X*Y);
        d=sqrt(x*y*z);
        double vol=(b+c+d-a)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d);
        vol=sqrt(vol)/(192*u*v*w);
        cout<<fixed<<setprecision(4);
        cout<<vol<<'\n';
    }
    return 0;
}   