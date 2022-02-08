/****************************************************************************************
*  @author: kzvd4729                                         created: 04-03-2019 16:00:15                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/MARCH19A/problems/CHONQ
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long bit[N+2],aa[N+2];
const double eps=1e-9;
void upd(long x,long vl)
{
  if(x<=0)x=1;
  for( ;x<=N;x+=x&-x)
    bit[x]+=vl*1LL;
}
long get(long x)
{
  long ret=0;
  for( ;x>0;x-=x&-x)
    ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
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
        if(lt>rt||(sq>=lt&&sq<=rt))continue;
        upd(i-rt+1,j);upd(i-lt+2,-j);
      }
    }
    int f=0;
    for(long i=1;i<=n+1;i++)
    {
      if(get(i)<=k)
      {
        cout<<i<<endl;f=1;
        break;
      }
      //cout<<get(i)<<endl;
    }
    assert(f);
  }
/*6
6
8
10
8
10
12
14
14
24*/
  return 0;
}