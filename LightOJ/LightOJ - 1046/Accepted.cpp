/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-12-27 19:08:25                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 436                                        memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1046
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 999999999999
using namespace std;
long t,n,m,dis[12][12],tc;
char mat[12][12];
long dr[]= {1,1,2,2,-1,-1,-2,-2};
long dc[]= {2,-2,1,-1,2,-2,1,-1};
queue<pair<long,long> >q;
char tmp[100];
struct knight
{
    long nth,row,col;
};
vector<knight>v;
long k_move(long s1,long s2,long e1,long e2)
{
    for(long i=0; i<12; i++)
    {
        for(long j=0; j<12; j++)
        {
            dis[i][j]=inf;
        }
    }
    while(q.size())q.pop();
    dis[s1][s2]=0;
    q.push({s1,s2});
    while(q.size())
    {
        long x,y,xx,yy;
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(long i=0; i<8; i++)
        {
            xx=x+dr[i];
            yy=y+dc[i];
            if(xx<1||xx>n||yy<1||yy>m)continue;
            if(dis[xx][yy]<inf)continue;
            dis[xx][yy]=dis[x][y]+1;
            q.push({xx,yy});
        }
        if(dis[e1][e2]<inf)return dis[e1][e2];
    }
    return dis[e1][e2];
}
int main()
{
    ///ofstream cout("out.txt");
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    scanf("%lld",&t);
    while(t--)
    {
        v.clear();
        scanf("%lld",&n);
        scanf("%lld",&m);
        for(long i=1; i<=n; i++)
        {
            scanf("%s",tmp);
            for(long j=1;j<=strlen(tmp); j++)
            {
                mat[i][j]=tmp[j-1];
                if(mat[i][j]!='.')v.push_back({mat[i][j]-'0',i,j});
            }
        }
        long ans=inf;
        for(long i=1; i<=n; i++)
        {
            for(long j=1; j<=m; j++)
            {
                long sum=0;
                for(long k=0; k<v.size(); k++)sum=sum+((k_move(v[k].row,v[k].col,i,j)+v[k].nth-1)/v[k].nth);
                ans=min(ans,sum);
            }
        }
        printf("Case %lld: ",++tc);
        if(ans>10000)printf("-1\n");
        else printf("%lld\n",ans);
    }
    return 0;
}