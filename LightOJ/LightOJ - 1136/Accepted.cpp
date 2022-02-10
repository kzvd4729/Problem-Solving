/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-21 00:45:38                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1136
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,a,b;
int _find(int x)
{
  int ret=(x/3)*2;
  x=x%3;
  if(x)ret+=x-1;
  return ret;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&a,&b);
    printf("Case %d: %d\n",++tc,_find(b)-_find(a-1));
  }
  return 0;
}