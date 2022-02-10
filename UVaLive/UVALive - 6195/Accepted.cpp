/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-11 21:40:34                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 149                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6195
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ind[1003],n,m,u,v,x;
vector<long>adj[1003];
queue<long>q;
void mem(void)
{
    for(long i=1;i<=n;i++)
    {
        adj[i].clear();
        ind[i]=0;
    }
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;

        mem();

        for(long i=1;i<=m;i++)
        {
            cin>>u>>v;
            ind[v]++;
            adj[u].push_back(v);
        }
        for(long i=1;i<=n;i++)
        {
            if(ind[i]==0)q.push(i);
        }
        long two=0;
        while(q.size())
        {
            if(q.size()>=2)two=1;
            x=q.front();
            q.pop();
            n--;
            for(long i=0;i<adj[x].size();i++)
            {
                long z=adj[x][i];
                ind[z]--;
                if(ind[z]==0)q.push(z);
            }
        }
        if(n)cout<<0<<endl;
        else
        {
            if(two==0)cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
    return 0;
}