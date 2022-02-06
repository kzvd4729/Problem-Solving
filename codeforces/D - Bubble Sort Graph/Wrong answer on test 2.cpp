/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2018 18:58                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/340/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,x,bit[200005];
void upd(int idx)
{
    for( ;idx<=n;idx+=idx&-idx)bit[idx]++;
}
int query(int idx)
{
    int sum=0;
    for( ;idx>0;idx-=idx&-idx)sum+=bit[idx];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ans=max(ans,query(x-1)+1);
        upd(x);
    }
    cout<<ans<<endl;
     return 0;
}