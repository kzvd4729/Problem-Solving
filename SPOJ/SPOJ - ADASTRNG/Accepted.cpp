/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-20 13:07:53                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1220                                       memory_used (MB): 17.4                            
*  problem: https://vjudge.net/problem/SPOJ-ADASTRNG
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
const int N=1e6,inf=1e9;
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
long cnt[26+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  sa.init(s);sa.buildSA();sa.computeLCP();

  //sa.print();

  for(int i=1;i<=s.size();i++)
  {
    int ad=s.size()-sa.SA[i]-sa.lcp[i];
    cnt[s[sa.SA[i]]-'a']+=ad;
  }
  cout<<cnt[0];
  for(int i=1;i<26;i++)cout<<" "<<cnt[i];
    cout<<endl;
  return 0;
}