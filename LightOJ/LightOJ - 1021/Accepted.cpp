/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-17 23:46:39                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 388                                        memory_used (MB): 13                              
*  problem: https://vjudge.net/problem/LightOJ-1021
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,b,k,dp[1<<16][22],mp[403],tc;
char s[20];
void make_map(void)
{
  mp['0']=0;
  mp['1']=1;
  mp['2']=2;
  mp['3']=3;
  mp['4']=4;
  mp['5']=5;
  mp['6']=6;
  mp['7']=7;
  mp['8']=8;
  mp['9']=9;
  mp['A']=10;
  mp['B']=11;
  mp['C']=12;
  mp['D']=13;
  mp['E']=14;
  mp['F']=15;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  make_map();

  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld%lld",&b,&k);
    scanf("%s",s);
    int l=strlen(s);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int msk=0;msk<(1<<l);msk++)
    {
      for(int i=0;i<l;i++)
      {
        if(msk&(1<<i))continue;
        for(int m=0;m<k;m++)
        {
          if(!dp[msk][m])continue;
          dp[msk|(1<<i)][(m*b+mp[s[i]])%k]+=dp[msk][m];
        }
      }
    }
    printf("Case %lld: %lld\n",++tc,dp[(1<<l)-1][0]);
  }
  return 0;
}