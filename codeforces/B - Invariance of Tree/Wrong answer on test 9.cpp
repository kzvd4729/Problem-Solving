/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 14:55                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/576/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,p[N+2],par[N+2];
vector<pair<int,int> >ed;
map<pair<int,int>,int>mp;
int union_find(int x)
{
  if(x==par[x])return x;
  return par[x]=union_find(par[x]);
}
void case1(void)
{
  int rt=-1;
  for(int i=1;i<=n;i++)
    if(p[i]==i)rt=i;
  if(rt==-1)return ;
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
  {
    if(i==rt)continue;
    cout<<rt<<" "<<i<<endl;
  }
  exit(0);
}
void case2(void)
{
  int rt=-1;
  for(int i=1;i<=n;i++)
    if(i==p[p[i]])rt=i;
  if(rt==-1)return ;
  for(int i=1;i<=n;i++)par[i]=i;
  ed.push_back({rt,p[rt]});
  mp[{rt,p[rt]}]=1;mp[{p[rt],rt}];par[rt]=par[p[rt]];
  for(int i=1;i<=n;i++)
  {
    int tr=rt,j=i;
    while(true)
    {
      if(mp[{tr,j}]||tr==j)break;
      mp[{tr,j}]=mp[{j,tr}]=1;
      int r1=union_find(tr);
      int r2=union_find(j);
      //cout<<tr<<" "<<j<<endl;
      if(r1==r2)return ;
      ed.push_back({tr,j});
      par[r1]=r2;
      tr=p[tr],j=p[j];
    }
    if(ed.size()==n-1)break;
  }
  cout<<"YES"<<endl;
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<endl;
  exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>p[i];
  case1();case2();
  cout<<"NO"<<endl;
  return 0;
}