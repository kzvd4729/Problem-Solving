/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-21 19:42:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 202                                        memory_used (MB): 8.1                             
*  problem: https://vjudge.net/problem/HDU-4436
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
    t[n++]='#';t[n]='\0';
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
const int mod=2012;
char tmp[N+2];int ed[N+2],qm[N+2],nm[N+2],pw[N+2],pq[N+2];
int ret(int b,int e)
{
  int ans=qm[e];if(b)ans=(ans-qm[b-1]+mod)%mod;
  int mn=0;if(b)mn=nm[b-1];
  mn=(mn*(pq[e-b+1]-1))%mod;
  mn=(mn+mod)%mod;
  ans=(ans-mn+mod)%mod;
  return ans;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int q;
  while(~scanf("%d",&q))
  {
    int n=0;
    for(int i=1;i<=q;i++)
    {
      scanf("%s",tmp);int b=n;
      for(int j=0;tmp[j];j++)s[n++]=tmp[j];
      for(int j=b;j<n;j++)ed[j]=n;
      if(i<q)s[n++]='#';
    }
    s[n]='\0';
    sa.init(n);sa.buildSA();sa.computeLCP();
    
    //cout<<s<<endl;sa.print();

    nm[0]=s[0]-'0';qm[0]=nm[0];pw[0]=1;pq[0]=1;
    for(int i=1;i<n;i++)
    {
      nm[i]=(nm[i-1]*10+s[i]-'0')%mod;
      qm[i]=(qm[i-1]+nm[i])%mod;
      pw[i]=(pw[i-1]*10)%mod;
      pq[i]=(pq[i-1]+pw[i])%mod;
    }
    int ad=0;
    for(int i=1;i<=n;i++)
    {
      if(s[sa.SA[i]]=='0'||s[sa.SA[i]]=='#')continue;

      int ans=ret(sa.SA[i],ed[sa.SA[i]]-1);
      if(sa.lcp[i])ans=(ans-ret(sa.SA[i],min(sa.SA[i]+sa.lcp[i]-1,ed[sa.SA[i]]-1))+mod)%mod;

      ad=(ad+ans)%mod;
    }
    printf("%d\n",ad);
  }
  return 0;
}