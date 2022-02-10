/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-01 11:14:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 252                                        memory_used (MB): 2.5                             
*  problem: https://vjudge.net/problem/LightOJ-1325
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************ Baby Step Giant Step ************/
long BsGs(long a,long b,long m)
{
  //Find such k that a^k(mod m)=b;
  int n=sqrt(m+1);long an=1;
  for(int i=0;i<n;i++)an=(an*a)%m;
  unordered_map<int,int>mp;//unoedered is good choice
  long cur=an;
  for(int i=1;i<=n;i++)
  {
    if(!mp.count(cur))
      mp[cur]=i;
    cur=(cur*an)%m;
  }
  cur=b;long ret=1e18;
  for(int i=0;i<=n;i++)
  {
    if(mp.count(cur))
    {
      long ans=mp[cur]*n-i;
      if(ans<m)ret=min(ret,ans);
      //modify for largest/smallest solution
    }
    cur=(cur*a)%m;
  }
  return ret;
}
////////////////////////////////////////////////////
int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int a,b;scanf("%d%d",&a,&b);
    printf("Case %d: %lld\n",++tc,BsGs(a,b,100000007));
  }
  return 0;
}