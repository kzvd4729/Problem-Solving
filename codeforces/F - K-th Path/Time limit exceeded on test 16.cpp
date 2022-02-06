/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/29/2019 16:51                        
*  solution_verdict: Time limit exceeded on test 16          language: GNU C++14                               
*  run_time: 2500 ms                                         memory_used: 28000 KB                             
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
    md=(lo+hi)/2;int cnt=0;
    for(int i=1;i<=n;i++)
    {
      priority_queue<pair<long,int> >pq;
      pq.push({0,i});
      vector<int>tmp;set<int>st;
       while(pq.size())
      {
        pair<long,int>p=pq.top();pq.pop();
        int nd=p.second;long cs=-p.first;
        dis[nd]=cs;tmp.push_back(nd);
        if(cnt+st.size()>=k+k)break;
         for(auto x:adj[nd])
        {
          if(cs+x.second<=md&&cs+x.second<dis[x.first])
            pq.push({-cs-x.second,x.first}),st.insert(x.first);
        }
      }
      cnt+=st.size();
      for(auto x:tmp)dis[x]=LLONG_MAX;tmp.clear();
      if(cnt>=k+k)break;
    }
    if(cnt>=k+k)hi=md;
    else lo=md+1;
  }
  cout<<lo<<endl;
  return 0;
}