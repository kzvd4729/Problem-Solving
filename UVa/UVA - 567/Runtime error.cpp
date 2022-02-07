/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-10 19:36:28                      
*  solution_verdict: Runtime error                           language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-567
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 999999999
using namespace std;
long u,v,mat[102][102],cnt,tc,f;
void mem(void)
{
    for(long i=1; i<=100; i++)
    {
        for(long j=1; j<=100; j++)
        {
            if(i==j)mat[i][j]=0;
            else mat[i][j]=inf;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    f=0;
    while(true)
    {
        mem();
        while(cin>>u>>v)
        {
            if(u==0&&v==0)break;
            f=1;
            mat[u][v]=1;
        }
        if(f==0)break;
        f=0;
        for(long k=1; k<=100; k++)
        {
            for(long i=1; i<=100; i++)
            {
                for(long j=1; j<=100; j++)
                {
                    if(mat[i][k]+mat[k][j]<mat[i][j])mat[i][j]=mat[i][k]+mat[k][j];
                }
            }
        }
        double sum=0,cnt=0;
        for(long i=1; i<=100; i++)
        {
            for(long j=1; j<=100; j++)
            {
                if(mat[i][j]!=inf&&mat[i][j]!=0)
                {
                    cnt++;
                    sum+=mat[i][j];
                }
            }
        }
        double ans=sum/cnt;
        cout<<"Case "<<++tc<<": average length between pages = "<<setprecision(3)<<fixed<<ans<<" clicks"<<endl;

    }
    return 0;
}