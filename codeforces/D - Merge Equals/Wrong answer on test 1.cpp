/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2018 22:25                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 11100 KB                             
*  problem: https://codeforces.com/contest/962/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,ans[1000006];
map<long,set<long> >mp,vs;
map<long,set<long> >::iterator it;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>x;
    mp[x].insert(i);
  }
  for(it=mp.begin();it!=mp.end();it++)
  {
    while(it->second.size()>1)
    {
      x=*it->second.begin();
      it->second.erase(x);
      x=*it->second.begin();
      it->second.erase(x);
       mp[it->first*2].insert(x);
     }
  }
  for(it=mp.begin();it!=mp.end();it++)
  {
    while(it->second.size())
    {
      x=*it->second.begin();
      it->second.erase(x);
      ans[x]=it->first;
    }
  }
  for(int i=1;i<=1000000;i++)
  {
    if(ans[i]==0)continue;
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}