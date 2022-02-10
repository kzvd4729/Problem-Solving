/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 01:36:48                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1066
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
char tar;
long dr[]={0,1,0,-1};
long dc[]={1,0,-1,0};
long n,f,t,tc;
string s[20];
long bfs(char bg,char en)
{
    ///cout<<bg<<" "<<en<<endl;
    queue<pair<long,long> >q;
    while(q.size())q.pop();
    long dis[20][20],vis[20][20];
    for(long i=0;i<=15;i++)
    {
        for(long j=0;j<=15;j++)
        {
            vis[i][j]=0;
            dis[i][j]=-1;
        }
    }

    for(long i=0; i<n; i++)
    {
        for(long j=0; j<n; j++)
        {
            if(s[i][j]==bg)
            {
                q.push({i,j});
                vis[i][j]=1;
                dis[i][j]=0;
                s[i][j]='.';
            }
        }
    }
    while(q.size())
    {
        long u=q.front().first;
        long v=q.front().second;
        ///cout<<u<<" "<<v<<endl;
        q.pop();
        for(long i=0;i<4;i++)
        {
            long uu=u+dr[i];
            long vv=v+dc[i];
            if(uu<0||uu>=n||vv<0||vv>=n)continue;
            if(s[uu][vv]==en)return dis[u][v]+1;
            if(vis[uu][vv]==0&&s[uu][vv]=='.')
            {
                vis[uu][vv]=1;
                dis[uu][vv]=dis[u][v]+1;
                q.push({uu,vv});
            }
        }

    }
    f=1;
    return 0;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long i=0; i<n; i++)
        {
            cin>>s[i];
        }
        tar='A';
        for(long i=0; i<n; i++)
        {
            for(long j=0; j<n; j++)
            {
                if(s[i][j]>='A'&&s[i][j]<='Z')
                {
                    tar=max(tar,s[i][j]);
                }
            }
        }
        long ans=0,ff=0;
        for(char i='A'; i<tar; i++)
        {
            f=0;
            ans+=bfs(i,i+1);
            ///cout<<ans<<endl;
            if(f)ff=1;
        }

        if(ff)cout<<"Case "<<++tc<<": Impossible"<<endl;
        else cout<<"Case "<<++tc<<": "<<ans<<endl;

    }


    return 0;
}