/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/09/2020 14:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 312 ms                                          memory_used: 14200 KB                             
*  problem: https://codeforces.com/contest/749/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=2e5;
int ls[N+1],b[N+2],tmp[N+2],vis[N+2];
vector<int>po[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<=n;i++)po[i].push_back(0);
  for(int i=1;i<=n;i++)
  {
    int a;cin>>a>>b[i];
    po[a].push_back(i);
  }
  priority_queue<pair<int,int> >pq;
  for(int i=0;i<=n;i++)
  {
    pq.push({po[i].back(),i});
    //cout<<i<<" --> "<<po[i].back()<<endl;
  }
  int q;cin>>q;
  while(q--)
  {
    int x;cin>>x;
    for(int i=1;i<=x;i++)cin>>tmp[i],vis[tmp[i]]=1;
     vector<pair<int,int> >bf;pair<int,int>p;
    while(true)
    {
      p=pq.top();if(!vis[p.second])break;
      bf.push_back(p);pq.pop();
    }
    for(auto z:bf)pq.push(z);
    for(int i=1;i<=x;i++)vis[tmp[i]]=0;
    if(p.first==0)cout<<0<<" "<<0<<"\n";
    else
    {
      int a=p.second;//cout<<po[a][1]<<" "<<po[a][2]<<endl;
      int lo=1,hi=po[a].size()-1,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;int rm=n-po[a][md]+1-(po[a].size()-md);
        for(int i=1;i<=x;i++)
        {
          int c=lower_bound(po[tmp[i]].begin(),po[tmp[i]].end(),po[a][md])-po[tmp[i]].begin();
          rm-=(po[tmp[i]].size()-c);
        }
        assert(rm>=0);
        if(rm==0)hi=md;else lo=md;
      }
      for(md=lo;md<=hi;md++)
      {
        int rm=n-po[a][md]+1-(po[a].size()-md);
        for(int i=1;i<=x;i++)
        {
          int c=lower_bound(po[tmp[i]].begin(),po[tmp[i]].end(),po[a][md])-po[tmp[i]].begin();
          rm-=(po[tmp[i]].size()-c);
        }
        assert(rm>=0);
        if(rm==0)break; 
      }
      cout<<a<<" "<<b[po[a][md]]<<"\n";
    }
  }
  return 0;
}