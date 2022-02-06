/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2018 20:05                        
*  solution_verdict: Time limit exceeded on test 88          language: GNU C++14                               
*  run_time: 5000 ms                                         memory_used: 84700 KB                             
*  problem: https://codeforces.com/contest/1011/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,ty[N+2],one[N+2],two[N+2];
int vl[N+2],x,y,mx,dp[N+2][3],par[N+2];
vector<int>lev[N+2];
string s;
void input(void)
{
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    if(s=="AND")
    {
      cin>>x>>y;
      ty[i]=1;
      one[i]=x;
      two[i]=y;
      par[x]=i;
      par[y]=i;
    }
    else if(s=="OR")
    {
      cin>>x>>y;
      ty[i]=2;
      one[i]=x;
      two[i]=y;
      par[x]=i;
      par[y]=i;
    }
    else if(s=="XOR")
    {
      cin>>x>>y;
      ty[i]=3;
      one[i]=x;
      two[i]=y;
      par[x]=i;
      par[y]=i;
    }
    else if(s=="NOT")
    {
      cin>>x;
      ty[i]=4;
      one[i]=x;
      par[x]=i;
    }
    else
    {
      cin>>x;
      ty[i]=5;
      vl[i]=x;
    }
  }
}
void height(int node,int h)
{
  lev[h].push_back(node);
  if(ty[node]<=4)height(one[node],h+1);
  if(ty[node]<=3)height(two[node],h+1);
}
void calculate(void)
{
  for(int i=n;i>=1;i--)
  {
    for(auto x:lev[i])
    {
      if(ty[x]==1)
        vl[x]=vl[one[x]]&vl[two[x]];
      else if(ty[x]==2)
        vl[x]=vl[one[x]]|vl[two[x]];
      else if(ty[x]==3)
        vl[x]=vl[one[x]]^vl[two[x]];
      else if(ty[x]==4)
        vl[x]=vl[one[x]]^1;
    }
  }
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++)
    dp[i][vl[i]]=vl[1];
//  for(int i=1;i<=n;i++)
//    cout<<vl[i]<<" ";
//  cout<<endl;
}
int query(int node)
{
  int child=node,val=vl[child]^1;
  node=par[child];
  while(true)
  {
    if(ty[node]==1)
    {
      if(one[node]==child)
        val&=vl[two[node]];
      else val&=vl[one[node]];
    }
    else if(ty[node]==2)
    {
      if(one[node]==child)
        val|=vl[two[node]];
      else val|=vl[one[node]];
    }
    else if(ty[node]==3)
    {
      if(one[node]==child)
        val^=vl[two[node]];
      else val^=vl[one[node]];
    }
    else if(ty[node]==4)
      val^=1;
    if(dp[node][val]!=-1)return dp[node][val];
    if(node==1)break;
    child=node;
    node=par[child];
  }
  return val;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  input();
  height(1,1);
  calculate();
   string ans;
  for(int i=1;i<=n;i++)
  {
    if(ty[i]!=5)continue;
    ans.push_back(query(i)+'0');
  }
  cout<<ans<<endl;
  return 0;
}