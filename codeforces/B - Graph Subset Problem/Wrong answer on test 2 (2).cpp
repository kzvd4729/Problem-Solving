/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2020 21:29                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 100100 KB                            
*  problem: https://codeforces.com/contest/1439/problem/B
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
const int N=2e5,mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int d[N+2],tr[N+2];
vector<int>ad[N+2];set<int>da[N+2];
 const int sz=1e7;//more size better
long key[sz+2]; bool val[sz+2];//can be any data type
static inline int h(long x){return((x^179)*7LL)%sz;}
int id=0,bf[N+2];
void init()
{
  memset(key,-1,sizeof key);//-1 is invalid
}
void add(long x,int y)//assign
{
  int k=h(x);
  while(key[k]!=-1&&key[k]!=x)k=(k+1)%sz;//first non-taken index
  key[k]=x,val[k]=y;
  bf[++id]=k;
}
int get(long x)
{
  for(int k=h(x);key[k]!=-1;k=(k+1)%sz)
    if(key[k]==x)return val[k];
  return -1;
}
void clear()
{
  for(int i=1;i<=id;i++)key[bf[i]]=-1;
  id=0;
}
void add2(int x,int y)
{
  if(x>y)swap(x,y);
  add((long)x^(((long)y)<<32),1);
}
bool get2(int x,int y)
{
  if(x>y)swap(x,y);
  return get((long)x^(((long)y)<<32));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   init();int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;clear();
    for(int i=1;i<=n;i++)d[i]=0,ad[i].clear();
    for(int i=1;i<=m;i++)
    {
      int a,b;cin>>a>>b;d[a]++,d[b]++;add2(a,b);
      ad[a].push_back(b);ad[b].push_back(a);
    }
    set<pair<int,int> >st;
    for(int i=1;i<=n;i++)st.insert({d[i],i});
     while((int)st.size())
    {
      pair<int,int>p=*st.begin();
      if(p.first>=k)break;
       st.erase(p);
      for(auto x:ad[p.second])
      {
        if(st.find({d[x],x})==st.end())continue;
         st.erase({d[x],x});d[x]--;
        st.insert({d[x],x});
      }
    }
    if((int)st.size())
    {
      cout<<1<<" "<<(int)st.size()<<'\n';
      for(auto x:st)cout<<x.second<<" ";
        cout<<'\n';
      continue;
    }
    for(int i=1;i<=n;i++)
    {
      for(auto x:ad[i])da[i].insert(x);
    }
    for(int i=1;i<=n;i++)d[i]=da[i].size();
    st.clear();
     vector<int>ans;
    for(int i=1;i<=n;i++)st.insert({d[i],i});
    while((int)st.size())
    {
      pair<int,int>p=*st.begin();
      if(p.first==k-1)
      {
        //vector<int>tr;//tr.push_back(p.second);
        int id=0;
        for(auto x:da[p.second])tr[++id]=x;
         //shuffle(tr.begin(),tr.end(),rng);
        int f=1;
        for(int i=1;i<=id;i++)
        {
          for(int j=i+1;j<=id;j++)
          {
            if(get2(tr[i],tr[j])==0){f=0;break;}
            //if(da[tr[i]].count(tr[j])==0){f=0;break;}
          }
        }
        if(f==1)
        {
          ans.push_back(p.second);
          for(int i=1;i<=id;i++)ans.push_back(tr[i]);
          break;
        }
      }
       st.erase(p);
      for(auto x:da[p.second])
      {
        if(st.find({d[x],x})==st.end())continue;
         st.erase({d[x],x});d[x]--;
        st.insert({d[x],x});
        da[x].erase(p.second);
      }
    }
    if((int)ans.size()==0)cout<<-1<<'\n';
    else 
    {
      cout<<2<<'\n';
      for(auto x:ans)cout<<x<<" ";
        cout<<'\n';
    }
    for(int i=1;i<=n;i++)da[i].clear();
  }
  return 0;
}