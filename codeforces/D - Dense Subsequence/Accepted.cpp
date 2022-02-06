/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2019 19:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/724/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int vis[N+2],n,k;
vector<int>v[N+2];
int makeVisit(int r)
{
  int c;
  for(c=0;c<r;c++)
  {
    for(int i=1;i<=n-k+1;i++)
    {
      if(vis[i])continue;
      int id=lower_bound(v[c].begin(),v[c].end(),i)-v[c].begin();
      if(id<v[c].size()&&v[c][id]<=i+k-1)vis[i]=1;
    }
    int f=0;
    for(int i=1;i<=n-k+1;i++)
      if(!vis[i])f=1;
    if(!f)break;
  }
  return c;
}
string s;
int cal(int c)
{
  int ret=0;//cout<<s<<" *** "<<c<<endl;
  for(int i=n;i>=n-k+2;i--)vis[i]=1;
//  for(int i=1;i<=n;i++)
//    cout<<vis[i];
//  cout<<endl;
  for(int i=n;i>=1;i--)
  {
    if(s[i-1]-'a'==c)
    {
      int f=0;
      for(int j=i;j>=max(i-k+1,1);j--)
      {
        if(j<i&&s[j-1]-'a'==c)break;
        if(!vis[j]){f=1;break;}
      }
      ret+=f;
      if(f)
      {
        for(int j=i;j>=max(i-k+1,1);j--)
          vis[j]=1;
      }
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>k;string ans;cin>>s;n=s.size();
   for(int i=0;i<s.size();i++)
    v[s[i]-'a'].push_back(i+1);
  int c=makeVisit(26);
  memset(vis,0,sizeof(vis));
   if(c)
  {
    makeVisit(c);
    for(int i=0;i<c;i++)
    {
      for(int j=0;j<v[i].size();j++)
        ans.push_back((char)(i+'a'));
    }
  }
   int cnt=cal(c);
  while(cnt--)
    ans.push_back((char)(c+'a'));
   cout<<ans<<endl;
   return 0;
}