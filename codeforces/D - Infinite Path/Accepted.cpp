/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2020 17:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 24400 KB                             
*  problem: https://codeforces.com/contest/1327/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long;
using namespace std;
const int N=2e5;
int n,cl[N+2],ans;
bool vis[N+2];vector<int>vv[N+2];
void vvv()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)vv[j].push_back(i);
  }
}
void ck(vector<int>a)
{
  ans=n;
  for(int i=1;i<=n;i++)vis[i]=0;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    int x=i;vector<int>tmp;
    while(!vis[x])
    {
      tmp.push_back(x);
      vis[x]=1;x=a[x];
    }
    int ln=tmp.size();
    //for(auto z:tmp)cout<<z<<" ";cout<<endl;
    for(auto d:vv[ln])
    {
      for(int in=0;in<d;in++)
      {
        int f=0;
        for(int j=in;j<tmp.size();j+=d)
        {
          int nx=(j+d)%ln;
          if(cl[tmp[j]]!=cl[tmp[nx]])f=1;
        }
        if(!f)ans=min(ans,d);
      }
    }
  }
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vvv();int t;cin>>t;
  while(t--)
  {
    cin>>n;vector<int>a(n+2);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>cl[i];
    ck(a);
  }
  return 0;
}