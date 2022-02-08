/****************************************************************************************
*  @author: kzvd4729                                         created: 31-08-2019 20:25:19                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.86 sec                                        memory_used: 30.3M                                
*  problem: https://www.codechef.com/LTIME75A/problems/DESTCELL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int aa[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;int id=0;
    for(int i=1;i<=m;i++)
      for(int j=i;j<=n*m;j+=m)
        aa[++id]=j;
    vector<int>clr;
    for(int i=1;i<=n*m;i++)
    {
      int ans=0;
      for(int j=1;j<=n*m;j+=i)
      {
        ans++,vis[j]=1;
        clr.push_back(j);
      }
      for(int j=1;j<=n*m;j+=i)
      {
        if(vis[aa[j]])continue;
        vis[aa[j]]=1;ans++;
        clr.push_back(aa[j]);
      }
      for(auto x:clr)vis[x]=0;
      clr.clear();
      cout<<ans;
      if(i==n*m)cout<<endl;
      else cout<<" ";
    }
  }
  return 0;
}