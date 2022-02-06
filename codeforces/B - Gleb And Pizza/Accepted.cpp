/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2017 23:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1060 ms                                         memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/842/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
double r,d,x,y,rd;
long n,ans;
double dist(double x,double y,double xx,double yy)
{
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>r>>d;
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x>>y>>rd;
        if(dist(0,0,x,y)+rd<=r&&dist(0,0,x,y)-rd>=r-d)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
 