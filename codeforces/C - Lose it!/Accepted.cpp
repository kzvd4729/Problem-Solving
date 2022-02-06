/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/14/2019 19:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 15900 KB                             
*  problem: https://codeforces.com/contest/1176/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  set<int>st[7];int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x==4)st[1].insert(i);
    else if(x==8)st[2].insert(i);
    else if(x==15)st[3].insert(i);
    else if(x==16)st[4].insert(i);
    else if(x==23)st[5].insert(i);
    else if(x==42)st[6].insert(i);
  }
  int ans=0;
  while(true)
  {
    int pt=0,f=0;
    for(int i=1;i<=6;i++)
    {
      auto it=st[i].lower_bound(pt);
      if(it==st[i].end()){f=1;break;}
      pt=*it;st[i].erase(pt);
    }
    if(f)break;ans+=6;
  }
  cout<<n-ans<<endl;
  return 0;
}