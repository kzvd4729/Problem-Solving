/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/11/2020 16:40                        
*  solution_verdict: Runtime error on test 1                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 198100 KB                            
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
#define long long long
using namespace std;
const int N=5e5;
struct suffixArray
{
  char t[N+12];int idx[N+12];//N is atleast 300
  int n,c[N+12],RA[N+12],SA[N+12],tRA[N+12],tSA[N+12];
  void init(string s)
  {
    n=s.size();
    for(int i=0;i<n;i++)t[i]=s[i];
    t[n++]='#';
  }
  void countingSort(int k)
  {
    for(int i=0;i<=n;i++)c[i]=0;
    for(int i=0;i<n;i++)c[i+k<n?RA[i+k]:0]++;
    for(int i=0,sm=0;i<max(300,n);i++)
    {
      int d=c[i];c[i]=sm;sm+=d;
    }
    for(int i=0;i<n;i++)tSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
    for(int i=0;i<n;i++)SA[i]=tSA[i];
  }
  void buildSA()
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
    //suffixes are sorted in index SA[1] to SA[n-1];
    //use SA index 1 to s.size() for outside use;
  }
  int phi[N+12],tmp[N+12],lcp[N+12];
  void computeLCP()
  {
    phi[SA[0]]=-1;
    for(int i=1;i<n;i++)phi[SA[i]]=SA[i-1];
    for(int i=0,l=0;i<n;i++)
    {
      if(phi[i]==-1){tmp[i]=0;continue;}
      while(t[i+l]==t[phi[i]+l])l++;
      tmp[i]=l;l=max(l-1,0);
    }
    for(int i=0;i<n;i++)lcp[i]=tmp[SA[i]];//lcp with previous suffix in sorted order
    for(int i=0;i<n;i++)idx[SA[i]]=i;//order of suffix i in sorted list
  }
  void print()
  {
    for(int i=0;i<n;i++)printf("%2d\t%2d\t%s\n",SA[i],lcp[i],t+SA[i]);
  }
}sa;
int sp[N+2][20+2];
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=sa.lcp[i];//array
   for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))<=n)
        sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  if(lt==rt)return 1e9;if(lt>rt)swap(lt,rt);lt++;
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
string a[N+2];int bg[N+2],lt[N+2],rt[N+2];
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;string s;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];bg[i]=s.size();
    for(auto x:a[i])s.push_back(x);
    s.push_back('#');
  }s.pop_back();//cout<<s<<endl;
  sa.init(s);sa.buildSA();sa.computeLCP();//sa.print();
  build(s.size());//cout<<"**"<<get(6,7)<<endl;
  for(int k=1;k<=n;k++)
  {
    int id=sa.idx[bg[k]];//cout<<"id = "<<id<<endl;
    int lo=0,hi=id,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(get(id,md)>=a[k].size())hi=md;else lo=md;
    }
    for(md=lo;md<=hi;md++)if(get(id,md)>=a[k].size())break;
     lt[k]=md;lo=id,hi=s.size();
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(get(id,md)>=a[k].size())lo=md;else hi=md;
    }
    for(md=hi;md>=lo;md--)if(get(id,md)>=a[k].size())break;
    rt[k]=md;
    //cout<<lt[k]<<" "<<rt[k]<<endl;
  }
  for(int i=1;i<=s.size();i++)
  {
    rot[i]=++nw;
    upd(rot[i],rot[i-1],0,s.size(),sa.SA[i]);
  }
  while(m--)
  {
    int l,r,k;cin>>l>>r>>k;//cout<<l<<" "<<r<<" "<<k<<endl;
    cout<<get(rot[rt[k]],rot[lt[k]-1],0,s.size(),bg[l],bg[r]+a[r].size())<<" ";
  }
  return 0;
}