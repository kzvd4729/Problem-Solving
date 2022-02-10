/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-21 12:33:17                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-4416
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
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=3e5,inf=1e9;
char s[N+2];
struct suffixArray
{
  char t[N+12];int idx[N+12];//N is atleast 300
  int n,c[N+12],RA[N+12],SA[N+12],tRA[N+12],tSA[N+12];
  void init(int sz)
  {
    n=sz;
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
    for(int i=0;i<n;i++)printf("%2d\t%2d\t%2d\t%s\n",i,SA[i],lcp[i],t+SA[i]);
  }
}sa;
int seg[N*4+8];
void build(int node,int lo,int hi)
{
  if(lo==hi){seg[node]=sa.lcp[lo];return;}
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
int get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return inf;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return min(get(node*2,lo,md,lt,rt),get(node*2+1,md+1,hi,lt,rt));
}
char tmp[N+2];int fr,dl[N+2],sl[N+2],dr[N+2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int q;scanf("%d",&q);
    scanf("%s",s);int n=strlen(s);fr=n;s[n++]='$';
    for(int i=1;i<=q;i++)
    {
      scanf("%s",tmp);
      for(int j=0;tmp[j];j++)s[n++]=tmp[j];
      if(i<q)s[n++]='#';
    }
    sa.init(n);sa.buildSA();sa.computeLCP();sa.lcp[n+1]=0;build(1,1,n+1);

    //cout<<s<<endl;sa.print();

    for(int i=1;i<=n;i++)
    {
      if(sa.SA[i]<fr)sl[i]=i,dl[i]=dl[i-1];
      else sl[i]=sl[i-1],dl[i]=i;
    }
    dr[n+1]=n+1;
    for(int i=n;i>=1;i--)
    {
      if(sa.SA[i]<fr)dr[i]=dr[i+1];
      else dr[i]=i; 
    }
    long ans=0;
    for(int i=1;i<=n;i++)
    {
      if(sa.SA[i]>=fr)continue;
      int mx=max(get(1,1,n+1,dl[i-1]+1,i),get(1,1,n+1,i,dr[i+1]));
      mx=max(mx,get(1,1,n+1,sl[i-1]+1,i));
      ans+=fr-sa.SA[i]-mx;
    }
    printf("Case %d: %lld\n",++tc,ans);
  }
  return 0;
}