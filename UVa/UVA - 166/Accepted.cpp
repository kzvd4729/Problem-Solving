/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-10-05 12:38:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 50                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-166
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 99999999999
using namespace std;
long a,b,c,d,e,f,coin[2003],cn[8],id,total,dp[2003][2003],dp2[2003];
double tot;
void make_coin(void)
{
    id=0;
    for(long i=1; i<=a; i++)
    {
        coin[++id]=1;
    }
    for(long i=1; i<=b; i++)
    {
        coin[++id]=2;
    }
    for(long i=1; i<=c; i++)
    {
        coin[++id]=4;
    }
    for(long i=1; i<=d; i++)
    {
        coin[++id]=10;
    }
    for(long i=1; i<=e; i++)
    {
        coin[++id]=20;
    }
    for(long i=1; i<=f; i++)
    {
        coin[++id]=40;
    }
}
void mem(void)
{
    for(long i=0; i<2001; i++)
    {
        for(long j=0; j<2001; j++)
        {
            dp[i][j]=inf;
        }
    }
}
void make_dp2(void)
{
    cn[1]=1,cn[2]=2,cn[3]=4,cn[4]=10,cn[5]=20,cn[6]=40;
    for(long j=1; j<2001; j++)
    {
        dp2[j]=inf;
    }
    for(long i=0; i<=1000; i++)
    {
        for(long j=1; j<=6; j++)
        {
            if(dp2[i]!=inf)
            {
                dp2[i+cn[j]]=min(dp2[i+cn[j]],dp2[i]+1);
            }
        }
    }
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>a>>b>>c>>d>>e>>f)
    {
        if(!a&&!b&&!c&&!d&&!e&&!f)break;
        make_coin();
        cin>>tot;
        tot*=100.00;
        total=(long)tot;
        total=(total+1)/5;
        ///cout<<total<<endl;
        mem();
        dp[0][0]=0;
        for(long i=1; i<=id; i++)
        {
            for(long j=0; j<=500; j++)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                if(dp[i-1][j]!=inf)dp[i][j+coin[i]]=min(dp[i][j+coin[i]],dp[i-1][j]+1);
            }
        }
        make_dp2();
        //cout<<dp2[17]<<endl;
        //cout<<dp[id][40]<<endl;
        long ans=inf;
        ///cout<<dp[id][120]<<endl;
        for(long i=total; i<=1000; i++)
        {
            if(dp[id][i]!=inf&&dp2[i-total]!=inf)
            {
                /*if(dp[id][i]+dp2[i-total]<ans)
                {
                    cout<<i<<endl;
                    cout<<i-total<<endl;
                    cout<<total<<endl;
                    cout<<dp[id][i]<<" "<<dp2[i-total]<<endl;
                }*/
                ans=min(ans,dp[id][i]+dp2[i-total]);
            }
        }
        cout<<setw(3)<<ans<<endl;
    }
    return 0;
}