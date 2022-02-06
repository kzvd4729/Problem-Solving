/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/15/2020 21:34                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 79100 KB                             
*  problem: https://codeforces.com/contest/1446/problem/C
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
int sz;
struct trie
{
  int nx[2],ind;
}tr[N*32+2];
void insrt(int x,int id)
{
  int now=0;
  for(int i=30-1;i>=0;i--)
  {
    bool c=(x&(1<<i));
    if(tr[now].nx[c]==0)tr[now].nx[c]=++sz;
    now=tr[now].nx[c];
  }
  tr[now].ind=id;
}
pair<int,int>get(int x)
{
  int now=0,mn=0;
  for(int i=30-1;i>=0;i--)
  {
    bool c=(x&(1<<i));
    if(tr[now].nx[c])now=tr[now].nx[c];
    else now=tr[now].nx[c^1],mn|=(1<<i);
  }
  return {mn,tr[now].ind};
}
int a[N+2],par[N+2];
vector<pair<int,int> >v[N+2];
int find(int x)
{
  if(x==par[x])return x;
  return par[x]=find(par[x]);
}
pair<int,int>ord(int a,int b)
{
  if(a<=b)return {a,b};
  else return {b,a};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    if(i>1)v[i].push_back(get(a[i]));
    insrt(a[i],i);
  }
  for(int i=0;i<N*32+2;i++)
  {
    tr[i].nx[0]=0,tr[i].nx[1]=0;
    tr[i].ind=0;
  }
  sz=0;
  for(int i=n;i>=1;i--)
  {
    if(i<n)v[i].push_back(get(a[i]));
    insrt(a[i],i);
  }
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    if((int)v[i].size()==1)st.insert(ord(i,v[i][0].second));
    else
    {
      if(v[i][0].first<v[i][1].first)st.insert(ord(i,v[i][0].second));
      else st.insert(ord(i,v[i][1].second));
    }
  }
  //cout<<"here"<<endl;
  for(int i=1;i<=n;i++)par[i]=i;
  for(auto x:st)
  {
    //cout<<x.first<<" "<<x.second<<endl;
    int r1=find(x.first),r2=find(x.second);
    assert(r1!=r2);par[r1]=r2;
  }
  set<int>un;
  for(int i=1;i<=n;i++)un.insert(find(i));
  cout<<(int)un.size()-1<<endl;
  return 0;
}