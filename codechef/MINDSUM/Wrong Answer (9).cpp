/****************************************************************************************
*  @author: kzvd4729                                         created: 07-10-2018 12:03:15                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 1.26 sec                                        memory_used: 165.7M                               
*  problem: https://www.codechef.com/OCT18A/problems/MINDSUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long R=5e6;
unordered_map<long,int>vis;
long digitsum(long x)
{
  long ret=0;
  while(x)
  {
    ret+=x%10;x/=10;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vis.max_load_factor(0.25);vis.reserve((1<<24));
  long t;cin>>t;
  while(t--)
  {
    long n,d;cin>>n>>d;vis.clear();
    queue<pair<long,long> >q;q.push({n,0});long cnt=0;
    while(q.size())
    {
      pair<long,long>p=q.front();q.pop();
      vis[p.first]=p.second;
      if(!vis[p.first+d])q.push({p.first+d,p.second+1});
      long dg=digitsum(p.first);
      if(!vis[dg])
        q.push({dg,p.second+1});
      ++cnt;if(cnt>R)break;
      if(vis[1])break;
    }
    if(n==1)
      cout<<1<<" "<<0<<endl;
    else
    {
      for(long i=1;i<=R;i++)
      {
        if(vis[i])
        {
          cout<<i<<" "<<vis[i]<<endl;
          break;
        }
      }
    }
  }
  return 0;
}