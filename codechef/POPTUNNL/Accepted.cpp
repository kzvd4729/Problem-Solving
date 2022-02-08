/****************************************************************************************
*  @author: kzvd4729                                         created: 25-01-2020 19:43:18                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 72.3M                                
*  problem: https://www.codechef.com/LTIME80A/problems/POPTUNNL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s[N+2];int d[N+2];
vector<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>s[i],adj[i].clear();
    for(int i=1;i<=n;i++)
    {
      for(int j=i-k;j<=i+k;j++)
      {
        if(j<1||j>n)continue;
        if(s[i][j-1]=='1')adj[i].push_back(j);
      }
    }
    for(int i=1;i<=n;i++)d[i]=1e9;
    queue<int>q;q.push(1);d[1]=0;
    while(q.size())
    {
      int u=q.front();q.pop();
      for(auto v:adj[u])
      {
        if(d[u]+1<d[v])
          d[v]=d[u]+1,q.push(v);
      }
    }
    if(d[n]==1e9)d[n]=-1;
    cout<<d[n]<<"\n";
  }
    return 0;
}