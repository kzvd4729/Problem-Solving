/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/21/2020 22:21                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 124 ms                                          memory_used: 28900 KB                             
*  problem: https://codeforces.com/contest/1381/problem/C
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
//#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
int a[N+2],b[N+2];
vector<int>po[N+2];
void solve()
{
  int n,x,y;cin>>n>>x>>y;set<int>st;y-=x;
  for(int i=1;i<=n+1;i++)po[i].clear();
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];st.insert(a[i]);
    po[a[i]].push_back(i);
  }
  int inv;
  for(inv=1;inv<=n+1;inv++)
  {
    if(st.find(inv)==st.end())break;
  }
  //cout<<inv<<endl;
  priority_queue<pair<int,int> >pq;
  for(int i=1;i<=n+1;i++)pq.push({(int)po[i].size(),i});
  while(x--)
  {
    pair<int,int>p=pq.top();pq.pop();p.first--;pq.push(p);
    int nd=p.second;b[po[nd].back()]=nd;po[nd].pop_back();
  }
  vector<int>ord;
  pair<int,int>p=pq.top();pq.pop();
  ord.push_back(p.second);
   vector<int>str;
  while(pq.size())
  {
    pair<int,int>nw=pq.top();pq.pop();
    while(nw.first--)str.push_back(nw.second);
    ord.push_back(nw.second);
  }
  while(p.first--)str.push_back(p.second);
   //for(int i=0;i<ord.size();i++)cout<<ord[i]<<" ";cout<<endl;
   int pt=0;
  for(auto nd:ord)
  {
    while(po[nd].size())
    {
      int bk=po[nd].back();po[nd].pop_back();
      if(y==0)b[bk]=inv;
      else if(a[bk]==str[pt])b[bk]=inv;
      else b[bk]=str[pt++],y--;
    }
  }
  if(y)cout<<"NO\n";
  else
  {
    cout<<"YES\n";
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";
      cout<<"\n";
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}