/****************************************************************************************
*  @author: kzvd4729                                         created: 31-03-2018 20:33:08                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.92 sec                                        memory_used: 91.5M                                
*  problem: https://www.codechef.com/LTIME58A/problems/ARRP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int t,n,arr[N+2],ans[N+2];
long qm[N+2],x,xx;
map<long,int>mp;
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    mp.clear();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&arr[i]);
      qm[i]=qm[i-1]+arr[i]*1LL;
      mp[qm[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
      if(qm[n]%i)continue;
      x=qm[n]/(i*1LL);
      xx=x;
      int f=0;
      for(xx=x;xx<=qm[n];xx+=x)
      {
        if(!mp[xx])
        {
          f=1;
          break;
          xx+=x;
        }
      }
      if(f==0)ans[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
      printf("%d",ans[i]);
      ans[i]=0;
    }
    printf("\n");
  }
  return 0;
}