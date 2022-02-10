/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-28 17:45:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 412                                        memory_used (MB): 13                              
*  problem: https://vjudge.net/problem/LightOJ-1021
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long t,b,k,dp[1<<16][22],arr[403],tc;
char s[20];
int main()
{
    arr['0']=0;
    arr['1']=1;
    arr['2']=2;
    arr['3']=3;
    arr['4']=4;
    arr['5']=5;
    arr['6']=6;
    arr['7']=7;
    arr['8']=8;
    arr['9']=9;
    arr['A']=10;
    arr['B']=11;
    arr['C']=12;
    arr['D']=13;
    arr['E']=14;
    arr['F']=15;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&b,&k);
        scanf("%s",s);
        int l=strlen(s);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int msk=0; msk<(1<<l); msk++)
        {
            for(int i=0; i<l; i++)
            {
                if(msk&(1<<i))continue;
                for(int m=0;m<k;m++)
                {
                    if(!dp[msk][m])continue;
                    dp[msk|(1<<i)][(m*b+arr[s[i]])%k]+=dp[msk][m];
                }
            }
        }
        printf("Case %lld: %lld\n",++tc,dp[(1<<l)-1][0]);
    }
    return 0;
}