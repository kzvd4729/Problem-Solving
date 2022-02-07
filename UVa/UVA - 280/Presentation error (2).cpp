/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-03 15:50:54                      
*  solution_verdict: Presentation error                      language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-280
****************************************************************************************/
#include<bits/stdc++.h>

using namespace std;

vector<int>graph[110];
int color[110];

void resetColor(int m)
{
    for(int i=0; i<=m; i++)
    {
        color[i]=0;
    }
}

void init(int m)
{
    resetColor(m);
    for(int i=0; i<=m; i++)
    {
        graph[i].clear();
    }
}

bool isValidMove(int n)
{
    if(color[n]==0)return true;
    return false;
}

void dfs(int node)
{
  for(auto x:graph[node])
  {
    if(color[x]==0)
    {
      color[x]=1;
      dfs(x);
    }
  }
}
int main()
{
    int n,u,v,q;
    while(cin>>n)
    {
        if(n==0)break;

        init(n);

        while(cin>>u)
        {
            if(u==0)break;
            while(cin>>v)
            {
                if(v==0)break;
                graph[u].push_back(v);
            }
        }

        cin>>q;
        while(q--)
        {
            vector<int>vv;
            int cnt=0;
            cin>>u;
            resetColor(n);
            dfs(u);
            for(int i=1;i<=n;i++)
            {
              if(color[i]==0)
              {
                cnt++;
                vv.push_back(i);
              }
            }
            cout<<cnt<<" ";
            for(auto x:vv)
              cout<<x<<" ";
            cout<<endl;

        }
    }
}
/*

*/