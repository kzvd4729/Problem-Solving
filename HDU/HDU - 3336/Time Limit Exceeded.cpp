/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-20 18:29:40                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-3336
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
const int N=2e5,inf=1e9;

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
    for(int i=0;i<n;i++)printf("%2d\t%2d\t%s\n",SA[i],lcp[i],t+SA[i]);
  }
}sa;
int sp[N+2][20];
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=sa.lcp[i];//array
  for(int j=1;j<=18;j++)
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
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t;scanf("%d",&t);
  while(t--)
  {
    int n;scanf("%d",&n);scanf("%s",s);
    sa.init(n);sa.buildSA();sa.computeLCP();

    //sa.print();
    int id=sa.idx[0];build(n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      int lo=id+1,hi=n+1,md;//hi=n+1;
      while(lo<hi)
      {
        md=(lo+hi)/2;
        if(get(id,md)<i)hi=md;else lo=md+1;
      }
      int dw=lo-1;

      lo=1,hi=id,md;//hi=n+1;
      while(lo<hi)
      {
        md=(lo+hi)/2;
        if(get(md+1,id)>=i)hi=md;else lo=md+1;
      }
      int up=lo;
      ans=(ans+dw-up+1)%10007;
    }
    printf("%d\n",ans);
  }
  return 0;
}