/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-18 00:52:42                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 855                                        memory_used (MB): 4                               
*  problem: https://vjudge.net/problem/LightOJ-1073
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s[15];
int dp[(1<<15)+2][15],n,mt[15][15],vis[20];
int match(string a,string b)
{
  for(int i=0;i<a.size();i++)
  {
    int ln=a.size()-i;
    if(ln>b.size())continue;
    if(a.substr(i,ln)==b.substr(0,ln))return ln;
  }
  return 0;
}
int substring(string a,string b)
{
  if((b+"#"+a).find(a)<b.size())return true;
  return false;
}
int dfs(int msk,int ls)
{
  if(msk==((1<<n)-1))return dp[msk][ls]=0;
  if(dp[msk][ls]!=-1)return dp[msk][ls];
  int now=1e9;
  for(int i=0;i<n;i++)
  {
    if(msk&(1<<i))continue;
    now=min(now,(int)s[i].size()-mt[ls][i]+dfs(msk|(1<<i),i));
  }
  return dp[msk][ls]=now;
}
void make_unique(void)
{
  vector<string>v;
  for(int i=0;i<n;i++)v.push_back(s[i]);
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  n=v.size();
  for(int i=0;i<n;i++)s[i]=v[i];
  memset(vis,0,sizeof(vis));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==j)continue;
      if(substring(s[i],s[j]))
        vis[i]=1;
    }
  }
  v.clear();
  for(int i=0;i<n;i++)
    if(!vis[i])v.push_back(s[i]);
  n=v.size();
  for(int i=0;i<n;i++)s[i]=v[i];
}
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>s[i];
    make_unique();
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i==j)mt[i][j]=0;
        else mt[i][j]=match(s[i],s[j]);
      }
    }
    int mn=1e9,id;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
      int now=(int)s[i].size()+dfs((1<<i),i);
      dp[(1<<i)][i]=now;
      if(now<mn)mn=now,id=i;
    }
    /*cout<<endl;
    for(int i=0;i<n;i++)
      cout<<s[i]<<endl;*/
    vector<int>ans;ans.push_back(id);
    int msk=(1<<id),ls=id;
    while(true)
    {
      if(msk==((1<<n)-1))break;
      int now=1e9;vector<pair<string,int> >v;
      for(int i=0;i<n;i++)
      {
        if(msk&(1<<i))continue;
        if(dp[msk|(1<<i)][i]==-1)continue;
        int here=(int)s[i].size()-mt[ls][i]+dp[msk|(1<<i)][i];
        if(here<now)
        {
          v.clear();
          v.push_back({s[i].substr(mt[ls][i],s[i].size()-mt[ls][i]),i});
          now=here;
        }
        else if(here==now)
        {
          v.push_back({s[i].substr(mt[ls][i],s[i].size()-mt[ls][i]),i});
        }
      }
      sort(v.begin(),v.end());
      id=v[0].second;
      ans.push_back(id);msk|=(1<<id);ls=id;
    }
    string prnt=s[ans[0]];
    for(int i=1;i<ans.size();i++)
    {
      int nw=ans[i],pr=ans[i-1];
      for(int j=mt[pr][nw];j<s[nw].size();j++)
        prnt.push_back(s[nw][j]);
    }
    cout<<"Case "<<++tc<<": "<<prnt<<"\n";
  }
  return 0;
}