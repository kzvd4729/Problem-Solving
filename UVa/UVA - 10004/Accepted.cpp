/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-25 01:47:18                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10004
****************************************************************************************/
#include<bits/stdc++.h>
#define white 0
#define black 1
using namespace std;
int adj[3000][3000];
int par[2000];
int dis[2000];
int col[2000];
int nodes,edges,test;
bool bfs(int first)
{
    for(int i=0;i<nodes;i++)
    {
        if(i!=first)
        {
            col[i]=-1;
            par[i]=-1;
            dis[i]=INT_MIN;
        }
    }
    col[first]=white;
    dis[first]=0;
    par[first]=-1;
    queue<int>q;
    q.push(first);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<201;i++)
        {
            if(adj[x][i]==1)
            {
                if(par[i]!=-1)
                  if(col[i]==col[x])
                    return false;
                if(col[i]==-1)
                {
                    q.push(i);
                    par[i]=x;
                    if(col[x]==white)col[i]=black;
                    else col[i]=white;
                }
            }
        }
    }
    return true;
}
int main()
{
    int n1,n2,first;
    while(cin>>nodes)
    {
        if(nodes==0)
            break;
        memset(adj,0,sizeof(adj));
        memset(par,0,sizeof(par));
        cin>>edges;
        for(int i=0;i<edges;i++)
        {
            cin>>n1>>n2;
            if(i==0)
                first=n1;
            adj[n1][n2]=1;
            adj[n2][n1]=1;
        }
        bool ans;
        ans=bfs(first);
        if(ans==true)
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;

    }
}