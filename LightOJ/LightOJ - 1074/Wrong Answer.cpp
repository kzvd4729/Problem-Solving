/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-27 18:06:34                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1074
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int fre[12],n;
void con(int x)
{
  while(x)
  {
    fre[x%10]++;
    x/=10;
  }
}
int main()
{
  for(int i=2546;i<=3020;i++)
  {
    n=i;
    memset(fre,0,sizeof(fre));
    for(int j=1;j<=n;j++)
      con(j);
    int mn=0,ans;
    for(int j=1;j<=9;j++)
    {
      if(fre[j]>=mn)
        mn=fre[j],ans=j;
    }
    cout<<n<<" "<<ans<<endl;
  }
  return 0;
}