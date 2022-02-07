/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-10-02 20:24:08                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-116
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 99999999999999;
using namespace std;
long r,c,mat[12][102],dp[12][102],pr[102];
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>r>>c)
    {
        for(long i=1; i<=r; i++)
        {
            for(long j=1; j<=c; j++)
            {
                cin>>mat[i][j];
            }
        }
        for(long i=0; i<12; i++)
        {
            for(long j=0; j<102; j++)
            {
                dp[i][j]=inf;
            }
        }
        for(long i=1; i<=r; i++)
        {
            dp[i][1]=mat[i][1];
        }
        for(long j=2; j<=c; j++)
        {
            for(long i=1; i<=r; i++)
            {
                long ii,jj;
                jj=j-1;
                ii=i;
                dp[i][j]=min(dp[i][j],dp[ii][jj]+mat[i][j]);
                ii=i-1;
                if(ii==0)ii=r;
                dp[i][j]=min(dp[i][j],dp[ii][jj]+mat[i][j]);
                ii=i+1;
                if(ii>r)ii=1;
                dp[i][j]=min(dp[i][j],dp[ii][jj]+mat[i][j]);

            }
        }
        long ans,last,id=0,now;
        ans=inf;
        for(long i=1; i<=r; i++)
        {
            if(dp[i][c]<ans)
            {
                ans=dp[i][c];
                last=i;
            }
        }
        for(long i=0; i<102; i++)pr[i]=inf;
        pr[++id]=last;
        for(long j=c-1; j>=1; j--)
        {
            ans-=mat[last][j+1];
            now=inf;
            long ii;
            ii=last;
            if(dp[ii][j]==ans)now=min(now,ii);
            ii=last-1;
            if(ii==0)ii=r;
            if(dp[ii][j]==ans)now=min(now,ii);
            ii=last+1;
            if(ii>r)ii=1;
            if(dp[ii][j]==ans)now=min(now,ii);
            pr[++id]=now;
            last=now;
        }
        for(long i=id; i>=1; i--)
        {
            cout<<pr[i];
            if(i==1)cout<<endl;
            else cout<<" ";
        }
        cout<<dp[pr[1]][c]<<endl;
    }
    return 0;
}