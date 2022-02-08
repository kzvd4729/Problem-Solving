/****************************************************************************************
*  @author: kzvd4729                                         created: 06-10-2018 14:15:43                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.28 sec                                        memory_used: 23.3M                                
*  problem: https://www.codechef.com/OCT18A/problems/MINDSUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long R=1e6;
long vis[R+2];
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
  long t;cin>>t;
  while(t--)
  {
    long n,d;cin>>n>>d;memset(vis,-1,sizeof(vis));
    queue<pair<long,long> >q;q.push({n,0});long cnt=0;
    while(q.size())
    {
      pair<long,long>p=q.front();q.pop();
      if(p.first<=R)vis[p.first]=p.second;
      if(p.first+d>R)q.push({p.first+d,p.second+1});
      else if(vis[p.first+d]==-1)q.push({p.first+d,p.second+1});
      long dg=digitsum(p.first);
      if(vis[dg]==-1)
        q.push({dg,p.second+1});
      ++cnt;if(cnt>R)break;
    }
    for(long i=1;i<=R;i++)
    {
      if(vis[i]!=-1)
      {
        cout<<i<<" "<<vis[i]<<endl;
        break;
      }
    }
  }
  return 0;
}