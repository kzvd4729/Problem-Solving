/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/01/2020 15:15                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 873 ms                                          memory_used: 53100 KB                             
*  problem: https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/C
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
const int N=4e5;
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();
   sa.init(s);sa.buildSA();sa.computeLCP();
  build(n);//sa.print();
     //for(int i=0;i<=n;i++)cout<<sa.idx[i]<<" ";cout<<endl;
   int t;cin>>t;vector<pair<int,int> >v(t);
  for(int i=0;i<t;i++)cin>>v[i].first>>v[i].second,v[i].first--,v[i].second--;
   // pair<int,int>a={4,6},b={2,3};int p1=sa.idx[a.first],p2=sa.idx[b.first];int rt=0;
  // if(p1>p2)swap(p1,p2);int l=get(p1+1,p2);cout<<"&&"<<l<<endl;
  // if(l>=min(a.second-a.first+1,b.second-b.first+1))rt=a<b,cout<<"rere"<<endl;
  // else rt=s[a.first+l]<s[b.first+l];cout<<rt<<endl;
   sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b){
    int p1=sa.idx[a.first],p2=sa.idx[b.first];
    if(p1>p2)swap(p1,p2);int l=get(p1+1,p2);
     int rt=0;
     //cout<<a.first<<" "<<b.first<<" ";
    if(l>=a.second-a.first+1&&l>=b.second-b.first+1)
    {
      if(a.second-a.first==b.second-b.first)rt=a<b;
      else rt=a.second-a.first<b.second-b.first;
    }
    else if(l>=a.second-a.first+1)rt=true;
    else if(l>=b.second-b.first+1)rt=false;
    else rt=s[a.first+l]<s[b.first+l];
    //cout<<s.substr(a.first,a.second-a.first+1)<<" "<<s.substr(b.first,b.second-b.first+1)<<" "<<rt<<endl;
    return rt;
  });
   for(int i=0;i<t;i++)cout<<v[i].first+1<<" "<<v[i].second+1<<"\n";
    return 0;
}