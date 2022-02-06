/****************************************************************************************
*  @author: JU_AAA: aniks2645, kzvd4729, prdx9_abir          created: Sep/18/2017 19:39                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/847/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int l[105],r[105],vis[105];
int dfs(int node,int val)
{
    vis[node]=val;
     if(r[node]==0)return node;
    return dfs(r[node],val);
}
int main()
{
    int n,i,j,f,val,temp;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    memset(vis,-1,sizeof(vis));
    f=0;
    val=0;
    temp=0;
    for(i=1;i<=n;i++)
    {
        if(l[i]==0&&f==0&&vis[i]==-1)
        {
            f=1;
            temp=dfs(i,val);
            val++;
        }
        else if(f==1&&l[i]==0&&vis[i]==-1)
        {
            l[i]=temp;
            r[temp]=i;
            temp=dfs(i,val);
            val++;
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<l[i]<<" "<<r[i]<<endl;
    }
     return 0;
}