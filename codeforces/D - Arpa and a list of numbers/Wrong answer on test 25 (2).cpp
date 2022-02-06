/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2018 14:17                        
*  solution_verdict: Wrong answer on test 25                 language: GNU C++17                               
*  run_time: 1107 ms                                         memory_used: 5800 KB                              
*  problem: https://codeforces.com/contest/851/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long vis[1003],ans=99999999999999999,n,a,b,arr[500005];
vector<long>prime;
void seive()
{
    prime.push_back(2);
    for(long i=4;i<=1000;i+=2)vis[i]=1;
    for(long i=3;i<=1000;i+=2)
    {
        if(vis[i])continue;
        prime.push_back(i);
        if(i*i>1000)continue;
        for(long j=i*i;j<=1000;j+=2*i)vis[j]=1;
    }
}
long check(long x)
{
    long sum=0;
    for(long i=1;i<=n;i++)
    {
        if(arr[i]%x)sum+=min(a,(x-(arr[i]%x))*b);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     seive();
    cin>>n>>a>>b;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(auto x:prime)ans=min(ans,check(x));
    cout<<ans<<endl;
    return 0;
}