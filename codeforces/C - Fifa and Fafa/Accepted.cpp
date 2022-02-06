/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/19/2018 23:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/935/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
double r,a1,a2,b1,b2,d,r1,dd,xt,yt,t,ux,vx,mg,vy,uy;
double dist()
{
    return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>r>>a1>>b1>>a2>>b2;
    d=dist();
    if(d>r)
    {
        cout<<a1<<" "<<b1<<" "<<r<<endl;
        return 0;
    }
    dd=d+r;
     dd=dd/2;
     vx=a1-a2;
    vy=b1-b2;
    if(vx==0)vx=0.000000000001;
    if(vy==0)vy=0.000000000001;
    mg=sqrt(vx*vx+vy*vy);
    ux=vx/mg;
    uy=vy/mg;
     a2=a2+ux*dd;
    b2=b2+uy*dd;
    cout<<setprecision(10)<<fixed<<a2<<" "<<setprecision(10)<<fixed<<b2<<" "<<setprecision(10)<<fixed<<dd<<endl;
      return 0;
}