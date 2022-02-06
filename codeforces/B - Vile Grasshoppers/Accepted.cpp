/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2018 22:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/937/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long p,y;
bool check(long x)
{
    long lim=sqrt(x);
    for(long i=2;i<=lim+1;i++)
    {
        if(x%i==0)
        {
            if(i>p)return true;
            else return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>p>>y;
    for(long i=y;i>p;i--)
    {
        if(check(i))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}