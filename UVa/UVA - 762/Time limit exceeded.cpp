/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-14 22:51:22                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-762
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long cnt,id,dis[10004],f,n;
vector<long>adj[10003],ans[10004],print;
map<string,long>mp;
string s[10004],u,v;
queue<long>q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n)
    {
        if(cnt)cout<<endl;
        cnt++;

        for(long i=0; i<=10000; i++)adj[i].clear();
        memset(dis,-1,sizeof(dis));
        while(q.size())q.pop();
        print.clear();
        id=0;
        f=0;

        for(long i=1; i<=n; i++)
        {
            cin>>u>>v;
            if(mp[u]==0)mp[u]=++id;
            s[id]=u;
            if(mp[v]==0)mp[v]=++id;
            s[id]=v;

            adj[mp[u]].push_back(mp[v]);
            adj[mp[v]].push_back(mp[u]);

        }
        cin>>u>>v;
        q.push(mp[u]);
        dis[mp[u]]=0;

        while(q.size())
        {
            long x=q.front();
            q.pop();
            for(long i=0; i<adj[x].size(); i++)
            {
                long z=adj[x][i];
                if(dis[z]!=-1)continue;
                dis[z]=dis[x]+1;
                ans[z].push_back(x);
                if(z==mp[v])
                {
                    f=1;
                    break;
                }
                q.push(z);
            }
            if(f)break;
        }

        if(!f)cout<<"No route"<<endl;
        else
        {
            long tmp=mp[v];
            print.push_back(tmp);
            while(true)
            {
                tmp=ans[tmp][0];
                print.push_back(tmp);
                if(tmp==mp[u])break;
            }
            for(long i=print.size()-1; i>=1; i--)
            {
                cout<<s[print[i]]<<" "<<s[print[i-1]]<<endl;
            }
        }
    }
    return 0;
}