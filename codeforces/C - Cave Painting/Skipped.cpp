/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2018 00:26                        
*  solution_verdict: Skipped                                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/922/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,vis[1000006];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    for(int i=1;i<=min(k,1000000LL);i++)
    {
        long x=n%i;
        if(vis[x])
        {
            cout<<"NO"<<endl;
            return 0;
        }
        vis[x]=1;
    }
    cout<<"YES"<<endl;
    return 0;
}