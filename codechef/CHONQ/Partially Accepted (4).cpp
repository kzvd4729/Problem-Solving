/****************************************************************************************
*  @author: kzvd4729                                         created: 04-03-2019 16:27:41                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 1.78 sec                                        memory_used: 16.4M                                
*  problem: https://www.codechef.com/MARCH19A/problems/CHONQ
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5+4;
long bit[N+2],aa[N+2];
const double eps=1e-9;
void upd(long x,long vl)
{
  if(x<=0)x=1;bit[x]+=vl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n,k;cin>>n>>k;memset(bit,0,sizeof(bit));
    for(long i=1;i<=n;i++)cin>>aa[i];
    for(long i=1;i<=n;i++)
    {
      long sq=sqrt(aa[i]*1.0+eps);
      for(long j=1;j<=sq;j++)
      {
        upd(i-j+1,aa[i]/j);upd(i-j+2,-(aa[i]/j));
        long lt=(aa[i]/(j+1))+1,rt=aa[i]/j;
        lt=max(lt,sq+1);if(lt>rt)continue;
        upd(i-rt+1,j);upd(i-lt+2,-j);
      }
    }
    for(long i=1;i<=n+1;i++)
    {
      bit[i]+=bit[i-1];
      if(bit[i]<=k)
      {
        cout<<i<<"\n";
        break;
      }
    }
  }
  return 0;
}