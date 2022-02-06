/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2019 19:06                        
*  solution_verdict: Time limit exceeded on test 11          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 16700 KB                             
*  problem: https://codeforces.com/gym/100551/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
 const int N=3e5,sq=1000;
int par[N+2],par2[N+2],com,qr[N+2];
map<pair<int,int>,int>mp;
vector<vector<int> >ed,tmp,onl;
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int get2(int x)
{
  if(x==par2[x])return x;
  return par2[x]=get2(par2[x]);
}
void add(int u,int v)
{
  int p1=get(u),p2=get(v);
  if(p1!=p2)par[p1]=p2,com--;
}
void add2(int u,int v)
{
  int p1=get2(u),p2=get2(v);
  if(p1!=p2)par2[p1]=p2,com--;
}
int main()
{
  freopen("connect.in","r",stdin);
  freopen("connect.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=0;i<q;i++)
  {
    string s;cin>>s;
    int u,v;if(s!="?")cin>>u>>v;
    if(u>v)swap(u,v);
    if(s=="+")
    {
      ed.push_back({u,v,i,q});
      mp[{u,v}]=ed.size();
    }
    else if(s=="-")
    {
      int id=mp[{u,v}]-1;ed[id][3]=i;
    }
    else qr[i]=1;
  }
  for(int i=1;i<=n;i++)par2[i]=i;
  for(int bl=0; ;bl++)
  {
    int l=bl*sq,r=min((bl+1)*sq,q)-1;if(l>r)break;
    for(int i=1;i<=n;i++)par[i]=i;
     tmp.clear();com=n;
    for(auto &x:ed)
    {
      if(x[2]<l&&x[3]>r)add(x[0],x[1]);
      if((x[2]>=l&&x[2]<=r)||(x[3]>=l&&x[3]<=r))tmp.push_back(x);
    }
    if(tmp.size()>sq+sq)assert(0);
    for(int i=l;i<=r;i++)
    {
      int remm=com;if(!qr[i])continue;
      onl.clear();
      for(auto &x:tmp)
      {
        if(x[2]<i&&x[3]>i)
        {
          onl.push_back(x);
          par2[x[0]]=get(x[0]),par2[x[1]]=get(x[1]);
        }
      }
      for(auto &x:onl)add2(x[0],x[1]);
      cout<<com<<"\n";com=remm;
      for(auto &x:onl)par2[x[0]]=x[0],par2[x[1]]=x[1];
    }
  }
  return 0;
}