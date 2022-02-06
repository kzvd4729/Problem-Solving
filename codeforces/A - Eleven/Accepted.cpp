/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/29/2018 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2300 KB                              
*  problem: https://codeforces.com/contest/918/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int vis[100000],f[10000],n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     f[1]=1;
    f[2]=1;
    vis[1]=1;
    for(int i=3; ;i++)
    {
        f[i]=f[i-1]+f[i-2];
        vis[f[i]]=1;
        if(f[i]>1000)break;
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1)cout<<"O";
        else cout<<"o";
    }
    cout<<endl;
    return 0;
}