/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-12-17 21:47:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-COINS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
map<long,long>mp;
long n;
long fx(long x)
{
    if(x==0)return 0;
    if(mp[x]!=0)return mp[x];
    return mp[x]=max(x,fx(x/2)+fx(x/3)+fx(x/4));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n)
    {
        cout<<fx(n)<<endl;
    }
    return 0;
}