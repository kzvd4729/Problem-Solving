/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2017 22:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/507/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
double r,x,y,xx,yy;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>r>>x>>y>>xx>>yy;
    double dist=sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
    if(x==xx&&y==yy)
    {
        cout<<0<<endl;
        return 0;
    }
    for(double i=1;  ;i+=1.0)
    {
        if(i*2*r+1e-6>=dist)
        {
            cout<<setprecision(0)<<fixed<<i<<endl;
            return 0;
        }
    }
     return 0;
}
 