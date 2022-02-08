/****************************************************************************************
*  @author: kzvd4729                                         created: 07-10-2018 12:26:15                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 18.7M                                
*  problem: https://www.codechef.com/OCT18A/problems/MINDSUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ans[N+2];
int digitsum(long x)
{
  int ret=0;
  while(x)
  {
    ret+=x%10;x/=10;
  }
  return ret;
}
void dfs(long n,int ds,long d)
{
  if(n<10)ans[n]=min(ans[n],ds);
  if(ds>17)return ;
  dfs(n+d,ds+1,d);dfs(digitsum(n),ds+1,d);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,d;cin>>n>>d;
    for(int i=1;i<=10;i++)ans[i]=20;
    dfs(n,0,d);
    for(int i=1;i<=10;i++)
      if(ans[i]<20)
      {
        cout<<i<<" "<<ans[i]<<endl;
        break;
      }
  }
  return 0;
}