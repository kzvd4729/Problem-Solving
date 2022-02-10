/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-06 19:48:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 86                                         memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-2071
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int fib[200],n,f,s,x,id,cnt;
vector<int>v;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fib[0]=0,fib[1]=1;
  cnt=2;
  for(int i=2;fib[i-1]<1e8;i++)fib[i]=fib[i-1]+fib[i-2],cnt++;
  while(cin>>n>>f>>s)
  {
    if(!n&&!f&&!s)break;
    v.clear();
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      id=lower_bound(fib,fib+cnt,x)-fib;
      v.push_back(fib[id]-x);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(auto x:v)
    {
      if(f>=x)
      {
        ans++;
        f-=x;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}