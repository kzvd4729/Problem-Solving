/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2018 15:08                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++17                               
*  run_time: 140 ms                                          memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/851/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans,cnt;
double p[1003][7];
vector<long>v;
double ret(long a,long b)
{
    double rt=0;
    for(long j=1;j<=5;j++)rt+=p[a][j]*p[b][j];
    return rt;
}
double ang(long a,long b)
{
    double tmp=ret(a,b)/(fabs(ret(a,a))*fabs(ret(b,b)));
    return acos(tmp);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=5;j++)
        {
            cin>>p[i][j];
        }
    }
    for(long i=1;i<=n;i++)
    {
        cnt=0;
        for(long j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(ang(i,j)<90.00)cnt++;
        }
        if(cnt<2)v.push_back(i);
    }
    cout<<v.size()<<endl;
    for(auto x:v)cout<<x<<" ";
    cout<<endl;
    return 0;
}