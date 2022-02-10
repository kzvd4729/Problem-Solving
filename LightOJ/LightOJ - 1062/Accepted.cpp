/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-31 18:10:16                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1062
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc;
double x,y,c,hi,lo,mn,a,b,m,n;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>c;
        lo=0;hi=min(x,y);
        for(int i=1;i<=1000;i++)
        {
            mn=(lo+hi)/2.0;
            a=sqrt(y*y-mn*mn);
            b=sqrt(x*x-mn*mn);
            m=(mn*c)/a;
            n=(mn*c)/b;
            if((m+n)>mn)hi=mn;
            else lo=mn;
        }
        cout<<"Case "<<++tc<<": "<<setprecision(12)<<fixed<<mn<<endl;
    }
    return 0;
}