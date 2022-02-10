/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-21 13:56:20                      
*  solution_verdict: Wrong Answer                            language: C++                                     
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
  char t[N+12];//N is atleast 300
  int n,c[N+12],RA[N+12],SA[N+12],tRA[N+12],tSA[N+12];
  void init(int sz)
  {
    n=sz;
    for(int i=0;i<n;i++)t[i]=s[i];
    t[n++]='#';//t[n]='\0';
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
  int lcp[N+12];
  void computeLCP()
  {
    tRA[SA[0]]=-1;
    for(int i=1;i<n;i++)tRA[SA[i]]=SA[i-1];
    for(int i=0,l=0;i<n;i++)
    {
      if(tRA[i]==-1){tSA[i]=0;continue;}
      while(t[i+l]==t[tRA[i]+l])l++;
      tSA[i]=l;l=max(l-1,0);
    }
    for(int i=0;i<n;i++)lcp[i]=tSA[SA[i]];//lcp with previous suffix in sorted order
  }
  void print()
  {
    for(int i=0;i<n;i++)printf("%2d\t%2d\t%s\n",SA[i],lcp[i],t+SA[i]);
  }
}sa;
char tmp[N+2];int fr,mx[N+2];
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("opt.txt","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int q;scanf("%d",&q);
    scanf("%s",tmp);int n=strlen(tmp);fr=n;
    for(int i=0;i<n;i++)s[i]=tmp[i];s[n++]='#';
    for(int i=1;i<=q;i++)
    {
      scanf("%s",tmp);
      for(int j=0;tmp[j];j++)s[n++]=tmp[j];
      if(i<q)s[n++]='#';
    }
    s[n]='\0';
    sa.init(n);sa.buildSA();sa.computeLCP();sa.lcp[n+1]=0;
    
    for(int i=1;i<=n+1;i++)mx[i]=0;
    int mn=0;
    for(int i=1;i<=n;i++)
    {
      mn=min(mn,sa.lcp[i]);
      if(sa.SA[i]<fr)
      {
        mx[i]=max(mx[i],mn);
        mn=sa.lcp[i+1];
      }
    }
    mn=0;
    for(int i=1;i<=n;i++)
    {
      mn=min(mn,sa.lcp[i]);
      if(sa.SA[i]<fr)mx[i]=max(mx[i],mn);
      else mn=sa.lcp[i+1];
    }
    mn=0;
    for(int i=n;i>=1;i--)
    {
      if(sa.SA[i]<fr)mx[i]=max(mx[i],mn);
      mn=min(mn,sa.lcp[i]);
      if(sa.SA[i]>=fr)mn=sa.lcp[i];
    }
    long ans=0;
    for(int i=1;i<=n;i++)
    {
      if(sa.SA[i]>=fr)continue;
      ans+=max(0,(fr-sa.SA[i]-mx[i]));
    }
    printf("Case %d: %lld\n",++tc,ans);
  }
  return 0;
}