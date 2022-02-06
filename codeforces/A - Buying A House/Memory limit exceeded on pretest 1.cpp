/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2017 22:42                        
*  solution_verdict: Memory limit exceeded on pretest 1      language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/796/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,k,arr[1000],vis[1000],d,dd,i;
    cin>>n>>m>>k;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]>0&&arr[i]<=k)vis[i]=1;
    }
     dd=999999999;
     for(i=1;i<=n;i++)
    {
        if(vis[i]==1)
        {
            d=abs(i-m)*10;
            if(d<dd)dd=d;
        }
    }
    cout<<dd<<endl;
    main();
    return 0;
}