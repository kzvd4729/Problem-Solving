/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2017 19:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/869/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,x[2002],y[2002],mp[4000006];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i];
        mp[x[i]]=1;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>y[i];
        mp[y[i]]=1;
    }
    int tmp,ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            tmp=x[i]^y[j];
            if(mp[tmp]==1)ans++;
        }
    }
    if(ans%2==0)cout<<"Karen"<<endl;
    else cout<<"Koyomi"<<endl;
    ///cout<<ans<<endl;
     return 0;
}