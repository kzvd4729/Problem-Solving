/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/18/2020 21:36                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 27500 KB                             
*  problem: https://codeforces.com/contest/891/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int pt[N+2],par[N+2],sz[N+2];
vector<int>qr[N+2],cs[N+2];
vector<vector<int> >ed[N+2],rm;
int find(int x)
{
  if(x==par[x])return x;
  return find(par[x]);
}
int chn1[N+2],chn2[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;rm.resize(m+2);
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ed[w].push_back({u,v});rm[i]={w,u,v};
  }
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int k;cin>>k;set<int>st;
    while(k--)
    {
      int id;cin>>id;qr[i].push_back(id);
      st.insert(rm[id][0]);
    }
    sort(qr[i].begin(),qr[i].end(),[](int a,int b){
      return rm[a][0]<rm[b][0];
    });
    for(auto x:st)cs[x].push_back(i);
  }
  for(int i=1;i<=n;i++)par[i]=i,sz[i]=1;
  for(int i=1;i<=6;i++)
  {
    //for(int i=1;i<=n;i++)cout<<par[i]<<" ";cout<<endl;
    for(auto q:cs[i])
    {
      //for(int i=1;i<=n;i++)cout<<par[i]<<" ";cout<<endl;
      if(pt[q]==-1)continue;set<int>st1,st2;
      while(pt[q]<qr[q].size()&&rm[qr[q][pt[q]]][0]==i)
      {
        //cout<<rm[qr[q][pt[q]]][1]<<" ** "<<rm[qr[q][pt[q]]][2]<<endl;
        int r1=find(rm[qr[q][pt[q]]][1]),r2=find(rm[qr[q][pt[q]]][2]);
        if(r1==r2){pt[q]=-1;break;}
        pt[q]++;
        if(sz[r1]<sz[r2])swap(r1,r2);
        if(st1.find(r2)==st1.end())st1.insert(r2),chn1[r2]=par[r2];
        if(st2.find(r1)==st2.end())st2.insert(r1),chn2[r1]=sz[r1];
        par[r2]=r1;sz[r1]+=sz[r2];
      }
      for(auto x:st1)par[x]=chn1[x];
      for(auto x:st2)sz[x]=chn2[x];
    }
    //for(int i=1;i<=n;i++)cout<<par[i]<<" ";cout<<endl;
    for(auto x:ed[i])
    {
      int r1=find(x[0]),r2=find(x[1]);
      if(r1==r2)continue;
      if(sz[r1]<sz[r2])swap(r1,r2);
      par[r2]=r1;sz[r1]+=sz[r2];
    }
  }
  //for(int i=1;i<=q;i++)cout<<pt[i]<<" ";cout<<endl;
  for(int i=1;i<=q;i++)
    pt[i]==-1?cout<<"NO\n":cout<<"YES\n";
  return 0;
}