/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/13/2017 09:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 12600 KB                             
*  problem: https://codeforces.com/contest/839/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
double dfs(int n,int p)
{
    double cn=0.0;
    for(int x:adj[n])
    {
        if(x==p)continue;
        cn=cn+dfs(x,n)+1.0;
    }
    if(cn==0.0)return 0.0;
    else if(n==1)return cn/((double)adj[n].size());
    else return cn/((double)(adj[n].size()-1));
}
int main()
{
    int n,u,v;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<setprecision(10)<<fixed<<dfs(1,-1)<<endl;
     return 0;
}