/****************************************************************************************
*  @author: kzvd4729                                         created: 04-03-2019 16:30:14                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.33 sec                                        memory_used: 16.8M                                
*  problem: https://www.codechef.com/MARCH19A/problems/CHONQ
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5+4;
long bit[N+2];int aa[N+2];
const double eps=1e-9;
inline void upd(int x,int vl)
{
  if(x<=0)x=1;bit[x]+=vl*1LL;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)
    {
      int sq=sqrt(aa[i]*1.0+eps);
      for(int j=1;j<=sq;j++)
      {
        upd(i-j+1,aa[i]/j);upd(i-j+2,-(aa[i]/j));
        int lt=(aa[i]/(j+1))+1,rt=aa[i]/j;
        lt=max(lt,sq+1);if(lt>rt)continue;
        upd(i-rt+1,j);upd(i-lt+2,-j);
      }
    }
    for(int i=1;i<=n+1;i++)
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