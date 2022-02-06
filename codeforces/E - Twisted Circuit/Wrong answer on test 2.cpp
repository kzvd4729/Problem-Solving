/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/31/2017 22:44                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/784/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,w,x,y,z,wx,yz;
    while(cin>>a>>b>>c>>d)
    {
        w=a*b;
        x=c+d;
        if(x==2)x=0;
        y=b+c;
        if(y==2)y=1;
        z=a*d;
        wx=w+x;
        if(wx==2)wx=1;
        yz=y+z;
        if(yz==2)yz=0;
        if(wx*yz==0)cout<<1<<endl;
        else cout<<0<<endl;
     }
     return 0;
}