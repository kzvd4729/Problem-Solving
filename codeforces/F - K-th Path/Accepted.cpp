/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/29/2019 17:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2401 ms                                         memory_used: 28100 KB                             
*  problem: https://codeforces.com/contest/1196/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<pair<int,int> >adj[N+2];
long dis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  for(int i=1;i<=n;i++)dis[i]=LLONG_MAX;
  long lo=0,hi=1e12,md;
  while(lo<hi)
  {
    md=(lo+hi)/2;int cnt=0,f=0;
    for(int i=1;i<=n;i++)
    {
      priority_queue<pair<long,int> >pq;
      pq.push({0,i});
      vector<int>tmp;set<int>st;
      dis[i]=0;tmp.push_back(i);
       while(pq.size())
      {
        pair<long,int>p=pq.top();pq.pop();
        int nd=p.second;long cs=-p.first;
         for(auto x:adj[nd])
        {
          if(cs+x.second<=md&&cs+x.second<dis[x.first])
          {
            dis[x.first]=cs+x.second;tmp.push_back(x.first);
            pq.push({-cs-x.second,x.first}),st.insert(x.first);
            int sz=st.size();
            if(sz>=k||cnt+sz>=k+k){f=1;break;}
          }
        }
      }
      for(auto x:tmp)dis[x]=LLONG_MAX;tmp.clear();
      if(f)break;cnt+=st.size();
    }
    if(f)hi=md;else lo=md+1;
  }
  cout<<lo<<endl;
  return 0;
}