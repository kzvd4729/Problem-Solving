/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/23/2019 23:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1131/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;int mt=0;long ans=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        int l=max(0,x-mt+1);
        int m=max(0,y-mt+1);
        ans+=min(l,m)*1LL;
        mt=max(x,y);if(x==y)mt++;
            }
    cout<<ans<<endl;
    return 0;
}