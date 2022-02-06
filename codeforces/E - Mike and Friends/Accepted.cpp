/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/11/2020 14:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1777 ms                                         memory_used: 202400 KB                            
*  problem: https://codeforces.com/contest/547/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
struct suffixArray
{
  static const int A=5e5+10;//atleast 300+10;
  char t[A+2];int idx[A+2],sp[A+2][20+2];
  int n,c[A+2],RA[A+2],SA[A+2],tRA[A+2],tSA[A+2];
  void init(string s)
  {
    n=s.size();
    for(int i=0;i<n;i++)t[i]=s[i];
    t[n++]='#';
  }
  void countingSort(int k)
  {
    memset(c,0,sizeof c);
    for(int i=0;i<n;i++)c[i+k<n?RA[i+k]:0]++;
    for(int i=0,sm=0;i<max(300,n);i++)
    {
      int d=c[i];c[i]=sm;sm+=d;
    }
    for(int i=0;i<n;i++)tSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
    for(int i=0;i<n;i++)SA[i]=tSA[i];
  }
  vector<int>buildSA()
  {
    for(int i=0;i<n;i++)RA[i]=t[i];
    for(int i=0;i<n;i++)SA[i]=i;
    for(int k=1,r;k<n;k<<=1)
    {
      countingSort(k);countingSort(0);tRA[SA[0]]=r=0;
      for(int i=1;i<n;i++)  
        tRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]]&&RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
      for(int i=0;i<n;i++)RA[i]=tRA[i];
      if(RA[SA[n-1]]==n-1)break;
    }
    vector<int>v;
    for(int i=1;i<n;i++)v.push_back(SA[i]);
    return v;
    for(int i=0;i<n;i++)
      cout<<SA[i]<<" ";
    cout<<endl;
  }
};
const int mod=1000001011,b=193;
int pw[N+2];
void cal(int n)
{
  pw[0]=1;
  for(int i=1;i<=n;i++)pw[i]=(1LL*pw[i-1]*b)%mod;
}
int h[N+2];string s;//global string
void makeHash()
{
  int hs=0,i=0;
  for(auto x:s){hs=(1LL*hs*b+x)%mod;h[i++]=hs;}
}
inline int get(int i,int j)
{
  int x=h[j];if(!i)return x;x=x-(1LL*h[i-1]*pw[j-i+1])%mod;
  if(x<0)x+=mod;return x;
}
int sz;
vector<int>suffixSort()
{
  sz=s.size();cal(sz);makeHash();
  vector<int>v;
  suffixArray sa;sa.init(s);
  v=sa.buildSA();return v;
  for(int i=0;i<sz;i++)v.push_back(i);
  sort(v.begin(),v.end(),[&](int a,int b){
    int mx=sz-max(a,b);int lo=0,hi=mx,md;
    while(lo<=hi)
    {
      int md=(lo+hi)/2;if(get(a,a+md)==get(b,b+md))lo=md+1;
      else hi=md-1;
    }
    if(a+lo==sz)return true;if(b+lo==sz)return false;
    return s[a+lo]<s[b+lo];
  });
  return v;
}
string a[N+2];int bg[N+2];
struct persistent
{
  int l,r,sm;
}seg[N*20+2];
int rot[N+2],nw;
void upd(int node,int pnode,int lo,int hi,int id)
{
  if(lo==hi){seg[node].sm=seg[pnode].sm+1;return ;}
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++nw;upd(seg[node].l,seg[pnode].l,lo,md,id);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++nw;upd(seg[node].r,seg[pnode].r,md+1,hi,id);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int get(int node,int pnode,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sm-seg[pnode].sm;
  int md=(lo+hi)/2;
  return get(seg[node].l,seg[pnode].l,lo,md,lt,rt)+get(seg[node].r,seg[pnode].r,md+1,hi,lt,rt);
}
int po[N+2],d;
inline bool ck(int i,int j,int k)
{
  if(i+k>d||j+k>d)return false;
  return get(i,i+k-1)==get(j,j+k-1);
}
int lt[N+2],rt[N+2];
int readInt () {
  int result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  result = ch-'0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result*10 + (ch - '0');
  }
  return result;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];bg[i]=s.size();
    for(auto x:a[i])s.push_back(x);
    s.push_back('#');
  }
  vector<int>v=suffixSort();
  for(int i=0;i<v.size();i++)po[v[i]]=i;
  //cout<<s<<endl;int c=0;
  //for(auto x:v)cout<<c++<<" "<<s.substr(x,s.size()-x)<<endl;
  //for(int i=1;i<=n;i++)cout<<bg[i]<<" ";cout<<endl;
  for(int i=1;i<v.size();i++)
  {
    rot[i]=++nw;
    upd(rot[i],rot[i-1],0,v.size()-1,v[i]);
  }
  d=s.size();
  for(int k=1;k<=n;k++)
  {
    int id=po[bg[k]];
    int lo=0,hi=id,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(ck(v[id],v[md],a[k].size()))hi=md;else lo=md;
    }
    for(md=lo;md<=hi;md++)if(ck(v[id],v[md],a[k].size()))break;
     lt[k]=md;
    lo=id,hi=v.size()-1,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(ck(v[id],v[md],a[k].size()))lo=md;else hi=md;
    }
    for(md=hi;md>=lo;md--)if(ck(v[id],v[md],a[k].size()))break;
    rt[k]=md;
  }
  while(m--)
  {
    int l,r,k;//cin>>l>>r>>k;//cout<<l<<" "<<r<<" "<<k<<endl;
    l=readInt(),r=readInt(),k=readInt();
    printf("%d ",get(rot[rt[k]],rot[lt[k]-1],0,v.size()-1,bg[l],bg[r]+a[r].size()-1));
  }
  //cout<<endl;
  return 0;
}