/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2020 22:48                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 514 ms                                          memory_used: 55700 KB                             
*  problem: https://codeforces.com/contest/1175/problem/F
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=3e5;
int a[N+2],fr[N+2],bc[N+2];
vector<int>v[N+2];
int sp[N+2][20+2];
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=a[i];//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))<=n)
        sp[i][j]=max(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return max(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
set<pair<int,int> >ans;
void solve(int l,int r,int m)
{
  int sz=r-l+1;set<int>st;
  for(int i=1;i<=sz+1;i++)st.insert(i);
   ans.insert({m,m});int mx=0;
  for(int i=m-1;i>=l;i--)
  {
    if(a[i]>sz)break;
    if(st.find(a[i])==st.end())break;
    st.erase(a[i]);mx=max(mx,a[i]);
    if(fr[i]<mx)continue;
     if(mx==(m-i+1)){ans.insert({i,m});continue;}
    auto it=st.lower_bound(mx);it--;
    if(get(m+1,i+mx-1)==*it)ans.insert({i,i+mx-1});
  }
   sz=r-l+1;st.clear();
  for(int i=1;i<=sz+1;i++)st.insert(i);
   ans.insert({m,m});mx=0;
  for(int i=m+1;i<=r;i++)
  {
    if(a[i]>sz)break;
    if(st.find(a[i])==st.end())break;
    st.erase(a[i]);mx=max(mx,a[i]);
    if(bc[i]<mx)continue;
     if(mx==(i-m+1)){ans.insert({m,i});continue;}
    auto it=st.lower_bound(mx);it--;
    if(get(i-mx+1,m-1)==*it)ans.insert({i-mx+1,i});
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],v[a[i]].push_back(i);
   fr[n]=n;
  for(int i=n-1;i>=1;i--)
  {
    fr[i]=fr[i+1];int x=a[i];
    int id=upper_bound(v[x].begin(),v[x].end(),i)-v[x].begin();
    if(id<v[x].size())fr[i]=min(fr[i],v[x][id]-1);
  }
  bc[1]=1;
  for(int i=2;i<=n;i++)
  {
    bc[i]=bc[i-1];int x=a[i];
    int id=lower_bound(v[x].begin(),v[x].end(),i)-v[x].begin();
    id--;
    if(id>=0)bc[i]=max(bc[i],v[x][id]+1);
  }
  //for(int i=1;i<=n;i++)cout<<bc[i]<<" ";cout<<endl;
   build(n);
  for(int i=1;i<=n;i++)fr[i]=fr[i]-i+1,bc[i]=i-bc[i]+1;
   int l=0;v[1].push_back(n+1);
  for(int i=0;i<v[1].size()-1;i++)
  {
    solve(l+1,v[1][i+1]-1,v[1][i]);
    l=v[1][i];
  }
  //for(auto x:ans)cout<<x.first<<" "<<x.second<<endl;
  cout<<ans.size()<<endl;
  return 0;
}