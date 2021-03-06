/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/17/2019 21:16                        
*  solution_verdict: Wrong answer on pretest 9               language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4600 KB                              
*  problem: https://codeforces.com/contest/1236/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<int>row[N+2],col[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;long rm=n*m-k;
   for(int i=1;i<=k;i++)
  {
    int u,v;cin>>u>>v;
    row[u].push_back(v);
    col[v].push_back(u);
  }
  for(int i=1;i<=N;i++)
  {
    sort(row[i].begin(),row[i].end());
    sort(col[i].begin(),col[i].end());
  }
   long cnt=1;
  if(row[1].size()&&row[1][0]==2)
  {
    if(col[1].size()==0)cnt=n;
    else cnt=col[1][0]-1;
    if(cnt==rm)cout<<"Yes\n";
    else cout<<"No\n";
    exit(0);
  }
   int rw=1,cl=1,urw=0,drw=n+1,lcl=0,rcl=m+1;
  while(true)
  {
    int id=upper_bound(row[rw].begin(),row[rw].end(),cl)-row[rw].begin();
    if(id>=row[rw].size())id=m+1;
    else id=row[rw][id];
    id=min(id,rcl);id--;
    if(id-cl==0)break;cnt+=id-cl;cl=id;
    urw=rw;
      id=upper_bound(col[cl].begin(),col[cl].end(),rw)-col[cl].begin();
    if(id>=col[cl].size())id=n+1;
    else id=col[cl][id];
    id=min(id,drw);id--;
    if(id-rw==0)break;cnt+=id-rw;rw=id;
    rcl=cl;
     id=lower_bound(row[rw].begin(),row[rw].end(),cl)-row[rw].begin();
    id--;
    if(id<0)id=0;
    else id=row[rw][id];
    id=max(id,lcl);id++;
    if(cl-id==0)break;cnt+=cl-id;cl=id;
    drw=rw;
     id=lower_bound(col[cl].begin(),col[cl].end(),rw)-col[cl].begin();
    id--;
    if(id<0)id=0;
    else id=col[cl][id];
    id=max(id,urw);id++;
    if(rw-id==0)break;cnt+=rw-id;rw=id;
    lcl=cl;
   }
  if(cnt==rm)cout<<"Yes\n";
  else cout<<"No\n";
  return 0;
}