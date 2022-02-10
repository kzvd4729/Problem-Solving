/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-22 15:27:32                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1066
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 12
using namespace std;
long t,n,vis[N][N],dis[N][N],tc;
string s;
char mat[N][N],cc;
long dr[]={1,-1,0,0};
long dc[]={0,0,1,-1};
queue<pair<long,long> >q;
long bfs(long r,long c,char d)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    while(!q.empty())q.pop();
    q.push({r,c});
    while(!q.empty())
    {
        long m1=q.front().first;
        long m2=q.front().second;
        q.pop();
        for(long i=0;i<4;i++)
        {
            long m3=m1+dr[i];
            long m4=m2+dc[i];
            if(mat[m3][m4]==d)return dis[m1][m2]+1;
            if(vis[m3][m4]==0&&m3>=1&&m3<=n&&m4>=1&&m4<=n&&mat[m3][m4]=='.')
            {
                q.push({m3,m4});
                vis[m3][m4]=1;
                dis[m3][m4]=dis[m1][m2]+1;
            }
        }
    }
    return -1;
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
        cin>>n;
        cc='A';
        for(long i=1;i<=n;i++)
        {
            cin>>s;
            for(long j=0;j<n;j++)
            {
                if(s[j]>='A'&&s[j]<='Z')cc=max(cc,s[j]);
                mat[i][j+1]=s[j];
            }
        }
        if(cc=='A')
        {
            cout<<"Case "<<++tc<<": "<<0<<endl;
            continue;
        }
        long f=0,sum=0,dd;
        for(char k='A';k<cc;k++)
        {
            for(long i=1;i<=n;i++)
            {
                for(long j=1;j<=n;j++)
                {
                    if(mat[i][j]==k)
                    {
                        dd=bfs(i,j,k+1);
                        ///cout<<dd<<endl;
                        sum+=dd;
                        if(dd==-1)f=1;
                    }
                }
            }
        }
        if(f)cout<<"Case "<<++tc<<": Impossible"<<endl;
        else cout<<"Case "<<++tc<<": "<<sum<<endl;
    }

    return 0;
}