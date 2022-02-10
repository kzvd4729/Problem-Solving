/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-09 14:28:32                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 628                                        memory_used (MB): 4.8                             
*  problem: https://vjudge.net/problem/LightOJ-1003
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
map<string,vector<string> >mp;
map<string,long>vis;
vector<string>vec;
long t,m,f,tc;
string u,v;
void dfs(string rt)
{
    if(vis[rt]==1)
    {
        f=1;
        return ;
    }
    vis[rt]=1;
    for(long i=0; i<mp[rt].size(); i++)
    {
        dfs(mp[rt][i]);
    }
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        mp.clear();
        vis.clear();

        cin>>m;
        while(m--)
        {
            cin>>u>>v;
            mp[u].push_back(v);
            if(vis[u]==0)
            {
                vec.push_back(u);
                vis[u]=1;
            }
            if(vis[v]==0)
            {
                vec.push_back(v);
                vis[v]=1;
            }
        }
        f=0;
        vis.clear();
        for(long i=0; i<vec.size(); i++)
        {
            if(vis[vec[i]]==0)
            {
                vis.clear();
                dfs(vec[i]);
            }
            if(f==1)break;
        }
        if(f==1)cout<<"Case "<<++tc<<": No"<<endl;
        else cout<<"Case "<<++tc<<": Yes"<<endl;
    }
    return 0;
}