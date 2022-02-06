/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 16:25                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/558/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],n,mx;
int ck(int vl)
{
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    int x=aa[i];
    if(x>vl)
    {
      while(x>vl)
      {
        if(x>1&&(x%2==1)&&(x-1==vl))
        {
          cnt+=2;x=vl;break;
        }
        x/=2;cnt++;
      }
      if(x!=vl)return 1e9;
    }
    else
    {
      while(x<vl)
      {
        x*=2;cnt++;
      }
      if(x!=vl)return 1e9;
    }
  }
  return cnt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;int ans=1e9;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];mx=max(mx,aa[i]);
  }
  while(mx)
  {
    ans=min(ans,ck(mx));
    mx/=2;
  }
  cout<<ans<<endl;
  return 0;
}