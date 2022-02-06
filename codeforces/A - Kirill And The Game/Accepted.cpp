/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/13/2017 19:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/842/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long l,r,x,y,z,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>l>>r>>x>>y>>k;
     for(long i=l;i<=r;i++)
    {
        if(i%k!=0)continue;
        z=i/k;
        if(z>=x&&z<=y)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
     return 0;
}