/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-05 13:02:58                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-functional-palindromes
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
#include<random>
#define long long long 
using namespace std;
const int N=2e5;

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
const int inf=1010580540;
int get(int lt,int rt)
{
  if(rt<lt)return inf;
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
void solve(string s,vector<pair<int,int> >&v)
{
  int n=s.size();
 
  sa.init(s);sa.buildSA();sa.computeLCP();
  build(n);//sa.print();
 
  int t=v.size();
  sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b){
    int p1=sa.idx[a.first],p2=sa.idx[b.first];
    if(p1>p2)swap(p1,p2);int l=get(p1+1,p2);
    int rt=0;
    if(l>=a.second-a.first+1&&l>=b.second-b.first+1)
    {
      if(a.second-a.first==b.second-b.first)rt=a<b;
      else rt=a.second-a.first<b.second-b.first;
    }
    else if(l>=a.second-a.first+1)rt=true;
    else if(l>=b.second-b.first+1)rt=false;
    else rt=s[a.first+l]<s[b.first+l];
    return rt;
  });
}
int nw,last,occur[N+2];
struct node
{
  int next[26],len,link;
  int st,ed;
}pal[N+2];
void init()
{
  pal[0].link=0;pal[0].len=-1;//odd length root
  pal[1].link=0;pal[1].len=0;//even length root
  nw=1,last=1;
  //last keeps track of the lps suffix of till inserted string
}
void build(string s)
{
  s="#"+s;
  for(int p=1;p<s.size();p++)
  {
    while(s[p-pal[last].len-1]!=s[p])last=pal[last].link;
    int x=pal[last].link,c=s[p]-'a';
    while(s[p-pal[x].len-1]!=s[p])x=pal[x].link;//finding suffix link
    if(!pal[last].next[c])
    {
      pal[last].next[c]=++nw;pal[nw].len=pal[last].len+2;
      pal[nw].ed=p-1;pal[nw].st=p-pal[nw].len;

      if(pal[nw].len==1)pal[nw].link=1;
      else pal[nw].link=pal[x].next[c];
    }
    last=pal[last].next[c];occur[last]++;
  }
}
void occurrences(void)
{
  for(int i=nw;i>=2;i--)occur[pal[i].link]+=occur[i];
}
const int mod=1e9+7;
const int b=100001;
int pw[N+2];
void cal(int n)
{
  pw[0]=1;
  for(int i=1;i<=n;i++)
    pw[i]=(1LL*pw[i-1]*b)%mod;
}
struct hsh
{
  string s;vector<int>v;
  int makeHash(void)
  {
    int hs=0;
    for(auto x:s)
    {
      hs=(1LL*hs*b+x)%mod;
      v.push_back(hs);
    }
    return hs;
  }
  int segment(int lt,int rt)
  {
    int x=v[rt];
    if(!lt)return x;
    x=x-(1LL*v[lt-1]*pw[rt-lt+1])%mod;
    if(x<0)x+=mod;
    return x;
  }
}hs;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;string s;cin>>s;

  init();build(s);occurrences();map<pair<int,int>,int>mp;
  vector<pair<int,int> >v;
  for(int i=2;i<=nw;i++)
  {
    v.push_back({pal[i].st,pal[i].ed});
    mp[{pal[i].st,pal[i].ed}]=occur[i];
  }
  solve(s,v);vector<int>dm;
  for(auto x:v)dm.push_back(mp[x]);

  for(int i=1;i<dm.size();i++)dm[i]+=dm[i-1];

  cal(N);hs.s=s;hs.makeHash();
  while(q--)
  {
    int k;cin>>k;
    int id=lower_bound(dm.begin(),dm.end(),k)-dm.begin();
    if(id==dm.size()){cout<<-1<<'\n';continue;}
    cout<<hs.segment(v[id].first,v[id].second)<<'\n';
    //cout<<v[id].first<<" "<<v[id].second<<endl;
  }
  return 0;
}