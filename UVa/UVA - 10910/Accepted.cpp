/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-24 22:45:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 80                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10910
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,n,total,p,c,k,q;
long long int dp[100][100];
long long int coin[100];
long long int f(long long int vl,long long int rm)
{
    long long int i,x;
    if(rm==0)
    {
        if(vl==0)return 1;
        else return 0;
    }
    if(dp[vl][rm]!=-1)return dp[vl][rm];
    x=0;
    for(i=0;i<=k;i++)
    {
        if((vl-coin[i])>=0)
        {
            x=x+f(vl-coin[i],rm-1);
        }
    }

    dp[vl][rm]=x;

    return x;

}
int main()
{
    memset(dp,-1,sizeof(dp));
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n>>total>>p;
            c=total-((n-1)*p);
            k=-1;
            for(int j=p;j<=c;j++)
            {
                coin[++k]=j;
            }
            memset(dp,-1,sizeof(dp));
            q=f(total,n);
            cout<<q<<endl;

        }

    }

    return 0;
}