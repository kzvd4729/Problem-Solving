/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/21/2019 19:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/1146/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2],cnt;
long sum(long lt,long rt)
{
  long hi=(rt*(rt+1))/2;
  long lo=(lt*(lt-1))/2;
  return hi-lo;
}
long cal(int lt,int rt,int g)
{
  long ret=0;
  while(lt<=rt)
  {
    if(lt%g==0)break;
    ret+=lt/g;lt++;
  }
  while(rt>=lt)
  {
    if(rt%g==g-1)break;
    ret+=rt/g;rt--; 
  }
  if(lt>rt)return ret;
  return ret+sum(lt/g,rt/g)*g;
}
int a,b,n;
int dfs(int i)
{
  vis[i]=1;cnt++;
  if(i+a<=n&&!vis[i+a])
    dfs(i+a);
  if(i-b>=0&&!vis[i-b])
    dfs(i-b);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>m>>a>>b;int g=__gcd(a,b);
  int r=a+b-g;
  int rm=max(m-r+1,0);long ans=0;
  ans+=rm;if(rm)ans+=cal(r,m,g);
   cnt=1;ans++;vis[0]=1;
  for(int i=1;i<=min(r-1,m);i++)
  {
    n=i;
    if(i-a>=0&&vis[i-a])
      dfs(i);
    ans+=cnt;
  }
  cout<<ans<<endl;
  return 0;
}