/****************************************************************************************
*  @author: kzvd4729                                         created: 09-07-2017 16:10:14                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/JULY17/problems/PSHTTR
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,vis[1003],n,i,u,v,c,x,y,xx,yy,ans,cost[1003][1003],m,f,cnt=0;
vector<int>adj[1003];
queue<pair<int,int> >q;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1; i<n; i++)
        {
            cin>>u>>v>>c;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u][v]=c;
            cost[v][u]=c;
        }
        cin>>m;
        while(m--)
        {
            memset(vis,0,sizeof(vis));
            f=0;
            cin>>u>>v>>c;
            q.push(make_pair(u,0));
            vis[u]=1;
            while(!q.empty())
            {
                x=q.front().first;
                y=q.front().second;
                q.pop();
                for(i=0; i<adj[x].size(); i++)
                {
                    if(vis[adj[x][i]]==0)
                    {
                        vis[adj[x][i]]=1;
                        xx=adj[x][i];
                        yy=cost[x][xx];
                        ///cout<<xx<<endl;
                        if(yy<=c)yy=y^yy;
                        else yy=y;
                        if(xx==v)
                        {
                            ans=yy;
                            f=1;
                            break;
                        }
                        q.push(make_pair(xx,yy));
                    }
                }
                if(f==1)break;
            }
            while(q.size())q.pop();
            cout<<ans<<endl;
        }
    }
    return 0;
}