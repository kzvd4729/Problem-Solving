/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-30 23:33:42                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1178
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc;
double a,b,c,d,e,s,area,h;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        e=abs(a-c);
        s=(e+b+d)/2;
        area=sqrt(s*(s-e)*(s-b)*(s-d));
        h=(area*2)/e;
        double ans=0.5*(a+c)*h;
        cout<<"Case "<<++tc<<": "<<setprecision(12)<<fixed<<ans<<endl;
    }
    return 0;
}