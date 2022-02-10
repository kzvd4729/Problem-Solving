/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-03 02:02:17                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 3188                                       memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-challenging-palindromes
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#define long long long 
using namespace std;
const int N=4e5+12;
//od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manacher(string s)
{
  int n=s.size();
  od.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?1:min(od[l+r-i],r-i+1);
    while(0<=i-k&&i+k<n&&s[i-k]==s[i+k])k++;
    od[i]=k--;
    if(i+k>r)l=i-k,r=i+k;
  }
  ev.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?0:min(ev[l+r-i+1],r-i+1);
    while(0<=i-k-1&&i+k<n&&s[i-k-1]==s[i+k])k++;
    ev[i]=k--;
    if(i+k>r)l=i-k-1,r=i+k;
  }
  for(int i=0;i<n;i++)od[i]=od[i]*2-1;
  ev.erase(ev.begin());
  for(int i=0;i<n-1;i++)ev[i]=ev[i]*2;
}
int ed[N+2];
void process(int n)
{
  for(int i=0;i<n;i++)ed[i+od[i]/2]=max(ed[i+od[i]/2],od[i]);
  for(int i=0;i<n-1;i++)ed[i+ev[i]/2]=max(ed[i+ev[i]/2],ev[i]);

  for(int i=n-1;i>=0;i--)ed[i]=max(ed[i],ed[i+1]-2);

  //for(int i=0;i<n;i++)cout<<ed[i];cout<<endl;
}
struct suffixArray
{
  char t[N+12];int idx[N+12];//N is atleast 300
  int n,c[N+12],RA[N+12],SA[N+12],tRA[N+12],tSA[N+12];
  void init(string s)
  {
    n=s.size();
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
int mt[N+2];
void clear()
{
  memset(mt,0,sizeof mt);memset(ed,0,sizeof ed);
  od.clear(),ev.clear();
}
string cal(string a,string b)
{
  int n1=a.size(),n2=b.size();

  manacher(b);process(b.size());
  sa.init(a+"#"+b);sa.buildSA();sa.computeLCP();

  //sa.print();
  int mn=0;
  for(int i=1;i<=n1+n2+1;i++)
  {
    if(sa.SA[i]<=n1)mn=sa.lcp[i+1];
    else
    {
      mn=min(mn,sa.lcp[i]);
      mt[sa.SA[i]-(n1+1)]=max(mt[sa.SA[i]-(n1+1)],mn);
    }
  }
  for(int i=n1+n2+1;i>=1;i--)
  {
    if(sa.SA[i]<=n1)mn=sa.lcp[i];
    else
    {
      mt[sa.SA[i]-(n1+1)]=max(mt[sa.SA[i]-(n1+1)],mn);
      mn=min(mn,sa.lcp[i]);
    }
  }
  for(int i=0;i<n2;i++)mt[i]=min(mt[i],n2-i);

  int ln=0;
  for(int i=0;i<n2;i++)
  {
    int pl=0;if(i)pl=ed[i-1];
    if(pl+mt[i]+mt[i]>ln&&mt[i])
      ln=pl+mt[i]+mt[i];
  }
  string ans;for(int i=1;i<=ln;i++)ans.push_back('z');
  for(int i=0;i<n2;i++)
  {
    int pl=0;if(i)pl=ed[i-1];
    if(pl+mt[i]+mt[i]==ln&&mt[i])
    {
      string now;
      for(int j=0;j<mt[i];j++)now.push_back(b[i+j]);
      reverse(now.begin(),now.end());
      for(int j=1;j<=pl;j++)now.push_back(b[i-j]);
      for(int j=0;j<mt[i];j++)now.push_back(b[i+j]);
      ans=min(ans,now);
    }
  }
  clear();return ans;
}
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("opt.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string a,b;cin>>a>>b;//assert((int)a.size()==(int)b.size());
    string tmp=a;reverse(tmp.begin(),tmp.end());
    string on=cal(tmp,b),tw=cal(b,tmp);

    a=on,b=tw;
    string ans;if(a.size()>b.size())ans=a;
    else if(b.size()>a.size())ans=b;
    else ans=min(a,b);

    if(ans.size()==0)cout<<-1<<'\n';
    else cout<<ans<<'\n';
  }
  return 0;
}