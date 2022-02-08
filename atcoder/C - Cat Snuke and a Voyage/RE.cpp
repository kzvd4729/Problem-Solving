/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-29 18:13:43                      
*  solution_verdict: RE                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 242 ms                                          memory_used: 1792 KB                              
*  problem: https://atcoder.jp/contests/abc068/tasks/arc079_a
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,m,vis1[300000],vis2[300000],a,b,i;
int main()
{
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        if(a==1)
        {
            vis1[b]=1;
        }
        if(b==1)
        {
            vis1[a]=1;
        }
        if(a==n)
        {
            vis2[b]=1;
        }
        if(b==n)
        {
            vis2[a]=1;
        }
    }
    for(i=0;i<=300000;i++)
    {
        if(vis1[i]==1&&vis2[i]==1)
        {
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
     return 0;
}