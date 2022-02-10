/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-31 02:16:18                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 4                                          memory_used (MB): 1.8                             
*  problem: https://vjudge.net/problem/LightOJ-1072
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc;
double n,R,r;
const double pi=3.141592653589;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>R>>n;
        double ang=pi/n;
        ///sin(ang)=r/(R-r);
        ///r=sin(ang)(R-r);
        ///r(1+sin)=Rsin;
        r=(R*sin(ang))/(1+sin(ang));
        cout<<"Case "<<++tc<<": "<<setprecision(12)<<fixed<<r<<endl;
    }
    return 0;
}