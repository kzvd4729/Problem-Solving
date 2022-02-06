/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2020 16:05                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 93 ms                                           memory_used: 31300 KB                             
*  problem: https://codeforces.com/contest/799/problem/C
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
const int N=1e6,inf=1e9+2;
pair<int,int>a[N+2],b[N+2],aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,c,d;cin>>n>>c>>d;
   int p=0,q=0;
  for(int i=1;i<=n;i++)
  {
    int x,y;char c;cin>>x>>y>>c;
    if(c=='C')a[++p]={y,x};
    else b[++q]={y,x};
  }
  sort(a+1,a+p+1);sort(b+1,b+q+1);
  for(int i=1;i<=p;i++)aa[i]=a[i];
  for(int i=1;i<=q;i++)bb[i]=b[i];
  for(int i=1;i<=p;i++)a[i].second=max(a[i].second,a[i-1].second);
  for(int i=1;i<=q;i++)b[i].second=max(b[i].second,b[i-1].second);
    int ans=0;
  for(int i=2;i<=p;i++)
  {
    int rm=c-a[i].first;
    int id=upper_bound(a+1,a+p+1,make_pair(rm,inf))-a;
    id--;if(id>=i)id=i-1;
    if(id>0)ans=max(ans,aa[i].second+a[id].second);
  }
  for(int i=2;i<=q;i++)
  {
    int rm=d-b[i].first;
    int id=upper_bound(b+1,b+q+1,make_pair(rm,inf))-b;
    id--;if(id>=i)id=i-1;
    if(id>0)ans=max(ans,bb[i].second+b[id].second);
  }
  int ad1=-1,ad2=-1;
  for(int i=1;i<=p;i++)if(a[i].first<=c)ad1=a[i].second;
  for(int i=1;i<=q;i++)if(b[i].first<=d)ad2=b[i].second;
  if(ad1!=-1&&ad2!=-1)ans=max(ans,ad1+ad2);
  cout<<ans<<endl;
  return 0;
}