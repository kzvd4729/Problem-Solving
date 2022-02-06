/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2020 18:12                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1311/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int par[N+2],lv[N+2],ch[N+2];
vector<int>v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,d;cin>>n>>d;v[0].push_back(1);
    for(int i=0;i<=100;i++)v[i].clear();
    for(int i=1;i<=n;i++)lv[i]=0,ch[i]=0;
    int nd=2,dp;v[0].push_back(1);
    for(int i=1; ;i++)
    {
      int nw=(1<<i);
      while(nw--)
      {
        if(nd>n)break;
        v[i].push_back(nd);nd++;
        d-=i;
      }
      if(nd>n)
      {
        dp=i;break;
      }
    }
    if(d<0)
    {
      cout<<"NO\n";continue;
    }
    for(int i=1;i<=dp;i++)
    {
      for(auto c:v[i])
      {
        for(auto p:v[i-1])
        {
          if(ch[p]==2)continue;
          ch[p]++;par[c]=p;break;
        }
      }
    }
    int g=0;
    while(d--)
    {
      int f=0;
      for(int i=1;i<=dp;i++)
      {
        int lf=-1;
        for(int j=0;j<v[i].size();j++)
          if(ch[v[i][j]]==0)lf=j;
        if(lf==-1)continue;
        for(int j=0;j<v[i].size();j++)
        {
          if(j==lf)continue;
          if(ch[v[i][j]]<2)
          {
            f=1;int u=v[i][j];
            v[i].erase(v[i].begin()+lf);
            lf=v[i][lf];
            v[i+1].push_back(lf);
            ch[u]++;par[lf]=u;
            break;
          }
        }
        if(f)break;
      }
      if(!f){g=1;break;}
    }
    if(g)cout<<"NO\n";
    else
    {
      cout<<"YES\n";
      for(int i=2;i<=n;i++)
        cout<<par[i]<<" ";
      cout<<endl;
    }
  }
  return 0;
}