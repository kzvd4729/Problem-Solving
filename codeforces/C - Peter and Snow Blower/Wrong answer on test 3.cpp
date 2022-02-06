/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/17/2017 20:34                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/614/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
#define pi acos(-1)
using namespace std;
double x,y,x1,y1,dist,mx,mn=999999999999;
long n,i;
int main()
{
    cin>>n>>x>>y;
    for(i=1;i<=n;i++)
    {
        cin>>x1>>y1;
        dist=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
        mx=max(mx,dist);
        mn=min(mn,dist);
    }
    cout<<setprecision(10)<<fixed<<pi*mx*mx-pi*mn*mn<<endl;
     return 0;
}